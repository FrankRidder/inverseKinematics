#ifndef REVKEN_ARM_H
#define REVKEN_ARM_H

#include "armComonent.h"
#include "calculations.h"


class arm {
private:
    static const int X = 0;
    static const int Y = 1;
    static const int Z = 2;

    double cosAngle, turnAngle, turnDeg;
    std::vector<double> rootPos, desiredEnd, crossResult,curVector,targetVector,curEnd;
    int link, tries;

    const int EFFECTORS = 3;
    const int MAX_IK_TRIES = 100; // TIMES THROUGH THE CCD LOOP
    const double IK_POS_THRESH = 1.0f; // THRESHOLD FOR SUCCESS

public:
    std::vector<armComponent*> segments;
    arm();
    void moveTo(std::vector<double > endPos);
};


#endif //REVKEN_ARM_H
