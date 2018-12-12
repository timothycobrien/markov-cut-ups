//
// Created by Tim on 12/11/2018.
//
#include "Options.h"
#include <filesystem>
#include <sstream>
#include <iostream>


Options* Options::inst = nullptr;

Options* Options::instance(std::string auth, uint8_t pre) {
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
    if (auth == "all"){
        std::string path = "../texts";
        auto directory = std::filesystem::directory_iterator(path);
        std::ostringstream out;
        for (const auto &name : directory){
            out << name.path() << " ";
        }
        std::cout << out.str() << std::endl;
        authorList = out.str();
    }
}