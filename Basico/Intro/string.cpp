#include <iostream>
#include <cstring>

int main() {
    char name[] = "a";
    char name2[] = "b";

    int result = strcmp(name, name2); // Compare the two strings
    if (result == 0) {
        std::cout << "The strings are equal." << std::endl;
    } else if (result < 0) {
        std::cout << "The first string is less than the second string." << std::endl;
    } else {
        std::cout << "The first string is greater than the second string." << std::endl;
    }

    return 0;
}