#include "jump_search.h"
#include <vector>
#include <iostream>

JumpSearch::JumpSearch(): SearchingAlgorithm(){}

int JumpSearch::search(const vector<int>& v, int target){
    int jump = sqrt(v.size());
    int left = 0;
    int right = jump;
    while (right < v.size() && v[right] <= target){
        numberComparisons++;
        left = right;
        right += jump;
        if (right > v.size() - 1){
            right = v.size();
        }
    }
    for (int i = left; i < right; i++){
        numberComparisons++;
        if (v[i] == target){
            return i;
        }
    }
    return -1;
}
