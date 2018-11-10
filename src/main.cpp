/*  Last edited 10/11/18
 *  by Camil
 *  added the parse function and error handling
 *  parsing args and constructing the simulation.
 */
#include <iostream>
#include <tclap/CmdLine.h>
#include "simulation.h"
#include "fastareader.h"

Simulation* parse(int argc, char **argv, TCLAP::CmdLine* cmd);


int main(int argc, char **argv) {
    TCLAP::CmdLine cmd("Genetic Drift Simulation");
    Simulation *sim =0;

    int nerr = 0;
    try {
        sim = parse(argc, argv, &cmd);
        

        // SUITE DU MAIN



    } catch(std::runtime_error &e) {
        if (strcmp(e.what(), "NGEN") == 0) {
            std::cerr << "Number of generation must be positive\n";
            nerr = 2;
        } else if (strcmp(e.what(), "NREP") == 0) {
            std::cerr << "Number of repetition must be positive\n";
            nerr = 3;
        } else if (strcmp(e.what(), "FREQ") == 0) {
            std::cerr << "All frequencies must be positive\n";
            nerr = 4;
        } else if (strcmp(e.what(), "NALL") == 0) {
            std::cerr << "Number of alleles must be positive\n";
            nerr = 5;
        } else if (strcmp(e.what(), "MARK") == 0) {
            std::cerr << "Markers must be positive integers and within the length of the sequence\n";
            nerr = 6;
        }
    } catch(TCLAP::ArgException &e) {
        std::cerr << "Error: " + e.error() + " " + e.argId();
        nerr = 1;
    }

    return nerr;
}

Simulation* parse(int argc, char **argv, TCLAP::CmdLine* cmd){
    TCLAP::ValueArg< int > nGeneration("T", "generations", 
        "Number of generation for each population", true, 10, "int");
    cmd->add(nGeneration);
    TCLAP::ValueArg< int > nRepetition("R", "repetition", 
        "Number of repetition", true, 2, "int");
    cmd->add(nRepetition);
    TCLAP::MultiArg< double > frequencies("f", "frequencies", 
        "Frequencies of the different alleles", false, {0.8}, "double");
    cmd->add(frequencies);
    TCLAP::ValueArg< int > nAlleles("A", "allele", 
        "Number of different alleles in a single population", false, 2, "int");
    cmd->add(nAlleles);
    TCLAP::ValueArg< string > fastafile("F", "fasta", 
        "Name of the fasta file", false, "NULL", "int");
    cmd->add(fastafile);
    TCLAP::MultiArg< size_t > markers("m", "markers", 
        "Positions of the marked nucleotides to form alleles", false);
    cmd->add(markers);
    cmd->parse(argc,argv);

    if(fastafile.getValue() != "NULL" and (markers.getValue()).empty){
        FastaReader fasta(fastafile.getValue(), markers.getValue());
        Simulation* sim = new Simulation(fasta.getMap(),nGeneration.getValue(),nRepetition.getValue());
        return sim;
    } else{
        Simulation* sim = new Simulation(nAlleles.getValue(), frequencies.getValue(),
                                        nGeneration.getValue(), nRepetition.getValue());
        return sim;
    }
}