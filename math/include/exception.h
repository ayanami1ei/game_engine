#ifndef EXCEPTION_H
#define EXCEPTION

#include <exception>
#include <string>

class MathException : public std::exception
{
private:
    std::string msg;

public:
    MathException(std::string &msg)
    {
        this->msg = msg;
    }
    MathException(char *msg, int len)
    {

        this->msg = std::string(msg, len);
    }
    const char *what() const throw()
    {
        return msg.c_str();
    }
};

#endif