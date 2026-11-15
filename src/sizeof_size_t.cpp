#include <iostream>
#include <cstddef>

int main ()
{
    int x { 1238631 };
    std::cout << sizeof(x) << "\n";

    std::size_t s { sizeof(int) };
    std::cout << s << '\n';

    std::cout << sizeof(std::size_t) << "\n";

    short int y { 12 };
    std::cout << sizeof(y) << "\n";

    return 0;
} 