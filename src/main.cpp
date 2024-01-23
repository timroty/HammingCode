#include <iostream>
#include "verification/verification.h"

using namespace std;

int main() {
    int totalBits = 15;
    int dataBits = 11;

    bool areValidParameters = Verification::isValidHammingParameters(totalBits, dataBits);

    cout << areValidParameters << endl;

    return 0;
}
