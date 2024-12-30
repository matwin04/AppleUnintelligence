#include "avr.h"
#include <iostream>

void displayMenu() {
    std::cout << "Denon AVR Control Menu\n";
    std::cout << "1. Power On\n";
    std::cout << "2. Power Standby\n";
    std::cout << "3. Volume Up\n";
    std::cout << "4. Volume Down\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::string port;
    port = "/dev/ttyUSB0";

    AVR avr(port);
    int choice = 0;

    while (choice != 5) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                avr.powerOn();
                break;
            case 2:
                avr.powerOff();
                break;
            case 3:
                avr.mvUp();
                break;
            case 4:
                avr.mvDown();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}