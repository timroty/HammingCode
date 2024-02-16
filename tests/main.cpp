#include <iostream>
#include <vector>

#include "../../src/include/constants.hpp"
#include "../../src/include/hammingCode.hpp"

using namespace std;

// HAMMING CODE TESTS

/*
*
* ENCODE
*
*/
void HammingCode_Encode_AllZerosInput() {
  vector<int> input = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Encode_AllZerosInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Encode_AllZerosInput" << endl;
  }
}

void HammingCode_Encode_EmptyInput() {
  vector<int> input = { };
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Encode_EmptyInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Encode_EmptyInput" << endl;
  }
}

void HammingCode_Encode_InputLengthEqualsDataBits() {
  vector<int> input = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Encode_InputLengthEqualsDataBits" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Encode_InputLengthEqualsDataBits" << endl;
  }
}

void HammingCode_Encode_InputLengthEqualsDataBitsAndSomeMore() {
  vector<int> input = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
  vector<int> expectedOutput = {1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Encode_InputLengthEqualsDataBitsAndSomeMore" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Encode_InputLengthEqualsDataBitsAndSomeMore " << endl;
  }
}

void HammingCode_Encode_InputLengthEqualsMultipleOfDataBits() {
  vector<int> input = {1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0};
  vector<int> expectedOutput = {1,1,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.encode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_Encode_InputLengthEqualsMultipleOfDataBits" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Encode_InputLengthEqualsMultipleOfDataBits" << endl;
  }
}

/*
*
* DECODE
*
*/

void HammingCode_Decode_AllZerosInput() {
  vector<int> input = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_AllZerosInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_AllZerosInput" << endl;
  }
}

void HammingCode_Decode_EmptyInput() {
  vector<int> input = { };
  vector<int> expectedOutput = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_EmptyInput" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_EmptyInput" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength() {
  vector<int> input = {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordLengthAndSomeMore() {
  vector<int> input = {1,1,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0};
  vector<int> expectedOutput = {1,1,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,0,0,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordLengthAndSomeMore" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordLengthAndSomeMore " << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength() {
  vector<int> input = {1,1,1,1,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,0,0};
  vector<int> expectedOutput = {1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_NonParity() {
  vector<int> input = {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_NonParity" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_NonParity" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_Parity() {
  vector<int> input = {1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_Parity" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_Parity" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_ParityAndNon() {
  vector<int> input = {1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0};
  vector<int> expectedOutput = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_ParityAndNon" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_ParityAndNon" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Parity() {
  vector<int> input = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Parity" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Parity" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Non() {
  vector<int> input = {1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1};
  vector<int> expectedOutput = {0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);

  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Non" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Non" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_OneErrorEach() {
  vector<int> input = {1,1,1,0,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0};
  vector<int> expectedOutput = {1,1,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_OneErrorEach" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_OneErrorEach" << endl;
  }
}

void HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_TwoErrorEach() {
  vector<int> input = {1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,1};
  vector<int> expectedOutput = {1,0,0,1,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1};

  HammingCode hammingCode(Constants::INT_CODEWORD_LENGTH, Constants::INT_PARITY_BITS, Constants::INT_DATA_BITS);
  
  vector<int> output = hammingCode.decode(input);
  
  if (expectedOutput == output){
    cout << "Passed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_TwoErrorEach" << endl;
  } 
  else {
    cerr << "Failed | HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_TwoErrorEach" << endl;
  }
}


int main(int argc, char* argv[]) {
  // Encode
  HammingCode_Encode_AllZerosInput();
  HammingCode_Encode_EmptyInput();
  HammingCode_Encode_InputLengthEqualsDataBits();
  HammingCode_Encode_InputLengthEqualsDataBitsAndSomeMore();
  HammingCode_Encode_InputLengthEqualsMultipleOfDataBits();

  // Decode
  HammingCode_Decode_AllZerosInput();
  HammingCode_Decode_EmptyInput();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength();
  HammingCode_Decode_InputLengthEqualsCodeWordLengthAndSomeMore();
  HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_NonParity();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength_OneError_Parity();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_ParityAndNon();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Parity();
  HammingCode_Decode_InputLengthEqualsCodeWordsLength_TwoErrors_Non();
  HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_OneErrorEach();
  HammingCode_Decode_InputLengthEqualsMultipleOfCodeWordLength_TwoErrorEach();

  return 0;
}