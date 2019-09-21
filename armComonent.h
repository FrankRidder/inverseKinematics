#ifndef REVKEN_ARMCOMONENT_H
#define REVKEN_ARMCOMONENT_H

class armComponent {
private:
    double L;

    armComponent* previous = nullptr;

    static const int X = 0;
    static const int Y = 1;
    static const int Z = 2;
public:
    double angle;

    armComponent(armComponent* previousComponent, double l, double angle);

    armComponent(double l, double angle);

    armComponent(armComponent* previousComponent, double l);

    double getAngle();

    double getX();

    double getY();

    std::vector<double> getMountPoint();

    void changeAngle(const std::vector<double>& curVector, const std::vector<double>& targetVector);
};

#endif //REVKEN_ARMCOMONENT_H
