CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
PROJECT (B VERSION 1.0 LANGUAGES CXX)

ADD_LIBRARY (B SHARED b.cpp b.hpp)
TARGET_INCLUDE_DIRECTORIES (B PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
TARGET_LINK_LIBRARIES (B PRIVATE A)

##  Create the test executable
ADD_EXECUTABLE (B-test main.cpp)
TARGET_LINK_LIBRARIES (B-test B)

##  CTest
ENABLE_TESTING ()
ADD_TEST (NAME B-test COMMAND B-test)
