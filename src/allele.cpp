#include "allele.h"
#include <string> 
#include <iostream>

 // CONSTRUCTOR 
 
Allele::Allele()
{
	//randomly constructs an allele
}

Allele::Allele(std::string _allele)
{
	this->setAlleleString(_allele) ;	
}

Allele::Allele(alleleSeq _allele) 
{
	this->setAllele(_allele);
}

 // GETTER 
 
alleleSeq Allele::getAllele()
{
	return mAllele; 
}

std::string Allele::getAlleleString()
{
	std::string seq ;
	
	for (auto N : mAllele) 
	{
		seq += N ; 
	}	
	
	return seq ; 
}

 // PRINTER
 
void Allele::printAllele()
{
	std::cout << this->getAlleleString() << std::endl;
	
}

  // SETTER 
  
void Allele::setAllele(alleleSeq _allele) 
{	
	mAllele.clear();
	for( auto N : _allele)
	{
		if ( N != 'A' and N != 'C' and N != 'G' and N!= 'T') 	//checks if the alleleSeq given is made of nucleotides only 
		{
			throw std::string("ERROR: alleleSeq containing a letter that is not a nucleotide : nucleotides are only A C G T");
		} 
	}
	mAllele = _allele;
}

void Allele::setAlleleString(std::string _allele) 
{	
	mAllele.clear();
	
	for ( auto N : _allele) 
    { 
		if ( N =='A' or N =='C' or N=='G' or N=='T' )	//checks if the alleleSeq given is made of nucleotides only 
		{
			mAllele.push_back(N); 
		}
		else
		{
			throw std::string("ERROR: alleleSeq containing a letter that is not a nucleotide : nucleotides are only A C G T");
		}
	}
}

int Allele::size() 
{
	return mAllele.size();
}
