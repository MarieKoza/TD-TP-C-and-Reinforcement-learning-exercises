#include <vector>
#include <iostream>

#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H
#include "search.h"
using namespace std;

class JumpSearch : public SearchingAlgorithm{

    public:
        JumpSearch();
        int search(const vector<int>&, int);

}; 

#endif