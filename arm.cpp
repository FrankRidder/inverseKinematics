#include <vector>
#include <cstdio>
#include "arm.h"

using namespace std;

void arm::moveTo(vector<double> endPos, double constraint, double errorMargin) {
    if (calculations::dist(curEnd, endPos) > errorMargin) {
        while (error > errorMargin) {
            if (tries++ == MAX_IK_TRIES) {
                printf("didnt'make it\n");
                printf("Got to X:%f Y: %f\n", segments[Z]->getX(), segments[Z]->getY());
                printf("Needed to get to to X:%f Y: %f\n", endPos[X], endPos[Y]);
                return;
            }

            while (currentSegment >= 0) {
                vector<double> mount = segments[currentSegment]->getMountPoint();
                curEnd = {segments[lastSegment]->getX(), segments[lastSegment]->getY(), 0.0f};

                curVector[X] = curEnd[X] - mount[X];
                curVector[Y] = curEnd[Y] - mount[Y];
                curVector[Z] = curEnd[Z] - mount[Z];

                targetVector[X] = endPos[X] - mount[X];
                targetVector[Y] = endPos[Y] - mount[Y];
                targetVector[Z] = endPos[Z] - mount[Z];

                calculations::normalize(targetVector);
                calculations::normalize(curVector);

                segments[currentSegment]->changeAngle(curVector, targetVector, constraint);
                currentSegment--;
            }
            currentSegment = (int) segments.size() - 1;
            error = calculations::getError(segments[currentSegment]->getX(),
                                           segments[currentSegment]->getY(), endPos[X], endPos[Y]);
        }
        printf("Solved in %d tries\n", tries);
        printf("Got to X:%f Y: %f\n", segments[Z]->getX(), segments[Z]->getY());
        printf("Needed to get to to X:%f Y: %f\n", endPos[X], endPos[Y]);
    }

}


arm::arm() {
    auto *one = new armComponent(15.0f, 90.0f);
    segments.push_back(one);
    auto *two = new armComponent(one, 18.0f);
    segments.push_back(two);
    auto *three = new armComponent(two, 16.0f);
    segments.push_back(three);

    curVector = {0, 0, 0};
    targetVector = {0, 0, 0};
    curEnd = {0, 0, 0};

    currentSegment = (int) segments.size() - 1;
    lastSegment = (int) segments.size() - 1;
}



