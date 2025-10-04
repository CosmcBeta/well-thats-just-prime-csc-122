#include "src/prime.hpp"
#include <iostream>

int main() {
    Factorizer factorizer;

    std::cout << "Enter a number and I will calculate the prime factors of said number: ";
    int num;
    std::cin >> num;
    std::cout << "The prime factors of " << num << " are: \n";
    for (int f : factorizer.getPrimeFactors(num))
    {
        std::cout << f << "\n";
    }
    std::cout << std::endl;
}
