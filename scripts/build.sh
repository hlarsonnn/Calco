#!/bin/bash

# Compiler settings
CXX=g++
CXXFLAGS="-std=c++11 -Wall -Wextra"
LDFLAGS=""

# Source files
SOURCES="calco.cpp"
TARGET="calco"

# Build command
echo "Building Calco..."
$CXX $CXXFLAGS $SOURCES -o $TARGET $LDFLAGS

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo "Build successful! Executable: ./$TARGET"
else
    echo "Build failed!"
    exit 1
fi
