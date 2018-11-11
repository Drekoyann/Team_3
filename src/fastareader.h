#ifndef _FASTAREADER_H_
#define _FASTAREADER_H_

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "Allele.h"

/*! 
  This is a fastareader class : responsible for opening a file, reading it and creating a map with key type Allele and mapped type unsigned int (number of said Allele).
 */ 

class Fastareader { 
	
 public: 
 /*! 
  @name Constructor
  Directly creates the map via the private method Initialize().
  @param[in] the name of the fasta file (a string) and a vector <size_t> corresponding to the marker positions
 */ 
    Fastareader(std::string filename, std::vector<size_t> markers);
    ~Fastareader();
 /*! 
  @name Getter
  Allows access to the map created in the constructor.
 */
    std::map<Allele, unsigned int> getMap();
    
 private:
  /*! 
  Private method used in the constructor to initialize all the class members needed.
 */
	void Initialize();
  /*! 
  Private method used in Initialize() to create the map corresponding to the input data.
 */
	void mapping(std::vector<size_t>, std::string&, std::vector<std::string>&, std::vector<unsigned int>&); 
	
	std::vector<size_t> mMarkers;
	std::ifstream file;
	std::map<Allele, unsigned int> mMap;
};

#endif
