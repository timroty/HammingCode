#ifndef FILE_HPP
#define FILE_HPP

namespace File {
  std::vector<int> read(char* inputFilePath);
  void write(std::vector<int>& dataVector, char* outputFilePath);
}

#endif
