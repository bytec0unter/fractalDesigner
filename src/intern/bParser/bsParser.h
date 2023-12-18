
#ifndef BPARSER_H
#define BPARSER_H

#include "bBuffer.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>



/*!
\title bVariableType
\brief Variable type
\detailed This enum is used to store the type of a variable
*/
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


/*!
\title bTokenizer
\brief Tokenizer class
\detailed This class is used to tokenize a string, it is used by the parser
*/
enum bTokenType {
    bTokenNumber,
    bTokenOperator,
    bTokenFunction,
    bTokenBracket,
    bTokenVariable,
    bTokenUnknown
};

typedef bsTokenOpenBracket = "(";
typedef bsTokenCloseBracket = ")";
typedef bsTokenPlus = "+";
typedef bsTokenMinus = "-";
typedef bsTokenMultiply = "*";
typedef bsTokenDivide = "/";
typedef bsTokenModulo = "%";
typedef bsTokenPower = "^";
typedef bsTokenAnd = "&";
typedef bsTokenOr = "|";
typedef bsTokenNot = "~";
typedef bsTokenNot = "!";
typedef bsTokenEqual = "=";
typedef bsTokenLess = "<";
typedef bsTokenGreater = ">";
typedef bsTokenQuestion = "?";

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
public:
    pParser(std::string filename);
    ~pParser();

private:

};


class bCalculator {
public:
    
    bCalculator(std::string filename);
    ~bCalculator();

    void calculate(std::string filename);


private:
    bTokenizer *tokenizer;
    bParser *parser;

    bVariable *variables;
    bBuffer *buffer;
    bFunction *fu      
};

#endif // BPARSER_H