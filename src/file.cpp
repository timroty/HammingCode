#include <fstream>
#include <vector>
#include <iostream>

#include "include/constants.hpp"
#include "include/file.hpp"

using namespace std;

namespace File {
  vector<int> read(char* inputFilePath) {
    vector<int> values;
    ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading: " << inputFilePath << endl;
        return values;
    }

    char value;
    while (inputFile >> value) {
        int intValue = value - '0';
        
        // Ensure only 1's and 0's
        if (intValue != 0 && intValue != 1){
          cout << "Invlaid input value of '" << value << "'. Casting to 1." << endl;
          intValue = 1;
        }
          
        values.push_back(intValue);
    }

    inputFile.close();

    return values;
  }

  void write(vector<int>& dataVector, char* outputFilePath) {
    ofstream outFile(outputFilePath); 

    if (!outFile.is_open()) {
      cerr << "Error opening file for writing: " << outputFilePath << endl;
    }

    for (int num : dataVector) {
      outFile << num ;
    }
    
    outFile.close();
  }
}
