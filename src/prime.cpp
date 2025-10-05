#include "prime.hpp"

#include <cstdlib>
#include <string>
#include <vector>

std::vector<int> Factorizer::primeFactors(int num)
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
    return  num > 1 && primeFactors(num).size() == 1;
}

std::string Factorizer::reduce(int numerator, int denominator)
{
    if (numerator == 0)
    {
        return "0";
    }
    if (denominator == 0)
    {
        return "UNDEFINED";
    }

    std::vector<int> numeratorPrimeFactors = primeFactors(abs(numerator));
    std::vector<int> denominatorPrimeFactors = primeFactors(abs(denominator));

    int n = 0;
    int d = 0;
    while (n < numeratorPrimeFactors.size() && d < denominatorPrimeFactors.size())
    {
        int numer = numeratorPrimeFactors[n];
        int denom = denominatorPrimeFactors[d];
        if (numer == denom)
        {
            numerator /= numer;
            denominator /= numer;
            n++;
            d++;
        }
        else if (numer > denom)
        {
            d++;
        }
        else if (numer < denom)
        {
            n++;
        }
    }

    if (numerator % denominator == 0)
    {
        return std::to_string(numerator / denominator);
    }
    else
    {
        std::string sign = "";
        if ((numerator < 0) != (denominator < 0))
        {
            sign = "-";
        }
        return sign + std::to_string(abs(numerator)) + "/" + std::to_string(abs(denominator));
    }
}
