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

void saveItems(const std::vector<Item>& items) {
    std::ofstream file("items.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open items file for saving.");
    }

    for (const Item& item : items) {
        file << item << std::endl;
    }
}

void loadItems(std::vector<Item>& items) {
    std::ifstream file("items.txt");

    if (!file.is_open()) {
        return;
    }

    Item item;

    while (file >> item) {
        items.push_back(item);
    }
}

void showItems(const std::vector<Item>& items) {
    if (items.empty()) {
        std::cout << "No items available." << std::endl;
        return;
    }

    std::cout << "\n--- Items ---" << std::endl;

    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". ";
        items[i].showInfo();
    }
}

void addItem(std::vector<Item>& items) {
    std::string name = readString("Enter item name: ");
    int power = readInt("Enter item power: ");

    if (power < 0) {
        throw std::runtime_error("Item power cannot be negative.");
    }

    items.push_back(Item(name, power));
    saveItems(items);
    writeHistory("Admin added item: " + name);

    std::cout << "Item added successfully." << std::endl;
}

bool adminLogin() {
    const std::string password = "admin123";

    std::string inputPassword = readString("Enter admin password: ");

    if (inputPassword == password) {
        std::cout << "Admin login successful." << std::endl;
        writeHistory("Admin logged in");
        return true;
    }

    std::cout << "Wrong password." << std::endl;
    writeHistory("Failed admin login");
    return false;
}

void adminMenu(std::vector<Item>& items) {
    int choice;

    do {
        std::cout << "\n--- Admin menu ---" << std::endl;
        std::cout << "1. Add item" << std::endl;
        std::cout << "2. Show items" << std::endl;
        std::cout << "3. Show history" << std::endl;
        std::cout << "0. Back" << std::endl;

        choice = readInt("Choose option: ");

        switch (choice) {
            case 1:
                addItem(items);
                break;

            case 2:
                showItems(items);
                writeHistory("Admin viewed items");
                break;

            case 3:
                showHistory();
                break;

            case 0:
                std::cout << "Back to main menu." << std::endl;
                break;

            default:
                std::cout << "Unknown option." << std::endl;
                break;
        }
    } while (choice != 0);
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
