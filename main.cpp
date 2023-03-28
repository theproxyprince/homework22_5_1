#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>

bool isNumber(const std::string& word) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] != '-' && word[i] < '0' && word[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isSurname(const std::string& word) {
    for (int i = 0; i < word.length(); ++i) {
        if (!std::isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

void add(std::map<std::string, std::string>& phoneDirectory, const std::string& number, const std::string& surname) {
    phoneDirectory[number] = surname;
}

void getSurnameByNumber(const std::map<std::string, std::string>& phoneDirectory, const std::string& number) {
    if (phoneDirectory.count(number) > 0) {
        std::cout << phoneDirectory.at(number) << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }
}

void getNumbersBySurname(const std::map<std::string, std::string>& phoneDirectory, const std::string& surname) {
    bool found = false;
    for (auto it = phoneDirectory.begin(); it != phoneDirectory.end(); ++it) {
        if (surname == it->second) {
            std::cout << it->first << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Not found!" << std::endl;
    } else {
        std::cout << std::endl;
    }
}

int main() {
    std::stringstream input;
    std::string line, number, surname;
    std::map<std::string, std::string> phoneDirectory;

    while (true) {
        std::cout << "Input formats:\n1. Number Surname\n2. Number\n3. Surname\n";
        std::getline(std::cin, line);
        input.clear();
        input.str(line);

        if (input >> number >> surname) {
            add(phoneDirectory, number, surname);
        } else if (isNumber(line)) {
            getSurnameByNumber(phoneDirectory, line);
        } else if (isSurname(line)) {
            getNumbersBySurname(phoneDirectory, line);
        } else {
            std::cout << "Invalid input!" << std::endl;
        }
    }

    return 0;
}
