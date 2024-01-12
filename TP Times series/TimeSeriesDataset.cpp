#include <iostream>
#include <vector>

#include "headers/timeSeriesDataset.h"

using namespace std;

TimeSeriesDataset::TimeSeriesDataset() : TimeSeriesDataset(true, true) {}

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain) : znormalize(znormalize), isTrain(isTrain) {}

void TimeSeriesDataset::zNormalize(bool boolean) {
    if (boolean){
        for (vector<double>& series : data) {
                double mean = calculateMean(series);
                double stdDev = calculateStdDev(series, mean);
                znormalizeSeries(series, mean, stdDev);
            }
    }
}

double TimeSeriesDataset::calculateMean(const vector<double>& series) {
    double sum = 0;
    for (double value : series) {
        sum += value;
    }
    return sum / series.size();
}

double TimeSeriesDataset::calculateStdDev(const vector<double>& series, double mean) {
    double sum = 0;
    for (double value : series) {
        sum += pow(value - mean, 2);
    }
    return sqrt(sum / series.size());
}

void TimeSeriesDataset::znormalizeSeries(vector<double>& series, double mean, double stdDev) {
    for (int i = 0; i < series.size(); i++) {
        series[i] = (series[i] - mean) / stdDev;
    }
}

double TimeSeriesDataset::euclidean_distance(const vector<double>& series1, const vector<double>& series2) {
    double sum = 0;
    for (int i = 0; i < series1.size(); i++) {
        sum += pow(series1[i] - series2[i], 2);
    }
    return sqrt(sum);
}

double TimeSeriesDataset::dtw_distance(const vector<double>& series1, const vector<double>& series2){
    int n = series1.size();
    int m = series2.size();
    vector<vector<double>> dtw(n, vector<double>(m, 0));
    dtw[0][0] = 0;
    for (int i = 1; i < n; i++){
        dtw[i][0] = 1000000000;
    }
    for (int i = 1; i < m; i++){
        dtw[0][i] = 1000000000;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            double cost = abs(series1[i] - series2[j]);
            dtw[i][j] = cost + min(dtw[i-1][j], min(dtw[i][j-1], dtw[i-1][j-1]));
        }
    }
    return sqrt(dtw[n-1][m-1]);
}

void TimeSeriesDataset::addTimeSeries(vector<double> &timeSeries, int length) {
    if (length > maxLength) {
        maxLength = length;
    }
    data.push_back(timeSeries);
    numberOfSamples++;
}

void TimeSeriesDataset::addTimeSeries(vector<double> &timeSeries) {
    addTimeSeries(timeSeries, timeSeries.size());
}
