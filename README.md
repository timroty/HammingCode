# HammingCode
A simple extended Hamming Code implementation in C++.

### Compile and Run
#### Dependencies
- Cmake `3.10`
- clang version `17`

1. Navigate to the ```build``` directory and run ```cmake .```.
2. Compile the program using ```make```.
3. Run the executable ```HammingCode```. The program expects 3 arguments in the following order:
    1. `encode` or `decode`, depending on the desired use case.
    2. The file path to the input file.
    3. The file path to the output file.

#### Tests
1. Navigate to the ```tests/build``` directory and run ```cmake .```.
2. Compile the program using ```make```.
3. Run the executable ```HammingCodeTests```. The program expects 0 arguments.
4. Each test will have either ```Passed``` or ```Failed``` preceding the name of the function containing the test printed.

