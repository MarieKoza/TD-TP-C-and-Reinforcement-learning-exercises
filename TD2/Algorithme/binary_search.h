#include <vector>
#include <iostream>

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include "search.h"

using namespace std;

class BinarySearch : public SearchingAlgorithm{

    public:
        BinarySearch();
        int search(const vector<int>&, int);

};

#endif
