#include <iostream>
#include <algorithm>

bool isPalindrome(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isalnum(c); }), str.end());
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome.\n";   

    } else {
        std::cout << "\"" << input << "\" is not a palindrome.\n";
    }

    return 0;
}