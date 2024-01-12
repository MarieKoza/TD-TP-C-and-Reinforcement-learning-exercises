#ifndef STEP_GENERATOR
#define STEP_GENERATOR

#include <vector>
#include <iostream>

#include "headers/timeSeriesGenerator.h"

using namespace std;

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator() : TimeSeriesGenerator() {}

    StepGenerator(int seed) : TimeSeriesGenerator(seed) {}

    vector<double> generateTimeSeries(int length);

    double generateStep(double value);

};

#endif

