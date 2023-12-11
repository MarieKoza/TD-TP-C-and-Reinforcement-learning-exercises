#ifndef MY_CLASS_H
#define MY_CLASS_H
#include <iostream>

class my_class{
    public : 
        my_class();
        my_class(std::string s);
        void print_my_element();
    private :
        std::string s;
};



#endif