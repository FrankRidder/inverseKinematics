#include "armComonent.h"

using namespace std;


armComponent::armComponent(armComponent* previousComponent, double l, double angle) {
    previous = previousComponent;
    L = l;
    this->angle = angle * (M_PI / 180);
};

armComponent::armComponent(armComponent* previousComponent, double l) {
    previous = previousComponent;
    L = l;
    angle = 0.0f * (M_PI / 180);
};

armComponent::armComponent(double l, double angle) {
    previous = nullptr;
    L = l;
    this->angle = angle * (M_PI / 180);
};

double armComponent::getAngle() {
    if (previous == nullptr) {
        return angle;
    }
    return previous->getAngle() + angle;
};

double armComponent::getX() {
    if (previous == nullptr) {
        return (L * sin(angle));

    }
    return previous->getX() + (L * sin(angle + previous->getAngle()));
};

double armComponent::getY() {
    if (previous == nullptr) {
        return (L * cos(angle));

    }
    return previous->getY() + (L * cos(angle + previous->getAngle()));
};



