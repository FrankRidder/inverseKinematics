#include <vector>
#include <cstdio>
#include "arm.h"

using namespace std;

void arm::moveTo(vector<double> endPos) {
    currentSegment = (int) segments.size() - 1;


    if (calculations::dist(curEnd, endPos) > IK_POS_THRESH) {
        while (error > IK_POS_THRESH) {
            if (tries++ == MAX_IK_TRIES) {
                printf("didnt'make it\n");
                printf("Got to X:%f Y: %f\n", segments[Z]->getX(),segments[Z]->getY());
                printf("Needed to get to to X:%f Y: %f\n", endPos[X],endPos[Y]);
                return;
            }

            curEnd = {segments[currentSegment]->x, segments[currentSegment]->y, 0.0f};
            segments[currentSegment]->getNewMountPoint();

            while (currentSegment >= 0) {
                curVector[X] = curEnd[X] - segments[currentSegment]->mountPoint[X];
                curVector[Y] = curEnd[Y] - segments[currentSegment]->mountPoint[Y];
                curVector[Z] = curEnd[Z] - segments[currentSegment]->mountPoint[Z];

                targetVector[X] = endPos[X] - segments[currentSegment]->mountPoint[X];
                targetVector[Y] = endPos[Y] - segments[currentSegment]->mountPoint[Y];
                targetVector[Z] = endPos[Z] - segments[currentSegment]->mountPoint[Z];

                calculations::normalize(targetVector);
                calculations::normalize(curVector);

                segments[currentSegment]->changeAngle(curVector, targetVector);
                currentSegment--;
            }
            currentSegment = (int) segments.size() - 1;
            error = calculations::getError(segments[currentSegment]->getX(),
                    segments[currentSegment]->getY(), endPos[X], endPos[Y]);

            printf("%f,%f\n", segments[X]->getX(),segments[X]->getY());
            printf("%f,%f\n", segments[Y]->getX(),segments[Y]->getY());
            printf("%f,%f\n", segments[Z]->getX(),segments[Z]->getY());
            printf("\n");

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

    curVector = {0, 0, 0};
    targetVector = {0, 0, 0};
    curEnd = {0, 0, 0};

    currentSegment = 0;


}



