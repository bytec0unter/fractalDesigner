
#ifndef BPARSER_H
#define BPARSER_H

#include "bBuffer.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>




#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


#define TOKEN_BRACKETS_OPEN 0x01
#define TOKEN_BEACKETS_CLOSE 0x02
#define TOKEN_STRINGq 0x03
#define TOKEN_NUMBER 0x04



struct Token {
    unsigned int token_type;
    unsigned chat value token_value;
    unsigned int level;
};


class bTokenizer {



public:
    bTokenizer(std::string filename);
    ~bTokenizer();

    void tokenize(std::string string);
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
        void generateToken(std::string string);
    


    /** List with a all supported functions */
    List<Token> tokens;

};






#endif // BPARSER_H