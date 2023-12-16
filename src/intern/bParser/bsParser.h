
#ifndef BPARSER_H
#define BPARSER_H


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

struct Token {
    std::string type;
    std::string value;
    int line;
    int column;
};


class pParser{

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