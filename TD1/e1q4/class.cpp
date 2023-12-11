#include "class.h"
#include <iostream>

using namespace std;

my_class::my_class(){
    s="sortie par défaut";
}

my_class::my_class(string string):s(string) //initialise s avec la valeur
{}

void my_class::print_my_element(){
    cout << s << endl;
}