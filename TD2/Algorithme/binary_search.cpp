#include "binary_search.h"
#include <vector>
#include <iostream>


BinarySearch::BinarySearch(): SearchingAlgorithm(){}

int BinarySearch::search(const vector<int>& v, int target){
    int left = 0;
    int right = v.size() - 1;
    while (left <= right){
        int middle = (left + right) / 2;
        numberComparisons++;
        if (v[middle] == target){
            return middle;
        }
        else if (v[middle] < target){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    return -1;
}