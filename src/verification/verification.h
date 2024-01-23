#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <string>

namespace Verification {
  bool isValidHammingParameters(int totalBits, int dataBits);
  bool isValidProgramParameters(int argc, char* argv[]);
}

#endif
