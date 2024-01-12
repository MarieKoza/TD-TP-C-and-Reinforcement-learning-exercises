#include <iostream>
#include <vector>

#include "headers/knn.h"

using namespace std;

KNN::KNN(int _k, const string& _similarityMeasure) : k(_k), similarity_mesure(_similarityMeasure) {}

double KNN::evaluate(const vector<int>& yTest, const vector<int>& yPred, vector<int>& ground_truth) {
    int correct = 0;
    for (int i = 0; i < yTest.size(); i++) {
        if (yTest[i] == yPred[i]) {
            correct++;
        }
    }
    return (double) correct / yTest.size();
}

