/*!
\title bBuffer
\brief Buffers for all kinds of data


*/
#ifndef BBUFFER_H
#define BBUFFER_H


class bBuffer {

public:
    bBuffer(std::string buffer);
    ~bBuffer();

    void addBuffer(std::string buffer);
    void removeBuffer(int id);
    void clearBuffers();

    std::string getBuffer(int id);





private:

    std::map<int, std::string> buffers;

};







#endif