//
// Created by Tim on 12/11/2018.
//

#include "Dictionary.h"
#include "Options.h"
#include <fstream>
#include <iostream>


Dictionary::Dictionary(std::string auth):author(auth) {

}

std::string Dictionary::generateText(uint32_t) {

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
    uint32_t adjustSize = Options::instance()->prefixSize()*2 - 1;
    std::string prefix(adjustSize, ' ');
    for (uint32_t i = 0; i < adjustSize; i += 2){
        prefix[i] = '$'; //preSize nonwords are used
    }
    std::string suffix;
    while (file >> suffix){
        dictionary[prefix].push_back(suffix);
        prefix = prefix.substr(prefix.find(' ') + 1) + ' ' + suffix;
        //looks for space, reappends with space
    }
    //need to fix last prefix with nonword
    dictionary[prefix].push_back("$");
}

