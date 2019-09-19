#ifndef REVKEN_CALCULATIONS_H
#define REVKEN_CALCULATIONS_H

#include <cmath>


class calculations {
private:
    static const int X = 0;
    static const int Y = 1;
    static const int Z = 2;
public:

    static double length(std::vector<double> target);

    static double angle(const std::vector<double> &target1, const std::vector<double> &target2);

    static double dist(std::vector<double> &from, std::vector<double> &to);

    static std::vector<double> normalize(std::vector<double> target);

    static double dotProduct(std::vector<double> target1, std::vector<double> target2);

    static std::vector<double> crossProduct(std::vector<double> target1, std::vector<double> target2);
};


#endif //REVKEN_CALCULATIONS_H
