#include <iostream>

#include "InputHandler.h"

int InputHandler::getCompFreq() {
    int compFreq;
    while (true) {
        std::cout << "What is the compound frequency? (12 for monthly, 4 for quarterly, 2 for semiannually, 1 for yearly): ";
        std::cin >> compFreq;
        if (std::cin.fail() || (compFreq != 12 && compFreq != 4 && compFreq != 2 && compFreq != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 12, 4, 2, or 1." << std::endl;
        } else {
            return compFreq;
        }
    }
}

double InputHandler::getPrincipalAmount() {
    double A;
    while (true) {
        std::cout << "What is the amount of money that you have available to invest when starting?: ";
        std::cin >> A;
        if (std::cin.fail() || A <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        } else {
            return A;
        }
    }
}

double InputHandler::getMonthlyContribution() {
    double MonthlyCont;
    while (true) {
        std::cout << "What is the amount? (positive for contribution, negative for withdrawal): ";
        std::cin >> MonthlyCont;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        } else {
            return MonthlyCont;
        }
    }
}

double InputHandler::getAnnualInterestRate() {
    double annualInterestRate;
    while (true) {
        std::cout << "What is the Annual Interest Rate as decimal (e.g., 0.05 for 5%, 0.1 for 10%)?: ";
        std::cin >> annualInterestRate;
        if (std::cin.fail() || annualInterestRate <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive decimal value." << std::endl;
        } else {
            return annualInterestRate;
        }
    }
}

double InputHandler::getYears() {
    double years;
    while (true) {
        std::cout << "What is the length of time, in years, that you plan to save?: ";
        std::cin >> years;
        if (std::cin.fail() || years < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Amount of years can't be smaller than 0." << std::endl;
        } else {
            return years;
        }
    }
}

bool InputHandler::askForMonthlyContribution() {
    bool useMonthlyContribution;
    char input;
    while(true) {
        std::cout << "Do you plan to add or withdraw a fixed amount monthly? ('y' for yes, 'n' for no): ";
        std::cin >> input;

        if(input == 'y' || input == 'n') {
            useMonthlyContribution = (input == 'y');
            break;
        }
        else if(input != 'n') {
            std::cout << "Invalid input. Please input 'y' or 'n'" << std::endl;
        }
    }
    return useMonthlyContribution;
}