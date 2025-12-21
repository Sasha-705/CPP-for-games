#include <iostream>
#include <limits>

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    unsigned int n;

    std::cout << "Write a natural number: ";
    std::cin >> n;

    while (std::cin.fail())
    {
        clearInput();
        std::cout << "Write a valid input: ";
        std::cin >> n;
    }

    // Handle 0 and 1 explicitly
    if (n <= 1)
    {
        std::cout << "The number " << n << " is not prime\n";
        return 0;
    }

    bool isPrime = true;

    // Check divisors only up to sqrt(n)
    for (unsigned int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break; // no need to continue
        }
    }

    if (isPrime)
        std::cout << "The number " << n << " is prime\n";
    else
        std::cout << "The number " << n << " is not prime\n";

    return 0;
}
