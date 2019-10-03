#ifndef REVKEN_ARMCOMONENT_H
#define REVKEN_ARMCOMONENT_H

class armComponent {
private:
    double L;

    armComponent *previous = nullptr;
public:
    double angle, x, y, z;

    std::vector<double> mountPoint;

    armComponent(armComponent *previousComponent, double l, double angle);

    armComponent(double l, double angle);

    armComponent(armComponent *previousComponent, double l);

    double getAngle();

    double getX();

    double getY();

    std::vector<double> getMountPoint();

    void changeAngle(const std::vector<double> &curVector, const std::vector<double> &targetVector);

    double getNewX();

    double getNewY();

    double getZ();

    std::vector<double> getNewMountPoint();
};

#endif //REVKEN_ARMCOMONENT_H
