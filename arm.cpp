#include <vector>
#include <cstdio>
#include "arm.h"

using namespace std;

void arm::moveTo(vector<double> endPos, double errorMargin) {
    currentSegment = (int) segments.size() - 1;

    if (calculations::dist(curEnd, endPos) > IK_POS_THRESH) {
        while (error > errorMargin) {
            if (tries++ == MAX_IK_TRIES) {
                printf("didnt'make it\n");
                break;
            }

            while (currentSegment >= 0) {
                mountPos = segments[currentSegment]->getMountPoint();
                curEnd = {segments[currentSegment]->getX(), segments[currentSegment]->getY(), 0.0f};

                curVector[X] = curEnd[X] - mountPos[X];
                curVector[Y] = curEnd[Y] - mountPos[Y];
                curVector[Z] = curEnd[Z] - mountPos[Z];

                targetVector[X] = endPos[X] - mountPos[X];
                targetVector[Y] = endPos[Y] - mountPos[Y];
                targetVector[Z] = endPos[Z];

                segments[currentSegment]->changeAngle(curVector, targetVector);
                currentSegment--;
            }
            currentSegment = (int) segments.size() - 1;
            error = calculations::getError(segments[currentSegment]->getX(), segments[currentSegment]->getY(),
                                           endPos[X], endPos[Y]);

        }
        printf("Solved in %d tries\n", tries);
        printf("Got to X:%f Y: %f\n", segments[Z]->getX(),segments[Z]->getY());
        printf("Needed to get to to X:%f Y: %f\n", endPos[X],endPos[Y]);


    }

}


arm::arm() {
    auto *one = new armComponent(15.0f , 90.0f);
    segments.push_back(one);
    auto *two = new armComponent(one, 18.0f);
    segments.push_back(two);
    auto *three = new armComponent(two, 16.0f);
    segments.push_back(three);

    mountPos = {0, 0, 0};
    curVector = {0, 0, 0};
    targetVector = {0, 0, 0};
    curEnd = {0, 0, 0};

    currentSegment = 0;


}



