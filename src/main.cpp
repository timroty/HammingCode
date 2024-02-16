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
    vector<int> result;

    HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
    if (strcmp(argv[1], Constants::STR_ENCODE) == 0){
        result = hammingCode.encode(input);
    } else {
        result = hammingCode.decode(input);
    }

    File::write(result, argv[3]);

    return 0;
}
