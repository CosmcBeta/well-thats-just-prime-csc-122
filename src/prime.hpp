#include <string>
#include <vector>

class Factorizer
{
public:
    std::vector<int> primeFactors(int num);
    bool isPrime(int num);
    std::string reduce(int numerator, int denominator);
};
