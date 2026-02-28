#ifndef EXCEPTION_H
#define EXCEPTION

#include <exception>
#include <string>

class MathException : public std::exception
{
private:
    std::string msg;

public:
    MathException(std::string &msg);
    MathException(char *msg, int len);
    const char *what() const throw();
};

#endif