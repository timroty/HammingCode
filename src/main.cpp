#include <iostream>
#include <fstream>
#include <vector>

#include "include/constants.hpp"
#include "include/file.hpp"
#include "include/hammingCode.hpp"
#include "include/verification.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (!Verification::isValidProgramParameters(argc, argv)){
        cout << "Invalid file parameters. Expecting 2 file paths for input and output files." << endl;
        return 0;
    }

    vector<int> input = File::read(argv[2]);

    HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
    if (strcmp(argv[1], Constants::STR_ENCODE)){
        vector<int> result = hammingCode.encode(input);
    } else {
        
    }

    return 0;
}
