#include <vector>
#include <cstdio>
#include "armComonent.h"
#include "calculations.h"

using namespace std;


armComponent::armComponent(armComponent *previousComponent, double l, double angle) {
    previous = previousComponent;
    L = l;
    this->angle = angle * (M_PI / 180);
    this->x = getNewX();
    this->y = getNewY();
    this->z = 0.0f;
    mountPoint = getNewMountPoint();
}

armComponent::armComponent(armComponent *previousComponent, double l) {
    previous = previousComponent;
    L = l;
    angle = 0.0f * (M_PI / 180);
    this->x = getNewX();
    this->y = getNewY();
    this->z = 0.0f;
    mountPoint = getNewMountPoint();
}

armComponent::armComponent(double l, double angle) {
    previous = nullptr;
    L = l;
    this->angle = angle * (M_PI / 180);
    this->x = getNewX();
    this->y = getNewY();
    this->z = 0.0f;
    mountPoint = getNewMountPoint();
}

double armComponent::getAngle() {
    if (previous == nullptr) {
        return angle;
    }
    return previous->getAngle() + angle;
}

double armComponent::getX() {
    return this->x;
}

double armComponent::getNewX() {
    if (previous == nullptr) {
        x = (L * cos(angle));
        return x;

    }
    x = (previous->getX() + (L * sin(angle + previous->getAngle())));
    return x;
}

double armComponent::getY() {
    return this->y;
}

double armComponent::getNewY() {
    if (previous == nullptr) {
        y = (L * sin(angle));
        return y;
    }
    y = (previous->getY() + (L * cos(angle + previous->getAngle())));
    return y;
}

double armComponent::getZ() {
    return this->z;
}

vector<double> armComponent::getMountPoint() {
    return mountPoint;
}

vector<double> armComponent::getNewMountPoint() {
    if (previous == nullptr) {
        return {0, 0, 0};
    }
    return {previous->getX(), previous->getY(), 0};
}

void armComponent::changeAngle(const vector<double> &curVector, const vector<double> &targetVector) {
    auto cosAngle = calculations::angle(targetVector, curVector);

    auto crossResult = calculations::crossProduct(targetVector, curVector);

    if(cosAngle > 2.0f){
        cosAngle = 2.0f;
    }

    printf("Angle = %f \n", cosAngle);

    if (crossResult[2] < 0.0f) {
        angle -= cosAngle;
    } else {
        angle += cosAngle;
    }

    this->x = getNewX();
    this->y = getNewY();

}




