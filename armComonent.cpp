#include <vector>
#include <cstdio>
#include "armComonent.h"
#include "calculations.h"

using namespace std;


armComponent::armComponent(armComponent *previousComponent, double l, double angle) {
    previous = previousComponent;
    L = l;
    this->angle = angle * (M_PI / 180);
}

armComponent::armComponent(armComponent *previousComponent, double l) {
    previous = previousComponent;
    L = l;
    angle = 90.0f * (M_PI / 180);
}

armComponent::armComponent(double l, double angle) {
    previous = nullptr;
    L = l;
    this->angle = angle * (M_PI / 180);
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
    return previous->getX() + (L * sin(angle + previous->getAngle()));
}

double armComponent::getY() {
    if (previous == nullptr) {
        return (L * cos(angle));

    }
    return previous->getY() + (L * cos(angle + previous->getAngle()));
}

vector<double> armComponent::getMountPoint() {
    if (previous == nullptr) {
        return {0, 0, 0};
    }
    return {previous->getX(), previous->getY(), 0};
}

void armComponent::changeAngle(const vector<double> &curVector, const vector<double> &targetVector) {
    calculations::normalize(targetVector);
    calculations::normalize(curVector);

    auto cosAngle = calculations::angle(targetVector, curVector);

    auto crossResult = calculations::crossProduct(targetVector, curVector);
    if (crossResult[Z] > 0.0f) {
        angle -= cosAngle;
    } else {
        angle += cosAngle;
    }

}




