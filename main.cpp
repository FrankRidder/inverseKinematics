#include <vector>
#include <iostream>
#include "arm.h"

using namespace std;

int main() {
    arm arm;

    double demping, x, y, errorMargin;

    cout << "Geeft een x waarde\n" << endl;
    cin >> x;

    cout << "Geef een y waarde\n" << endl;
    cin >> y;

    cout << "Geef een demping in graden\n" << endl;
    cin >> demping;

    cout << "Geef een errormargin (commagetal mogelijk)\n" << endl;
    cin >> errorMargin;

    vector<double> endpos = {x, y, 0};

    demping = demping * (M_PI / 180.0f);

    arm.moveTo(endpos, demping, errorMargin);

    return 0;
}

