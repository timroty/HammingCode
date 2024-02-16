#include <iostream>
#include <vector>

#include "include/hammingCode.hpp"

using namespace std;

HammingCode::HammingCode(int codeWordLength, int parityBits, int dataBits) :
  codeWordLength(codeWordLength), parityBits(parityBits), dataBits(dataBits) {}

vector<int> HammingCode::encode(const vector<int>& inputVector) {
  vector<int> encodedBits;
  vector<int> codeWordBlock(codeWordLength);
  int codeWordBlockIndex = 1;
  int codeWordBlockXOR = 0;
  int codeWordTrueBits = 0;

  for (int i = 0; i < inputVector.size(); i ++) {
    if (codeWordBlockIndex == codeWordLength){
      calculateParityBits(codeWordBlock, codeWordBlockXOR, codeWordTrueBits);
      encodedBits.insert(encodedBits.end(), codeWordBlock.begin(), codeWordBlock.end());

      // Reset
      codeWordBlockIndex = 1;
      codeWordBlockXOR = 0;
      codeWordTrueBits = 0;
      resetCurrentBlock(codeWordBlock);
    }

    while(isParityBit(codeWordBlockIndex)){
      codeWordBlockIndex ++;
    }

    codeWordBlock[codeWordBlockIndex] = inputVector[i];
    if (inputVector[i]){
      codeWordBlockXOR = codeWordBlockXOR ^ codeWordBlockIndex;
      codeWordTrueBits ++;
    }
    
    codeWordBlockIndex ++;
  }

  calculateParityBits(codeWordBlock, codeWordBlockXOR, codeWordTrueBits);
  encodedBits.insert(encodedBits.end(), codeWordBlock.begin(), codeWordBlock.end());

  return encodedBits;
}

std::vector<int> HammingCode::decode(const std::vector<int>& encodedVector){
  vector<int> decodedBits;
  vector<int> dataBitBlock(dataBits);
  int codeWordBlockXOR = 0;
  int codeWordTrueBits = 0;

  for (int i = 0; i < encodedVector.size(); i ++) {
    // Plus one to avoid adding unnecessary padding to the databits
    if (!(i % codeWordLength) && i > 0){
      checkAndFixCurrentBlock(dataBitBlock, codeWordBlockXOR, codeWordTrueBits);
      decodedBits.insert(decodedBits.end(), dataBitBlock.begin(), dataBitBlock.end());

      // Reset
      codeWordBlockXOR = 0;
      codeWordTrueBits = 0;
      resetCurrentBlock(dataBitBlock);
    }

    if (encodedVector[i]) {
      codeWordTrueBits ++;
      if (i % codeWordLength) {
        codeWordBlockXOR = codeWordBlockXOR ^ (i % codeWordLength);
      }
    }

    if (!isParityBit(i % codeWordLength) && (i % codeWordLength)) {
      dataBitBlock[getDataBitPosition(i % codeWordLength)] = encodedVector[i];
    }
  }

  checkAndFixCurrentBlock(dataBitBlock, codeWordBlockXOR, codeWordTrueBits);
  decodedBits.insert(decodedBits.end(), dataBitBlock.begin(), dataBitBlock.end());

  return decodedBits;
}

// Private Methods

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

int HammingCode::getDataBitPosition(int codeWordPosition) {
  // - 1 for the 0th power
  // - 1 to get the index right
  return codeWordPosition - floor(log2(codeWordPosition)) - 2;
}

void HammingCode::checkAndFixCurrentBlock(vector<int>& dataBitVector, int bitsXOR, int trueBits) {
  if (bitsXOR) {
    if (trueBits % 2 == 0) {
      // There are multiple errors in the block and cannont reliability fix
      cout << "  Multiple errors in the block" << endl;
      return;
    }

    if (isParityBit(bitsXOR)) {
      // Parity bits are not included in output so if there is a mistake skip
      cout << "  One error in the block on a parity bit" << endl;
      return;
    }

    int inputVectorPosition = getDataBitPosition(bitsXOR);
    dataBitVector[inputVectorPosition] = 1 - dataBitVector[inputVectorPosition];
    cout << "  One error in the block on a data bit. Flipping in output." << endl;
  }
}
