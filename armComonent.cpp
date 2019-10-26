#include <vector>
#include <cstdio>
#include "armComonent.h"
#include "calculations.h"

using namespace std;


armComponent::armComponent(armComponent *previousComponent, double l, double angle) {
    previous = previousComponent;
    L = l;
    this->angle = angle * (M_PI / 180.0f);
}

armComponent::armComponent(armComponent *previousComponent, double l) {
    previous = previousComponent;
    L = l;
    this ->angle = 0.0f * (M_PI / 180.0f);
}

armComponent::armComponent(double l, double angle) {
    previous = nullptr;
    L = l;
    this->angle = angle * (M_PI / 180.0f);
}

double armComponent::getAngle() {
    if (previous == nullptr) {
        return angle;
    }
    return previous->getAngle() + angle;
}

double armComponent::getX() {
    if (previous == nullptr) {
        return (L * sin(angle));
    }
    return (previous->getX() + (L * sin(angle + previous->getAngle())));
}

double armComponent::getY() {
    if (previous == nullptr) {
        return (L * cos(angle));
    }
    return (previous->getY() + (L * cos(angle + previous->getAngle())));;
}

vector<double> armComponent::getMountPoint() {
    if (previous == nullptr) {
        return {0, 0, 0};
    }
    return {previous->getX(), previous->getY(), 0};
}

void armComponent::changeAngle(const vector<double> &curVector, const vector<double> &targetVector, double demping) {
    auto cosAngle = calculations::angle(targetVector, curVector);

    auto crossResult = calculations::crossProduct(targetVector, curVector);

    if (cosAngle > demping) {
        cosAngle = demping;
    }

    if (crossResult[2] < 0.0f) {
        angle -= cosAngle;
    } else {
        angle += cosAngle;
    }

    if(angle < M_PI * -1){
        angle = M_PI * -1;
    }else if (angle > M_PI){
        angle = M_PI;

    }
}




