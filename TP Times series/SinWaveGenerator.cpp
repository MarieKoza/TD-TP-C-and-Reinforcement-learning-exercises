#include <iostream>
#include <vector>

#include "headers/sinWaveGenerator.h"

using namespace std;

vector<double> SinWaveGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries;
    for (int i = 0; i < length; i++) {
        timeSeries.push_back(generateSinWave(i));
    }
    return timeSeries;
}

double SinWaveGenerator::generateSinWave(double value) {
    return amplitude * sin(frequence * value + phase);
}

