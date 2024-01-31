#include <iostream>
#include <vector>

#include "../../src/include/constants.hpp"
#include "../../src/include/hammingCode.hpp"

using namespace std;

// HAMMING CODE
void HammingCode_AllZerosInput() {
  vector<int> input = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_AllZerosInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_AllZerosInput" << endl;
  }
}

void HammingCode_EmptyInput() {
  vector<int> input = { };
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_EmptyInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_EmptyInput" << endl;
  }
}

void HammingCode_InputLengthEqualsDataBits() {
  vector<int> input = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_InputLengthEqualsDataBits" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_InputLengthEqualsDataBits" << endl;
  }
}

void HammingCode_InputLengthEqualsDataBitsAndSomeMore() {
  vector<int> input = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
  vector<int> expectedOutput = {1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_InputLengthEqualsDataBitsAndSomeMore" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_InputLengthEqualsDataBitsAndSomeMore " << endl;
  }
}

void HammingCode_InputLengthEqualsMultipleOfDataBits() {
  vector<int> input = {1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0};
  vector<int> expectedOutput = {1,1,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_InputLengthEqualsMultipleOfDataBits" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_InputLengthEqualsMultipleOfDataBits" << endl;
  }
}

int main(int argc, char* argv[]) {
  HammingCode_AllZerosInput();
  HammingCode_EmptyInput();
  HammingCode_InputLengthEqualsDataBits();
  HammingCode_InputLengthEqualsDataBitsAndSomeMore();
  HammingCode_InputLengthEqualsMultipleOfDataBits();

  return 0;
}