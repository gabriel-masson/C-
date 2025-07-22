#include <iostream>
#include <string>
#include <vector>
#include <iterator>

int main() {
    std::string str = "Hello, World!";
    
    // Output the string
    std::cout << str << std::endl;

    // Find the length of the string
    std::cout << "Length of the string: " << str.length() << std::endl;

    // Accessing characters in the string
    for (size_t i = 0; i < str.length(); ++i) {
        std::cout << "Character at index " << i << ": " << str[i] << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    // Concatenating strings
    using namespace std::string_literals;
    auto anotherStr = " How are you?"s;
    std::string combinedStr = str + anotherStr;
    std::cout << "Combined string: " << combinedStr << std::endl;
    
    std::cout << "-------------------------------------------" << std::endl;
    // Finding a substring
    std::string toFind = "World";
    size_t pos = str.find(toFind);
    if (pos != std::string::npos) {
        std::cout << "Found substring '" << toFind << "' at position: " << pos << std::endl;
    } else {
        std::cout << "Substring '" << toFind << "' not found." << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    // Replacing a substring
    std::string toReplace = "World";
    std::string replacement = "C++";
    size_t replacePos = str.find(toReplace);

    if (replacePos != std::string::npos) {
        str.replace(replacePos, toReplace.length(), replacement);
        std::cout << "String after replacement: " << str << std::endl;
    } else {
        std::cout << "Substring '" << toReplace << "' not found for replacement." << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    std::string num = "12";
    std::string num2 = "34";
    std::string result = num + num2;
    std::cout << "Concatenated numbers as strings: " << result << std::endl;
    int soma = std::stoi(num) + std::stoi(num2);
    std::cout << "Sum of numbers: " << soma << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    // comparing strings
    std::string str1 = "BAnana";
    std::string str2 = "banana";

    str1.compare(str2) == 0 ? std::cout << "Strings are equal" << std::endl : std::cout << "Strings are not equal" << std::endl;
    if (str1 < str2) {
        std::cout << str1 << " is less than " << str2 << std::endl;
    } else if (str1 > str2) {
        std::cout << str1 << " is greater than " << str2 << std::endl;
    } else {
        std::cout << str1 << " is equal to " << str2 << std::endl;
    }



    return 0;
}