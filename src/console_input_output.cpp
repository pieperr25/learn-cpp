#include <iostream>

int main()
{
    std::cout << "Enter a number: ";

    int x{};
    std::cin >> x;
    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;
    std::cout << "Enter another number: ";
    int z{};
    std::cin >> z;

    std::cout << "You entered " << x << ", " << y << ", and " << z ;
    return 0;
}