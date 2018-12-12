//
// Created by Tim on 12/12/2018.
//

#include "Dictionary.h"
#include "Options.h"
#include <cstring>
#include <string>

int checkInt(char* arg);
std::string concatArgs(int argc, char* argv[]);
std::unique_ptr<Options> parseArgs(int argc, char* argv[]);

//different cases based on number of arguments and types of arguments
int main(int argc, char* argv[]){
    std::unique_ptr<Options> options = parseArgs(argc, argv);

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

std::string concatArgs(int argc, char* argv[]){

}

std::unique_ptr<Options> parseArgs(int argc, char* argv[]){
    if (argc == 1){
        std::unique_ptr<Options> options(Options::instance());
    }
    else{
        int preNum = checkInt(argv[1]);
        if (preNum == 0){ //no prefix size parameter was given
            if (strncmp(argv[1], "all", 3) == 0){
                std::unique_ptr<Options> options(Options::instance());
            }
            else{
                std::string param = concatArgs(argc, argv);
                std::unique_ptr<Options> options(Options::instance(param));
            }
        }
        else{
            std::string param = concatArgs(argc, argv);
            std::unique_ptr<Options> options(Options::instance(param, preNum));
        }
    }
}

