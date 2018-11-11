#ifndef _ALLELE_H_
#define _ALLELE_H_

#include <vector>

/*!
 * An allele is a vector of char 
 * A nucleotide is a type enum of char: {A,C,G,T}
 * A vector of nuleotide is a alleleSeq (typedef)
 */ 
 


/*enum nucleotide { 
	A=0, 
	C, 
	G, 
	T,
	nucleotideEnd
} ;
*/

typedef std::vector<char> alleleSeq ;


class Allele {
	
public:

/*! @name Constructor
 * three  different constructeur:
 * 		- one that take nothing in argument -> create a random nucleotide sequence 
 * 		- one that take a string in argument -> call \ref setAlleleString() 
 * 		- one that take a vector<char> in argument (sequence of nucleotide) -> call \ref setAllele() 
 */

	Allele () ;
	Allele(std::string _allele) ;
	Allele(alleleSeq _allele) ;
	
	
	
/*! 
 * @name Getter
 * two getter: one that return the vector of nucleotide, one that return a string 
 * @param[out] the alleleSeq of nucleotide of the allele (vector of nucleotide or string) 
 */
	alleleSeq getAllele() ;
	std::string getAlleleString() ; 
	
/*!
 * print the allele alleleSeq  
 */
	void printAllele() ;
	
/*! 
 * @name Setter
 * two setter: one with a vector as input and one with a string as input 
 * @param[in] vector of nucleotide or string 
 */ 
	void setAllele(alleleSeq _allele) ;
	void setAlleleString(std::string _allele) ; 
	
/*!
 * @param[out] the size of the allele, ie the number of nucleotide it is composed of 
 */ 
	int size() ;
	
	
private :
	
	alleleSeq mAllele ;
	 
	
	
};


#endif






