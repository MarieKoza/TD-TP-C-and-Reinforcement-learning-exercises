#ifndef TIMES_SERIES_GENERATOR
#define TIMES_SERIES_GENERATOR

#include <vector>

using namespace std;

class TimeSeriesGenerator {
  public:
    int seed;
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual vector<double> generateTimeSeries(int length) = 0;
    void printTimeSeries(const vector<double> &timeSeries);
};


#endif
