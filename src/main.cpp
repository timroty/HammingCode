#include <iostream>
#include <fstream>
#include <vector>

#include "include/verification.hpp"
#include "include/file.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (!Verification::isValidProgramParameters(argc, argv)){
        cout << "Invalid file parameters. Expecting 2 file paths for input and output files." << endl;
        return 0;
    }

    vector<int> input = File::read(argv[2]);

    cout << "ran!" << endl;

    return 0;
}
