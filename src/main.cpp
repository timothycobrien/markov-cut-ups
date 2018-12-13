//
// Created by Tim on 12/12/2018.
//

#include "Dictionary.h"
#include "Options.h"
#include <stdexcept>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <filesystem>
#include <iostream>
#include <fstream>

typedef std::vector<std::string> stringVec;

int checkInt(char* arg);
stringVec concatArgs(int argc, char* argv[]);
stringVec allAuthors();
std::unique_ptr<Options> parseArgs(int argc, char* argv[]);

//different cases based on number of arguments and types of arguments
int main(int argc, char* argv[]){
    std::unique_ptr<Options> options = parseArgs(argc, argv);
    std::vector<Dictionary> dictList;
    const stringVec authorList = options->authors();
    std::cout << "Creating dictionaries." << std::endl;
    for (const std::string auth : authorList){
        dictList.emplace_back(auth);
    }
    stringVec outputs;
    for (auto &dict : dictList){
        outputs.push_back(dict.generateText(options->outputSize()));
    }
    std::string path = "../output/output.txt";
    std::ofstream out(path);
    std::shuffle(outputs.begin(), outputs.end(),Dictionary::gen);
    std::cout << "Writing output." << std::endl;
    for (std::string const & output : outputs){
        out << output;
    }
    std::cout << "Done." << std::endl;
    return 0;
}

/**
 * Using code from
 * https://codereview.stackexchange.com
 * /questions/164365/checking-if-command-line-input-is-an-integer
 * Credit to Jerry Coffin
 */
int checkInt(char* arg){
    char *endChar;
    int input = strtol(arg, &endChar, 10);
    if (*endChar != '\0'){
        return 0;
    }
    else{
        return input;
    }
}

stringVec concatArgs(int argc, char* argv[]){
    stringVec temp;
    for (int i = 1; i < argc; ++i){
        temp.emplace_back(argv[i]);
    }
    return temp;
}

std::unique_ptr<Options> parseArgs(int argc, char* argv[]){
    if (argc == 1){
        throw std::invalid_argument("Need to provide at least one parameter");
    }
    else if (argc == 2){
        int outSize = checkInt(argv[1]);
        stringVec authList = allAuthors();
        std::unique_ptr<Options> options(Options::instance(outSize, authList));
        return options;

    }
    else{ //outSize and some other parameter
        int outSize = checkInt(argv[1]);
        int preNum = checkInt(argv[2]);
        if (preNum == 0){ //no prefix size parameter was given
            if (strncmp(argv[2], "all", 3) == 0){
                stringVec authList = allAuthors();
                std::unique_ptr<Options> options(Options::instance(outSize, authList));
                return options;
            }
            else{
                stringVec param = concatArgs(argc - 1, argv + 1);
                std::unique_ptr<Options> options(Options::instance(outSize, param));
                return options;
            }
        }
        else{ //prefix size parameter was given
            if (argc == 3){
                stringVec authList = allAuthors();
                std::unique_ptr<Options> options(Options::instance(outSize, authList, preNum));
                return options;
            }
            else {
                stringVec param = concatArgs((argc - 2), (argv + 2));
                std::unique_ptr<Options> options(Options::instance(outSize, param, preNum));
                return options;
            }
        }
    }
}

stringVec allAuthors(){
    stringVec authList;
    std::string path = "../texts";
    auto directory = std::filesystem::directory_iterator(path);
    for (const auto & author : directory){
        authList.push_back(author.path().filename().generic_string());
    }
    return authList;
}

