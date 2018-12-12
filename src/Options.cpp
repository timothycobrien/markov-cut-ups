//
// Created by Tim on 12/11/2018.
//
#include "Options.h"
#include <filesystem>
#include <sstream>
#include <iostream>


Options* Options::inst = nullptr;

Options* Options::instance(std::vector<std::string>& auth, uint8_t pre) {
    if (inst == nullptr){
        inst = new Options(auth, pre);
    }
    return inst;
}

uint8_t Options::prefixSize() const{
    return preSize;
}

const std::vector<std::string>& Options::authors() const{
    return authorList;
}

Options::Options(std::vector<std::string>& auth, uint8_t pre): authorList(auth), preSize(pre) {
}