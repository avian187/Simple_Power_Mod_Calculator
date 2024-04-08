// Simple Power-Mod Calculator for HW 08

#include <iostream>
using namespace std;

int main() {
    int base, exponent, mod;
    char another;
    do {
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the exponent: ";
        cin >> exponent;
        cout << "Enter the mod: ";
        cin >> mod;
        // Factor the exponent into a sum of powers of 2
        int powers[100];
        int i = 0;
        while (exponent > 0) {
            powers[i] = exponent % 2;
            exponent /= 2;
            i++;
        }
        // Calculate the power mod of the base to the power of 2^i mod the mod
        int M[100];
        M[0] = base;
        for (int j = 1; j < i; j++) {
            M[j] = (M[j - 1] * M[j - 1]) % mod;
        }
        // Multiply the appropriate M values to get the final answer
        int result = 1;
        for (int j = 0; j < i; j++) {
            if (powers[j] == 1) {
                result = (result * M[j]) % mod;
            }
        }
        std::cout << "The result is: " << result << std::endl;
        cout << "Would you like to enter another base, exponent, and mod? (y/n): ";
        cin >> another;
    } while (another == 'y');
    return 0;
}
