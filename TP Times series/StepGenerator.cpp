#include <iostream>
#include <vector>

#include "headers/stepGenerator.h"

using namespace std;


StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

    //fonction qui choisit aléatoirement si on ajoute la valeur actuelle (0) ou si on ajoute aléatoirement une valeur comprise entre 0 et 100
vector<double> StepGenerator::generateTimeSeries(int length){
    vector<double> timeSeries;
    double actualValue = 0;
    for (int i = 0; i < length; i++) {
        timeSeries.push_back(generateStep(actualValue));
    }
}

double StepGenerator::generateStep(double value) {
    double random = rand()%2; //random = 0 ou 1
    if (random == 0) {
        return value;
    } else {
        return rand()%101;
    }
}