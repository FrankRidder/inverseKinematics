#include <vector>
#include <cstdio>
#include "calculations.h"

using namespace std;

double calculations::dist(vector<double>& from, vector<double>& to) {
    double xd = from.begin() - to.begin();
    double yd = from.end() - to.end();
    return sqrt(xd * xd + yd * yd);
}

vector<double> calculations::normalize(vector<double> target) {
    double normalization = 1.0 / sqrt(target[X] * target[X] + target[Y] * target[Y] + target[Z] * target[Z]);

    target[X] *= normalization;
    target[Y] *= normalization;
    target[Z] *= normalization;

    return target;
}

double calculations::dotProduct(vector<double> target1,vector<double> target2) {
    return target1[X] * target2[X] + target1[Y] * target2[Y] + target1[Z] * target2[Z];
}

double calculations::angle(const vector<double>& target1, const vector<double>& target2) {

    double dot = dotProduct(target1,target2);
    double lenSq1 = length(target1);
    double lenSq2 = length(target2);
    double toReturn = dot/sqrt(lenSq1 * lenSq2);

    printf("to return %f \n", toReturn);

    return acos(toReturn);
}

double calculations::length(vector<double> target) {
    return sqrt(target[X]) + sqrt(target[Y]) + sqrt(target[Z]);
}

vector<double> calculations::crossProduct(vector<double> target1, vector<double> target2){
    vector<double> toReturn = {0,0,0};

    toReturn[X] = (target1[Y]*target2[Z]) - (target1[Z]*target2[Y]);

    toReturn[Y]= ((target1[X]*target2[Z]) - (target1[Z]*target2[X]));

    toReturn[Z] = (target1[X]*target2[Y]) - (target1[Y]*target2[X]);

    return toReturn;
}
