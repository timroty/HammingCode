#include "verification.h"
#include <cmath>

using namespace std;

namespace Verification {
  bool isValidHammingParameters(int totalBits, int dataBits) {
      // Check if the totalBits and dataBits are valid for a Hamming code
      int parityBits = totalBits - dataBits;

      return (totalBits >= dataBits) && (pow(2, parityBits) >= dataBits + parityBits + 1);
  }
}
