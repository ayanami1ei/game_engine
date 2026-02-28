#include "exception.h"

MathException::MathException(std::string &msg)
{
    this->msg = msg;
}
MathException::MathException(char *msg, int len)
{

    this->msg = std::string(msg, len);
}
const char *MathException::what() const throw()
{
    return msg.c_str();
}