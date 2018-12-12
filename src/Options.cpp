//
// Created by Tim on 12/11/2018.
//
#include "Options.h"

Options* Options::inst = nullptr;

Options* Options::instance(uint8_t pre, std::string auth) {
    if (inst == nullptr){
        inst = new Options(pre, auth);
    }
    return inst;
}

uint8_t Options::prefixSize() {
    return preSize;
}

std::string Options::authors() {
    return authorList;
}

Options::Options(uint8_t pre, std::string auth):preSize(pre), authorList(auth) {
}