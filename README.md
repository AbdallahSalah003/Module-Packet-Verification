# Module-Packet-Verification

<h3>
Automated verification of packet sequences for module transitions using C++. This tool checks packet validity based on rules and creates a CSV report with results for each sequence.
</h3>

## Built With

[![cpp][cpp]][cpp-url] [![gtest][gtest]][gtest-url]

## How to Run

1. Clone the repository.

```
git clone https://github.com/AbdallahSalah003/server-client-config.git
```

2. install g++

```
sudo apt update
sudo apt install g++
```

3. Navigate to the project dir and Run the following to compile and link:

```
g++ main.cpp utils.cpp -o main.exe
```

4. To run the program: replace packets with the number of packets, and modules 1->N with the number of modules

```
./main.exe packets module1, module2, ......, moduleN
#ex: ./main.exe 4 1 3 4 4
```

## To run the unit tests we need to follow these steps

1. first we need to install cmake

```
sudo apt install cmake
```

2. then run the following command to install gtest lib and dependencies

```
sudo apt install libgtest-dev googletest
```

3. navigate to /usr/src/gtest, and run the following

```
sudo cmake -Bbuild
sudo cmake --build build
sudo cp ./build/lib/libgtest* /usr/lib
```

4. navigate to the project dir and run:

```
cmake -Bbuild
cmake --build build
```

5. now you could able to run the test cases, try each file begins with test\_ in build dir:

```
./build/test_
#ex: ./build/test_assign_valid_invalid
```

[cpp]: https://img.shields.io/badge/CPP-black?style=for-the-badge&logo=cplusplus
[cpp-url]: https://cplusplus.com/doc/tutorial/
[gtest]: https://img.shields.io/badge/gtest-darkblue?style=for-the-badge&logo=google
[gtest-url]: https://google.github.io/googletest/
