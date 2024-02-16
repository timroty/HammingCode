# HammingCode
A simple extended Hamming Code implementation in C++.

### Motivation
I watched [3Blue1Brown's](https://www.youtube.com/@3blue1brown) video on Hamming Codes and thought it would be an interesting project to learn and try to implement. 

### Compile and Run
#### Dependencies
- Cmake `3.10`
- clang version `17`

#### Program
1. Navigate to the ```build``` directory and run ```cmake .```.
2. Compile the program using ```make```.
3. Run the executable ```HammingCode```. The program expects 3 arguments in the following order:
    1. `encode` or `decode`, depending on the desired use case.
    2. The absolute file path to the input file.
    3. The absolute file path to the output file.
    4. A sample command for running the program might look as follows: `./HammingCode encode "/Users/GitHub/HammingCode/input.txt" "/Users/GitHub/HammingCode/output.txt"` 

##### Implementation Details
When decoding, for each 16 bit chunk, if the program finds a flipped bit and can fix it, the bit in the output will be flipped to be correct. If thre are 2 errors, the program will not be able to fix the output and will write the data bits as received. 

The output file does not need to exist, the program will create it if not.

#### Tests
1. Navigate to the ```tests/build``` directory and run ```cmake .```.
2. Compile the program using ```make```.
3. Run the executable ```HammingCodeTests```. The program expects 0 arguments.
4. Each test will have either ```Passed``` or ```Failed``` preceding the name of the function containing the test printed.

