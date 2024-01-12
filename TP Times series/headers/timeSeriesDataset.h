#ifndef TIME_SERIES_DATASET
#define TIME_SERIES_DATASET

#include <vector>
#include <iostream>

#include "headers/timeSeriesGenerator.h"

using namespace std;

class TimeSeriesDataset{
    public:
        bool znormalize;
        bool isTrain;
        vector<vector<double>> data;
        vector<int> labels;
        int maxLength;
        int numberOfSamples;
    
        TimeSeriesDataset() : TimeSeriesDataset(true, true) {}

        TimeSeriesDataset(bool znormalize, bool isTrain) : znormalize(znormalize), isTrain(isTrain) {}

        void zNormalize(bool boolean);

        double calculateMean(const vector<double>& series);

        double calculateStdDev(const vector<double>& series, double mean);

        void znormalizeSeries(vector<double>& series, double mean, double stdDev);

        double euclidean_distance(const vector<double>& series1, const vector<double>& series2);

        double dtw_distance(const vector<double>& series1, const vector<double>& series2);

        void addTimeSeries(vector<double> &timeSeries, int length);

        void addTimeSeries(vector<double> &timeSeries);
};


#endif