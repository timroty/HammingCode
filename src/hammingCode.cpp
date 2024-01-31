#include <iostream>
#include <vector>

#include "include/hammingCode.hpp"

using namespace std;

HammingCode::HammingCode(int codeWordLength, int parityBits, int dataBits) :
  codeWordLength(codeWordLength), parityBits(parityBits), dataBits(dataBits) {}

vector<int> HammingCode::encode(const vector<int>& inputVector) {
  vector<int> encodedBits;
  vector<int> currentBlock(codeWordLength);
  int currentBlockIndex = 1;
  int currentBlockXOR = 0;
  int currentTrueBits = 0;

  for (int i = 0; i < inputVector.size(); i ++) {
    if (currentBlockIndex == codeWordLength){
      calculateParityBits(currentBlock, currentBlockXOR, currentTrueBits);
      encodedBits.insert(encodedBits.end(), currentBlock.begin(), currentBlock.end());

      // Reset
      currentBlockIndex = 1;
      currentBlockXOR = 0;
      currentTrueBits = 0;
      resetCurrentBlock(currentBlock);
    }

    while(isParityBit(currentBlockIndex)){
      currentBlockIndex ++;
    }

    currentBlock[currentBlockIndex] = inputVector[i];
    if (inputVector[i]){
      currentBlockXOR = currentBlockXOR ^ currentBlockIndex;
      currentTrueBits ++;
    }
    
    currentBlockIndex ++;
  }

  calculateParityBits(currentBlock, currentBlockXOR, currentTrueBits);
  encodedBits.insert(encodedBits.end(), currentBlock.begin(), currentBlock.end());

  return encodedBits;
}

void HammingCode::calculateParityBits(vector<int>& inputVector, int bitsXOR, int trueBits) {
  int bitPostion = 2 << (parityBits - 2);

  while (bitPostion > 0) {
    int parityBit = (bitPostion & bitsXOR) > 0;
    inputVector[bitPostion] = parityBit; 
    trueBits += parityBit;

    bitPostion = bitPostion >> 1;
  }

  inputVector[0] = trueBits % 2;
}

bool HammingCode::isParityBit(int index) {
  return (index > 0) && ((index & (index - 1)) == 0);
}

void HammingCode::resetCurrentBlock(vector<int>& inputVector) {
  for (int i = 0; i < inputVector.size(); i ++) {
    inputVector[i] = 0;
  }
}
