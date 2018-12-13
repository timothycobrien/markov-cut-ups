//
// Created by Tim on 12/11/2018.
//

#include "Dictionary.h"
#include "Options.h"
#include <fstream>
#include <chrono>
#include <iostream>

std::mt19937 Dictionary::gen = Dictionary::engineHelper();

/**
 * Credit to: https://www.guyrutenberg.com/2014/05/03/c-mt19937-example/
 * and https://codereview.stackexchange.com/questions/109260/seed-stdmt19937-from-stdrandom-device
 * @return Random Engine
 */
std::mt19937 Dictionary::engineHelper() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 temp(seed);
    temp.discard(700000);
    return temp;
}


Dictionary::Dictionary(std::string auth):author(auth) {
    create();
}

std::string Dictionary::generateText(uint32_t length){
    std::string prefix = prefixInitializer(Options::instance()->prefixSize());
    std::string suffix;
    std::string output("");
    for (uint32_t count = 0; count < length; ++count){
        suffix = suffixSelect(prefix);
        if (suffix[0] == nonWord){
            output.append("\n\n"); //just two newlines to simulate new text thread
            prefix = prefixInitializer(Options::instance()->prefixSize());
        }
        else{
            output.append(suffix + " ");
            prefix = prefix.substr(prefix.find(' ') + 1) + ' ' + suffix;
        }
    }
    return output;
}

void Dictionary::create() {
    std::string path = "../texts/"+author;
    auto directory = std::filesystem::directory_iterator(path);
    for (auto const &file : directory){
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
    dictionary[prefix].emplace_back(1, nonWord);
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
        int lookup = range(gen);
        return search[lookup];
    }
}
