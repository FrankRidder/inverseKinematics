#ifndef REVKEN_ARMCOMONENT_H
#define REVKEN_ARMCOMONENT_H

class armComponent {
private:
    double L, angle;

    armComponent *previous = nullptr;

    double getAngle();

public:
    void changeAngle(const std::vector<double> &curVector, const std::vector<double> &targetVector, double demping);

    armComponent(armComponent *previousComponent, double l, double angle);

    armComponent(double l, double angle);

    armComponent(armComponent *previousComponent, double l);

    double getX();

    double getY();

    std::vector<double> getMountPoint();
};

#endif //REVKEN_ARMCOMONENT_H
