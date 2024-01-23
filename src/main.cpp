#include <iostream>
#include "verification/verification.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (!Verification::isValidProgramParameters(argc, argv)){
            cout << "Invalid file parameters. Expecting 2 file paths for input and output files." << endl;
        return 0;
    }
    
    int totalBits = 15;
    int dataBits = 11;

    bool areValidParameters = Verification::isValidHammingParameters(totalBits, dataBits);

    cout << areValidParameters << endl;

    return 0;
}
