@echo off
:: Windows build script
set CXX=cl.exe
set CXXFLAGS=/EHsc /W4 /std:c++11
set LDFLAGS=
set SOURCES=calco.cpp
set TARGET=calco.exe

echo Building Calco...
%CXX% %CXXFLAGS% %SOURCES% /Fe:%TARGET% %LDFLAGS%

if %errorlevel% equ 0 (
    echo Build successful! Executable: %TARGET%
) else (
    echo Build failed!
    exit /b 1
)
