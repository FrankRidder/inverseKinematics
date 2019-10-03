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

    std::vector<double> curVector,targetVector,curEnd;

    int tries = 0;

    double error = std::numeric_limits<double >::max();

    const int MAX_IK_TRIES = 100; // TIMES THROUGH THE CCD LOOP
    const double IK_POS_THRESH = 1.0f; // THRESHOLD FOR SUCCESS

public:
    int currentSegment;

    std::vector<armComponent*> segments;

    arm();

    void moveTo(std::vector<double> endPos);
};


#endif //REVKEN_ARM_H
