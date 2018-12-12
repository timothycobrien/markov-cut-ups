//
// Created by Tim on 12/11/2018.
//

#include "Dictionary.h"
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
    std::string prefix = "$ $"; //two nonwords are used
    std::string suffix;
    while (file >> suffix){

    }

}

