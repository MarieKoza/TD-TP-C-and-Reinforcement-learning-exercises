#include "linear_search.h"
#include <vector>
#include <iostream>

LinearSearch::LinearSearch(): SearchingAlgorithm(){}

int LinearSearch::search(const vector<int>& v, int target){
    for (int i = 0; i < v.size(); i++){
        numberComparisons++; 
        if (v[i] == target){
            return i;
        }
    }
    return -1;
}

