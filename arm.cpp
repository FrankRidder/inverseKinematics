#include <vector>
#include <cstdio>
#include "arm.h"

using namespace std;

void arm::moveTo(vector<double> endPos) {
    rootPos = {0.0f, 0.0f, 0.0f};
    curEnd = {segments.back()->getX(), segments.back()->getY(), 0.0f};
    desiredEnd = {endPos[X], endPos[Y], endPos[Z]};

    if (calculations::dist(curEnd, desiredEnd) > IK_POS_THRESH) {
        curVector[X] = curEnd[X] - rootPos[X];
        curVector[Y] = curEnd[Y] - rootPos[Y];
        curVector[Z] = curEnd[Z] - rootPos[Z];

        targetVector[X] = endPos[X] - rootPos[X];
        targetVector[Y] = endPos[Y] - rootPos[Y];
        targetVector[Z] = endPos[Z];

        calculations::normalize(targetVector);
        calculations::normalize(curVector);

        cosAngle = calculations::angle(targetVector,curVector);
        printf("angle %f \n", cosAngle);

        if (cosAngle < 0.99999)
        {
            crossResult = calculations::crossProduct(targetVector, curVector);
            printf("cross %f \n", crossResult[Z]);
        }

    }

}


arm::arm() {
    auto *root = new armComponent(0.0f, 0.0f);
    segments.emplace_back(root);
    auto *one = new armComponent(root, 15.0f);
    segments.push_back(one);
    auto *two = new armComponent(one, 18.0f);
    segments.push_back(two);
    auto *three = new armComponent(two, 16.0f);
    segments.push_back(three);

    rootPos = {0,0,0};
    desiredEnd = {0,0,0};
    crossResult = {0,0,0};
    curVector = {0,0,0};
    targetVector = {0,0,0};
    curEnd  = {0,0,0};


    link = 3;

    tries = 0;


}



