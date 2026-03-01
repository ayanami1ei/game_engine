#include"physics_exception.h"

PhysicsException::PhysicsException(const char *msg){
    this->msg=std::string(msg,strlen(msg));
}

const char *PhysicsException::what() const throw(){
    return msg.c_str();
}