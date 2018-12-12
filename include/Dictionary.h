//
// Created by Tim on 12/11/2018.
// This class will create a dictionary for a particular authors texts
// Uses unordered_map to map prefixes to suffixes in a markov chain
// Only one suffix, so will just map a string to a vector containing other strings
//

#include <unordered_map>
#include <vector>
#include <string>
#include <filesystem>

#ifndef MARKOV_CUT_UPS_DICTIONARY_H
#define MARKOV_CUT_UPS_DICTIONARY_H

class Dictionary{

public:
    //takes string of author's works to create dictionary for
    Dictionary(std::string auth);

    //generates text of a certain length
    std::string generateText(uint32_t);

private:
    std::unordered_map<std::string, std::vector<std::string>> dictionary;
    //author to generate dictionary from
    std::string author;
    //creates a dictionary for entire author's works
    void create();
    //adds a specific text to the dictionary, intended to be used in larger loop
    void addText(const std::filesystem::path &filename);
    //creates a nonword prefix string (nonword is the '|' character in this case)
    //passed size to encapsulate method logic slightly better
    std::string prefixInitializer(uint32_t size);
    //randomly selects a particular entry from the vector
    //optimized if there is only one entry in the vector
    std::string suffixSelect(const std::string &prefix);


};

#endif //MARKOV_CUT_UPS_DICTIONARY_H
