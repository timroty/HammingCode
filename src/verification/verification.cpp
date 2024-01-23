#include "verification.h"
#include <cmath>
#include <filesystem>

using namespace std;

namespace Verification {
  bool isValidHammingParameters(int totalBits, int dataBits) {
      // Check if the totalBits and dataBits are valid for a Hamming code
      int parityBits = totalBits - dataBits;

      return (totalBits >= dataBits) && (pow(2, parityBits) >= dataBits + parityBits + 1);
  }

  bool isValidProgramParameters(int argc, char* argv[]) {
      return argc >= 3
        && (filesystem::exists(argv[1]) && filesystem::is_regular_file(argv[1]))
        && (filesystem::exists(argv[2]) && filesystem::is_regular_file(argv[2]));
  }
}
