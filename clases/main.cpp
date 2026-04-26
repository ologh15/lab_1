#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

#include "character.h"
#include "item.h"
#include "enemy.h"
#include "Boss.h"
#include "Hero.h"
#include "Potion.h"
#include "IDisplay.h"


void showCharacterByReference(const Character& character) {
    character.showInfo();
    character.attack();
}

void showByInterface(const IDisplay& obj) {
    obj.display();
}




int readInt(const std::string& message) {
    int value;

    std::cout << message;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid number input.");
    }

    return value;
}

std::string readString(const std::string& message) {
    std::string value;

    std::cout << message;
    std::cin >> value;

    if (value.empty()) {
        throw std::runtime_error("Empty text input.");
    }

    return value;
}

void writeHistory(const std::string& action) {
    std::ofstream file("history.txt", std::ios::app);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open history file.");
    }

    file << action << std::endl;
}

void showHistory() {
    std::ifstream file("history.txt");

    if (!file.is_open()) {
        std::cout << "History is empty." << std::endl;
        return;
    }

    std::string line;
    std::cout << "\n--- User history ---" << std::endl;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}



int main() {
    try {


        writeHistory("Program started");
        showHistory();
    }
    catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    return 0;
}
