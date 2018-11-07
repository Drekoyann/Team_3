#include <iostream>
#include <algorithm> // std::sort
#include "fastareader.h"

using namespace std;

Fastareader::Fastareader(string filename, vector<size_t> markers)
{
	if(markers.empty())
		throw string("ERROR: empty set of markers!\n");
	sort(markers.begin(), markers.end());
	mMarkers = markers;
	file.open(filename);
	if (file.is_open())
	{
		cout << "File named " << filename << " was successfully opened \n\n";
		Initialize();
	}
	else
	{
		cerr << "File named " << filename << " couldn't be opened (check the spelling/file hierarchy) \n";
		throw string("ERROR: Invalid file name\n");
	}
}

Fastareader::~Fastareader() {} //default destructor closes ifstream.

void Fastareader::Initialize()
{
	if (file.is_open()) 
	{
		string line, sequence;
		vector<string> Codons;
		vector<unsigned int> Numbers;
		unsigned int nbLine(0);
		
        while (getline(file, line)) 
        {			
			++nbLine;
            if (line[0] != '>')
			{
				sequence += line;
			}
			else if ((line[0] == '>')and(nbLine > 1))   //first line always contains a header -> algorithmic problem if we omit that detail
			{
				mapping(mMarkers, sequence, Codons, Numbers);
			}
		}
			
		mapping(mMarkers, sequence, Codons, Numbers);  //takes care of the last sequence, that would otherwise be left out
		
		for(size_t i(0); i < Codons.size(); ++i)
			mMap.insert(make_pair(Allele(Codons[i]), Numbers[i]));
	}
	else
		throw string("Programm did not go through. \n");
}

void Fastareader::mapping(std::vector<size_t> mark, string& seq, vector<string>& codons, vector<unsigned int>& numbers)
{
	string codon;
	for (auto pos : mark)
	{
		if (seq.size() >= pos)
		{
			codon += seq[pos - 1];
		}
		else
		{
			cerr << "position marker " << pos << " is too large for some of our DNA sequences !\n";
			throw string("ERROR: Invalid marker ID (try a smaller one)\n");
		}
	}
					
	seq = "";  //need to empty the used sequence
				
	bool identical(false);
	for(size_t i(0); i < codons.size(); ++i)
	{
		if(codons[i] == codon)
		{
			++numbers[i];
			identical = true;
			break;
		}
	}
					
	if(!identical) //else if the codon doesn't exist yet
	{
		codons.push_back(codon);
		numbers.push_back(1);
	}
}

map<Allele, unsigned int> Fastareader::getMap()
{
	return mMap;
}
