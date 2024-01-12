#include <iostream>
#include <vector>

#include "headers/gaussianGenerator.h"

using namespace std;


GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator() {}

GaussianGenerator::GaussianGenerator(int seed) : TimeSeriesGenerator(seed) {}

vector<double> GaussianGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries;
    for (int i = 0; i < length; i++) {
        timeSeries.push_back(generateGaussian());
    }
    return timeSeries;
}

double GaussianGenerator:: generateGaussian() {
    double u1 = generateUniform();
    double u2 = generateUniform();
    return sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
}

double GaussianGenerator:: generateUniform() {
    srand(this->seed);
    return (double) rand() / (double) RAND_MAX;
}
