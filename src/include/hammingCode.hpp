#ifndef HAMMINGCODE_HPP
#define HAMMINGCODE_HPP

#include <vector>

class HammingCode {
  private:
    int codeWordLength;
    int parityBits;
    int dataBits;

    void resetCurrentBlock(std::vector<int>& inputVector);

  public:
    HammingCode(int codeWordLength, int parityBits, int dataBits);

    std::vector<int> encode(const std::vector<int>& inputVector);
    void calculateParityBits(std::vector<int>& inputVector, int bitsXOR, int trueBits);
    bool isParityBit(int index);
};

#endif
