#ifndef _ALLELE_H_
#define _ALLELE_H_

#include <vector>

/*!
 * This is an allele class that represents the set of nucleotide markers composing an allele.
 * 
 * An allele is a vector of char.
 * A nucleotide is a type enum of char: {A,C,G,T}.
 * A vector of nucleotides is an alleleSeq (typedef).
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
 * There are three different constructors:
 * 		- one that takes nothing in argument; creates a random nucleotide sequence 
 * 		- one that takes a string in argument; calls \ref setAlleleString() 
 * 		- one that takes a vector<char> in argument (a sequence of nucleotides); calls \ref setAllele() 
 */

	Allele () ;
	Allele(std::string _allele) ;
	Allele(alleleSeq _allele) ;
		
/*! 
 * @name Getter
 * There are two getters: one that returns a vector of nucleotides and one that returns a string. 
 * @param[out] the alleleSeq of nucleotides of the allele (vector of nucleotides or string) 
 */
	alleleSeq getAllele() ;
	std::string getAlleleString() ; 
	
/*!
 * Method that prints the allele alleleSeq.  
 */
	void printAllele() ;
	
/*! 
 * @name Setter
 * There are two setters: one with a vector as input and one with a string as input. 
 * @param[in] a vector of nucleotides or a string 
 */ 
	void setAllele(alleleSeq _allele) ;
	void setAlleleString(std::string _allele) ; 
	
/*!
 * @param[out] the size of the allele, i.e. the number of nucleotides it is composed of 
 */ 
	int size() ;
	
private :
	
	alleleSeq mAllele ;
};

#endif






