#ifndef HAMMINGCODE_HPP
#define HAMMINGCODE_HPP

#include <vector>

class HammingCode {
  private:
    int codeWordLength;
    int parityBits;
    int dataBits;

    void resetCurrentBlock(std::vector<int>& inputVector);
    void calculateParityBits(std::vector<int>& inputVector, int bitsXOR, int trueBits);
    bool isParityBit(int index);
    void checkAndFixCurrentBlock(std::vector<int>& dataBitVector, int bitsXOR, int trueBits);
    int getDataBitPosition(int codeWordPosition);

  public:
    HammingCode(int codeWordLength, int parityBits, int dataBits);

    std::vector<int> encode(const std::vector<int>& inputVector);
    std::vector<int> decode(const std::vector<int>& dataBitVector);
};

#endif
