#include <iostream>
#include <stdexcept>
#include <cmath>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) {
    std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

int getCompFreq() {
    int compFreq;
    std::cout << "What is the compound frequency? (12 for monthly, 4 for quarterly, 2 for semiannualy, 1 for yearly): ";
    std::cin >> compFreq;
    return compFreq;
}

double getPrincipalAmount() {
    int A;
    std::cout << "What is the amount of money that you have available to invest when starting?: ";
    std::cin >> A;
    return A;
}

double getMonthlyContibution() {
    double MonthlyCont = 0;
    std::cout << "What is the amount? (positive for contribution, negative for withdraw): ";
    std::cin >> MonthlyCont;
    return MonthlyCont;
}

double getAnualInterestRate() {
    double anualIntrestRate;
    std::cout << "What is the Annual Interest Rate as decimal (e.g., 0.05, 0.1?: ";
    std::cin >> anualIntrestRate;
    return anualIntrestRate;

}

double getYears() {
    try {
        double years;
        std::cout << "What is the length of time, in years, that you plan to save?: ";
        std:: cin >> years;

        if(years < 0) {
            throw std::invalid_argument("Amount of years can't be smaller than 0");
        }
        else {
            return years;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

double calculateInterest(double initialAmount, double annualInterest, int compoundFrequency, double timeInYears, double montlyAmount, bool montlyContribution) {
    double nxt = compoundFrequency * timeInYears;
    double rDivn = annualInterest / compoundFrequency;

    double amount = initialAmount * std::pow(1 + rDivn, nxt);
    if(montlyContribution) {
        amount += montlyAmount * (std::pow(1 + rDivn, nxt) - 1) / rDivn;
    }
    return amount;
}

double returnInterestOnInput() {
    double initialAmount = getPrincipalAmount();
    bool monthlyContribution = false;
    char input;
    while(true) {
        std::cout << "Do you plan to add or withdraw a fixed amount monthly? ('y' for yes, 'n' for no)";
        std::cin >> input;

        if(input == 'y' || input == 'n') {
            monthlyContribution = (input == 'y');
            break;
        }
        else if(input != 'n') {
            std::cout << "Invalid input. Please input 'y' or 'n'" << std::endl;
        }
    }
    double montlyAmount = 0;
    if(monthlyContribution) {
        montlyAmount = getMonthlyContibution();
    }
    double years = getYears();
    double annualInterest = getAnualInterestRate();
    int compoundFrequency = getCompFreq();

    double amount = calculateInterest(initialAmount, annualInterest, compoundFrequency, years, montlyAmount, monthlyContribution);
    return amount;
}