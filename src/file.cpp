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
          cerr << "Error opening file: " << inputFilePath << endl;
          return values;
      }

      char value;
      while (inputFile >> value) {
          int intValue = value - '0';

          // Ensure only 1's and 0's
          if (intValue != 0){
            cout << "Invlaid input value of '" << value << "'. Casting to 1." << endl;
            intValue = 1;
          }
            
          values.push_back(intValue);
      }

      inputFile.close();

      return values;
  }
}
