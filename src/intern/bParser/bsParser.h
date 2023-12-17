
#ifndef BPARSER_H
#define BPARSER_H

#include "bBuffer.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


enum bVariableType {
    bVariableString,
    bVariableDouble,
    bVariableUnknown
};

/*!
\title bVariable
\brief Variable class
\detailed This class is used to store variables, variables can be of 
*/
class bVariable {
public:
    bVariable(std::string name, std::string value);
    ~bVariable();

public:
    bVariableType getType() const;
    std::string getName() const;
    std::string getValue() const;k

private:
    bVariableType type;
    std::string name;
    std::string value;
};

enum bTokenType {
    bTokenNumber,
    bTokenOperator,
    bTokenFunction,
    bTokenBracket,
    bTokenVariable,
    bTokenUnknown
};


List<std::string> functions = {"cos", "sin", "log", "mod"}
List<std::string> brackets = {"(",")"};
List<std::string> operators = {"+","-","*","/","%","^","&","|","~","!","=","<",">","?"};


struct Token {
    unsigned int type;
    unsigned char value;
    unsigned int level;
};


class bTokenizer {
public:
    bTokenizer(std::string filename);
    ~bTokenizer();

    void parseToken(std::string string);
    void printTokens();

    /** List with a all supported functions */
    std::vector<Token> tokens;                                      
}

class pParser {
private:
    pParsr(std::string filename);
    ~pParser();

public:
    
        static pParser* instance();



#endif // BPARSER_H