
#include "bBuffer.h"



bBuffer::bBuffer(std::string buffer)
{
    addBuffer(buffer);
}

bBuffer::~bBuffer()
{
    clearBuffers();
}