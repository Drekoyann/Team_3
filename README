# Population Genetics

## A. Program presentation

The aim of this program is to simulate how the genetics of a given population evolve with time.
It is based on the Wright-Fisher model for population genetics and models how allele frequencies evolve throughout generations.
The model doesn't take into account selective pressure, mutations or allele recombination and assumes that the individuals
of the population mate randomly. Alleles are defined by a few marker sites on the gene.

## B. How to compile the program

In the terminal, go into the "build" repository of the program and write the command "cmake .." and then "make" to compile the program using CMake.
Note: You will have to install CMake first.


## C. How to use the program

To execute the program, write "./ProjectTeam3" followed by:

Either, to use the first version of the program:

    "-T" or "--generations" + the number of generations for the population [of argument type int]
    "-R" or "--repetition" + the number of repetitions of the simulation [int]
    "-f" or "--frequencies" + the frequencies of the different alleles [several double]
    "-A" or "--allele" + the number of different alleles in a single population [int]

or, to use the second version:

    "-F" or "--fasta" + the name of the fasta file on which your gene sequences are located [string]
    "-m" or "--markers" + the positions on the gene of the marked nucleotides that form alleles [multiple size_t]

Notes:

- If you want to use the first version, you don't necessarily have to enter (all) the arguments, it is possible to do a by-default simulation.
- To use the program, you have to install the TCLAP library first.

Finally, to execute the tests, write "./testProject" and the corresponding arguments.

The output should be read this way:

- the numbers of the first column represent the generation numbers (0 being the initial population and 1, their offspring)
- the numbers of the other columns represent the frequency evolution of an allele according to the generation number (each allele is represented on one column and, at generation 0, you can see its initial frequency)
- frequencies of different alleles of the same simulation are separated by the character "|" and different simulations are separated by a space
- if the second version of the program was ran, you can find the corresponding allele genotype on the bottom of each frequencies column
