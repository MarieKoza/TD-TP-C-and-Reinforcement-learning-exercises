#ifndef SIN_WAVE_GENERATOR
#define SIN_WAVE_GENERATOR

#include <vector>
#include <iostream>
#include <cmath>

#include "headers/timeSeriesGenerator.h"

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator {
    public:
        double amplitude;
        double frequence;
        double phase;
        SinWaveGenerator() : TimeSeriesGenerator() {}

        SinWaveGenerator(int seed) : TimeSeriesGenerator(seed) {}

        vector<double> generateTimeSeries(int length);

        double generateSinWave(double value);

};

#endif