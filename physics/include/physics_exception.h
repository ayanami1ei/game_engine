#ifndef PHYSICSEXCEPTION_H
#define PHYSICSEXCEPTION_H

#include <exception>
#include<string>
#include<string.h>

class PhysicsException : public std::exception
{
    private:
    std::string msg;

public:
    PhysicsException(const char* msg);

    const char *what() const throw();
};

#endif