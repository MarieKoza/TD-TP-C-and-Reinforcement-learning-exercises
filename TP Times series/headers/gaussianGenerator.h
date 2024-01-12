#ifndef GAUSSIAN_GENERATOR
#define GAUSSIAN_GENERATOR

#include <vector>

#include "headers/timeSeriesGenerator.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator {
public:
    double moyen;
    double ecart_type;
    GaussianGenerator() : TimeSeriesGenerator() {}

    GaussianGenerator(int seed) : TimeSeriesGenerator(seed) {}

    vector<double> generateTimeSeries(int length);

    double generateGaussian();

    double generateUniform();
};

#endif