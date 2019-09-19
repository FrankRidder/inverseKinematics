#ifndef REVKEN_ARMCOMONENT_H
#define REVKEN_ARMCOMONENT_H

//#include <iostream>
#include <cmath>
//#include <vector>

class armComponent {
private:
    double L, angle;
    armComponent* previous = nullptr;
public:
    armComponent(armComponent* previousComponent, double l, double angle);

    armComponent(double l, double angle);

    armComponent(armComponent* previousComponent, double l);

    double getAngle();

    double getX();

    double getY();


};

#endif //REVKEN_ARMCOMONENT_H
