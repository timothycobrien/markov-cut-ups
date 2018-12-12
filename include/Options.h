//
// Created by Tim on 12/11/2018.
// This class is a singleton class to facilitate different options in text generation.
// Will deal with which authors to select to build dictionaries from.
// How dictionaries are actually built (i.e. prefix size).
// How often and what generated texts to splice together.
//

#include <cstdint>
#include <string>

#ifndef MARKOV_CUT_UPS_OPTIONS_H
#define MARKOV_CUT_UPS_OPTIONS_H

const char nonWord = '|';

class Options{

public:

     //Creates instance if not present
     //returns instance
     //default parameters of prefix size 2, and using all authors in texts directory
    static Options* instance(std::string = "all", uint8_t = 2,);


     //Default  destructor, preserves options through entire program execution
     ~Options() = default;

     //Returns prefix size
     uint8_t prefixSize();

     //Returns author list
     std::string authors();

private:
    //Private constructor for singleton
    Options(uint8_t, std::string);

    //Prefix size will be capped at 4? for now, otherwise should be weird
    //So will just make this variable 1 byte in memory
    uint8_t preSize;

    //List of authors, assumes each author represented by separate folder in ../texts
    std::string authorList;

    //Pointer to singleton
    static Options* inst;
};


#endif //MARKOV_CUT_UPS_OPTIONS_H
