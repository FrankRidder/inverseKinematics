#ifndef REVKEN_ARM_H
#define REVKEN_ARM_H

#include <limits>
#include "armComonent.h"
#include "calculations.h"


class arm {
private:
    static const int X = 0;
    static const int Y = 1;
    static const int Z = 2;

    std::vector<double> curVector, targetVector, curEnd;

    int lastSegment, currentSegment;

    int tries = 0;

    double error = std::numeric_limits<double>::max();

    const int MAX_IK_TRIES = 1000;

    std::vector<armComponent *> segments;

public:
    arm();

    void moveTo(std::vector<double> endPos, double constraint, double errorMargin);
};

#endif //REVKEN_ARM_H
