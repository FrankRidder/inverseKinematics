#include <vector>
#include "calculations.h"

using namespace std;

double calculations::dist(vector<double> from, vector<double> to) {
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

double calculations::dotProduct(vector<double> target1, vector<double> target2) {
    return (target1[X] * target2[X] + target1[Y] * target2[Y] + target1[Z] * target2[Z]);
}

double calculations::angle(const vector<double>& target1, const vector<double>& target2) {

    double product = dotProduct(target1, target2);
    double lenSqt = (length(target1) * length(target2));
    double toReturn;
    if (lenSqt == 0.0f) {
        toReturn = 0.0f;
    } else {
        toReturn = product / lenSqt;
    }
    if (toReturn < -1.0f) toReturn = -1.0f;
    if (toReturn > 1.0f) toReturn = 1.0f;
    return acos(toReturn);
}

double calculations::length(vector<double> target) {
    double leng = (target[X]*target[X] + target[Y]*target[Y]);
    if (leng < 0.0f) { return 0.0f; }
    return sqrt(leng);

}

vector<double> calculations::crossProduct(vector<double> target1, vector<double> target2) {
    vector<double> toReturn = {0, 0, 0};

    toReturn[X] = (target1[Y] * target2[Z]) - (target1[Z] * target2[Y]);
    toReturn[Y] = ((target1[Z] * target2[X]) - (target1[X] * target2[Z]));
    toReturn[Z] = (target1[X] * target2[Y]) - (target1[Y] * target2[X]);

    return toReturn;
}

double calculations::getError(double curEndX, double curEndY, double targetX, double targetY) {
    vector<double> vector = {curEndX - targetX, curEndY - targetY, 0};
    return length(vector);
}
