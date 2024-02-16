#include <cmath>
#include <filesystem>

#include "include/verification.hpp"
#include "include/constants.hpp"

using namespace std;

namespace Verification {
  bool isValidHammingParameters(int totalBits, int dataBits) {
      // Check if the totalBits and dataBits are valid for a Hamming code
      int parityBits = totalBits - dataBits;

      return (totalBits >= dataBits) && (pow(2, parityBits) >= dataBits + parityBits + 1);
  }

  bool isValidProgramParameters(int argc, char* argv[]) {
    return argc >= 4
      && (strcmp(argv[1], Constants::STR_ENCODE) == 0 || strcmp(argv[1], Constants::STR_DECODE) == 0)
      && (filesystem::exists(argv[2]) && filesystem::is_regular_file(argv[2]));
  }
}
