#include <iostream>

int double_number(int num)
{
    return num * 2;
}



int main()
{
    int x {};
    std::cout << "Enter a number\n";
    std::cin >> x;
    std::cout << "Double that number is " << double_number(x);
    return 0;
}