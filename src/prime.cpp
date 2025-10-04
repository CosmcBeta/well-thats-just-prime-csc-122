#include "prime.hpp"
#include <vector>

std::vector<int> Factorizer::getPrimeFactors(int num)
{
    if (num <= 1)
    {
        return std::vector<int> {};
    }

    std:std::vector<int> factors;
    int i = 2;
    while (true)
    {
        if (num == 1)
        {
            break;
        }
        if (num == i)
        {
            factors.push_back(i);
            break;
        }
        if (num % i == 0)
        {
            factors.push_back(i);
            num /= i;
            i = 2;
        }
        else
        {
            i++;
        }
    }
    return factors;
}

bool Factorizer::isPrime(int num)
{
    return  num > 1 && getPrimeFactors(num).size() == 1;
}
