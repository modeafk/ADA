#include <iostream>

// Define the operations
float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cerr << "Error: Division by zero!\n";
        return 0; // Handle division by zero
    }
}

// Code B
// User type to simplify the declaration
typedef float (*lpfnOperation)(float, float);

// CVector of pointer to functions
lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };

int main() {
    float a, b, c;
    int opt;

    // Enter the operands
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    // Enter the operation: 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
    std::cout << "Enter operation (0 for Addition, 1 for Subtraction, 2 for Multiplication, 3 for Division): ";
    std::cin >> opt;

    // Check for valid operation index
    if (opt < 0 || opt > 3) {
        std::cerr << "Error: Invalid operation index!\n";
        return 1; // Exit with error code
    }

    // Use the function pointer array to call the appropriate function
    c = (*vpf[opt])(a, b);

    // Output the result
    std::cout << "Result: " << c << "\n";

    return 0;
}
