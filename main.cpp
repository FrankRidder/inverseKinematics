#include <vector>
#include "arm.h"

using namespace std;

int main() {

    arm arm;

    vector<double> endpos = {45, 15, 0};

    arm.moveTo(endpos);

    return 0;

}

