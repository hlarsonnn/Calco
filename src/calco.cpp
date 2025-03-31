#include "calco.h"
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

// Basic arithmetic operations with string returns
string Calculator::add(double a, double b) {
    double result = a + b;
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    // Remove trailing zeros and . if not needed
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

string Calculator::subtract(double a, double b) {
    double result = a - b;
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

string Calculator::multiply(double a, double b) {
    double result = a * b;
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

string Calculator::divide(double a, double b) {
    if (b == 0) {
        return INF;
    }
    double result = a / b;
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

// Advanced operations
string Calculator::power(double base, double exponent) {
    double result = pow(base, exponent);
    if (isnan(result) || isinf(result)) {
        return ERROR;
    }
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

string Calculator::squareRoot(double value) {
    if (value < 0) {
        return ERROR;
    }
    double result = sqrt(value);
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

string Calculator::modulus(double a, double b) {
    if (b == 0) {
        return ERROR;
    }
    double result = fmod(a, b);
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << result;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

// Memory functions
void Calculator::memoryStore(double value) {
    memory = value;
}

string Calculator::memoryRecall() const {
    ostringstream oss;
    oss << fixed << setprecision(6);
    oss << memory;
    string str = oss.str();
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str.back() == '.') {
        str.pop_back();
    }
    return str.empty() ? "0" : str;
}

void Calculator::memoryClear() {
    memory = 0.0;
}

void Calculator::memoryAdd(double value) {
    memory += value;
}

void Calculator::memorySubtract(double value) {
    memory -= value;
}

// Utility function
bool Calculator::isError(const string& result) {
    return result == INF || result == ERROR;
}
