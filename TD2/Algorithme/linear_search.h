#include <vector>
#include <iostream>

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H
#include "search.h"

class LinearSearch : public SearchingAlgorithm{

    public:
        LinearSearch();
        int search(const vector<int>&, int);

};

#endif