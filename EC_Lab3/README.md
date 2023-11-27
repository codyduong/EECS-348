# Extra Credit Lab 3
Uses CMake for the toolchain management/build system.

## Build from Source

### Dependencies
Install through your preferred format, on your preferred operating system

- [LLVM](https://www.llvm.org/) or preferred build toolchain
- [CMake](https://cmake.org/)
- [Google Test](https://github.com/google/googletest)

Provided are CLI instructions for building from source:
- [For Linux/Ubuntu](#linux)
- [For macOS](#macos)
- [For Windows](#windows)<br></br>
These commands are provided as a courtesy examples, and may vary greatly dependent on version of OS, et. cetera.

### Linux
Dependencies
```bash
sudo apt-get install cmake
sudo apt install clang
sudo apt-get install libgtest-dev
```

Build
```bash
mkdir build
cmake -S . -B build && make -C build
```

Run
```bash
./build/extra_credit_lab3
```

### macOS
Dependencies
```bash
brew install cmake
brew install clang
brew install gtest
```

Build
```bash
mkdir build
cmake -S. -B build && make -C build
```

Run
```bash
./build/extra_credit_lab3
```

### Windows
Install [wsl](https://learn.microsoft.com/en-us/windows/wsl/install) and go to [Linux Installation Instructions](#linux)
<!-- LOL! -->