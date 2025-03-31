#include "calco.h"
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

// Basic arithmetic operations with string returns
string Calco::add(double a, double b) {
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

string Calco::subtract(double a, double b) {
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

string Calco::multiply(double a, double b) {
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

string Calco::divide(double a, double b) {
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
string Calco::power(double base, double exponent) {
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

string Calco::squareRoot(double value) {
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

string Calco::modulus(double a, double b) {
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
void Calco::memoryStore(double value) {
    memory = value;
}

string Calco::memoryRecall() const {
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

void Calco::memoryClear() {
    memory = 0.0;
}

void Calco::memoryAdd(double value) {
    memory += value;
}

void Calco::memorySubtract(double value) {
    memory -= value;
}

// Utility function
bool Calco::isError(const string& result) {
    return result == INF || result == ERROR;
}
