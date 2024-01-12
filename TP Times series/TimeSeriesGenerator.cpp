#include <iostream>
#include <vector>

#include "headers/timeSeriesGenerator.h"

using namespace std;


TimeSeriesGenerator::TimeSeriesGenerator() : TimeSeriesGenerator(0) {}

TimeSeriesGenerator::TimeSeriesGenerator(int newSeed) : seed(newSeed) {}

void TimeSeriesGenerator::printTimeSeries(const vector<double> &timeSeries) {
    for (int i = 0; i < timeSeries.size(); i++) {
        cout << timeSeries[i] << " ";
    }
    cout << endl;
}

