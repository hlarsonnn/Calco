#ifndef CALCO_H
#define CALCO_H

#include <string>

class Calco {
public:
    // Basic arithmetic operations with error handling
    static std::string add(double a, double b);
    static std::string subtract(double a, double b);
    static std::string multiply(double a, double b);
    static std::string divide(double a, double b);
    
    // Advanced operations
    static std::string power(double base, double exponent);
    static std::string squareRoot(double value);
    static std::string modulus(double a, double b);
    
    // Memory functions
    void memoryStore(double value);
    std::string memoryRecall() const;
    void memoryClear();
    void memoryAdd(double value);
    void memorySubtract(double value);
    
    // Utility functions
    static bool isError(const std::string& result);
    
private:
    double memory = 0.0;
    static constexpr const char* INF = "INF";
    static constexpr const char* ERROR = "ERR";
};

#endif // CALCO_H
