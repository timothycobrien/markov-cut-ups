//
// Created by Tim on 12/11/2018.
// This class is a singleton class to facilitate different options in text generation.
// Will deal with which authors to select to build dictionaries from.
// How dictionaries are actually built (i.e. prefix size).
// How often and what generated texts to splice together.
//

#include <cstdint>
#include <string>
#include <vector>

#ifndef MARKOV_CUT_UPS_OPTIONS_H
#define MARKOV_CUT_UPS_OPTIONS_H

const char nonWord = '|';

class Options{

public:

    //Can't create instance, used only for accessing
    static Options* instance();

     //Creates instance if not present
     //returns instance
     //default parameters of prefix size 2, and using all authors in texts directory
     //Output size parameter needs to be provided
    static Options* instance(uint32_t, std::vector<std::string>&, uint8_t = 2);


     //Default  destructor, preserves options through entire program execution
     ~Options() = default;

     //Returns number of words in each output file
     uint32_t outputSize() const;

     //Returns prefix size
     uint8_t prefixSize() const;

     //Returns author list
     const std::vector<std::string>& authors() const;

private:
    //Private constructor for singleton
    Options(uint32_t, std::vector<std::string>&, uint8_t);

    //number of words in each output file
    uint32_t outSize;

    //List of authors, assumes each author represented by separate folder in ../texts
    std::vector<std::string> authorList;

    //Prefix size will be capped at 4? for now, otherwise should be weird
    //So will just make this variable 1 byte in memory
    uint8_t preSize;


    //Pointer to singleton
    static Options* inst;
};


#endif //MARKOV_CUT_UPS_OPTIONS_H
