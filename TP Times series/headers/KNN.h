#ifndef KNN_H
#define KNN_H

#include <vector>
#include <iostream>
#include <string>


using namespace std;

class KNN {
    public :
        int k;
        string similarity_mesure;

        KNN(int _k, const std::string& _similarityMeasure);

        double evaluate(const std::vector<int>& yTest, const std::vector<int>& yPred, vector<int>& ground_truth);

        int predict(const std::vector<int>& neighborsLabels);
};


#endif