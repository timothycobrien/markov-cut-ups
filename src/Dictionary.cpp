//
// Created by Tim on 12/11/2018.
//

#include "Dictionary.h"
#include "Options.h"
#include <fstream>
#include <iostream>

std::mt19937 Dictionary::gen = Dictionary::engineHelper();

std::mt19937 Dictionary::engineHelper() {
    std::random_device rd;
    std::mt19937 temp(rd);
    temp.discard(700000);
    return temp;
}


Dictionary::Dictionary(std::string auth):author(auth) {

}

std::string Dictionary::generateText(uint32_t length) {
    std::string prefix = prefixInitializer(Options::instance()->prefixSize());
    std::string suffix;
    std::string output("");
    output.reserve(length);
    for (uint32_t count = 0; count < length; ++count){
        suffix = suffixSelect(prefix);
        if (suffix[0] == nonWord){

        }
    }
    return output;
}

void Dictionary::create() {
    std::string path = "../texts/"+author;
    auto directory = std::filesystem::path(path);
    for (auto const &file : directory){
        std::cout << file << std::endl;
        addText(file);
    }
}

void Dictionary::addText(const std::filesystem::path &filename) {
    std::ifstream file(filename);
    std::string prefix = prefixInitializer(Options::instance()->prefixSize());
    std::string suffix;
    while (file >> suffix){
        dictionary[prefix].push_back(suffix);
        prefix = prefix.substr(prefix.find(' ') + 1) + ' ' + suffix;
        //looks for space, reappends with space
    }
    //need to fix last prefix with nonword
    dictionary[prefix].emplace_back(nonWord);
}

std::string Dictionary::prefixInitializer(uint32_t size){
    uint32_t adjustSize = size*2 - 1;
    std::string prefix(adjustSize, ' ');
    for (uint32_t i = 0; i < adjustSize; i += 2){
        prefix[i] = nonWord; //preSize nonwords are used
    }
    return prefix;
}

std::string Dictionary::suffixSelect(const std::string &prefix) {
    auto search = dictionary.at(prefix); //already throws if nonexistent
    if (search.size() == 1){ //runtime optimization
        return search[0];
    }
    else{
        std::uniform_int_distribution<> range(0, search.size() - 1);
        return search[range(gen)];
    }
}
