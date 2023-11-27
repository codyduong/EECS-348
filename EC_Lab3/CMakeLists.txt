cmake_minimum_required(VERSION 3.14)
project(extra_credit_lab3)

# Configure Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure Main CLI
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

add_executable(extra_credit_lab3
  src/Account.cpp
  src/CurrentAccount.cpp
  src/SavingsAccount.cpp
  src/main.cpp
  src/Account.h
  src/CurrentAccount.h
  src/SavingsAccount.h
)