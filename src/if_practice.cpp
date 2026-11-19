#include <iostream>

int main()
{
    std::cout << "Enter a number 0-9\n";
    int x {};
    std::cin >> x;
    if (x == 2 || x== 3 || x == 5 || x == 7)
        std::cout << "Digit is prime";
    else
        std::cout << "Digit is not prime";

    return 0;

}