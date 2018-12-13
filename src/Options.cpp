//
// Created by Tim on 12/11/2018.
//
#include "Options.h"
#include <filesystem>
#include <sstream>
#include <iostream>


Options* Options::inst = nullptr;

Options* Options::instance() {
    if (inst == nullptr){
        throw std::invalid_argument("Need parameters to create singleton.");
    }
    else{
        return inst;
    }
}

Options* Options::instance(uint32_t outSize, std::vector<std::string>& auth, uint8_t pre) {
    if (inst == nullptr){
        inst = new Options(outSize, auth, pre);
    }
    return inst;
}

uint32_t Options::outputSize() const {
    return outSize;
}

uint8_t Options::prefixSize() const{
    return preSize;
}

const std::vector<std::string>& Options::authors() const{
    return authorList;
}

Options::Options(uint32_t out, std::vector<std::string>& auth, uint8_t pre):outSize(out), authorList(auth), preSize(pre) {
}