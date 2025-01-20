#include <iostream>
#include <iomanip>

#include "InputHandler.h"   
#include "CompoundCalculator.h"

using namespace std;

void compoundMenu() {
    cout << endl;
    while(true) {
        cout << "Make a choice based to for functionality:" << endl;
        cout << "- 1. Calculate Interst and display graph" << endl;
        cout << "- 2. Exit" << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        if(choice == 1) {
            double principal = InputHandler::getPrincipalAmount();
            double rate = InputHandler::getAnnualInterestRate();
            int freq = InputHandler::getCompFreq();
            double years = InputHandler::getYears();
            bool useMonthly = InputHandler::askForMonthlyContribution();
            double contribution = useMonthly ? InputHandler::getMonthlyContribution() : 0.0;

            CompoundCalculator calculator(principal, rate, freq, years, contribution, useMonthly);
            double result = calculator.calculateInterest();
            double totalContributions = calculator.calculateContribution();

            cout << endl << "The future value will be: " << fixed << setprecision(2) << result << endl;
            cout << "Total Contributions: " << fixed << setprecision(2) << totalContributions << endl << endl;

            calculator.plotInvestment();
        }
        else if(choice == 2) {
            break;
        }
    }
}

void menu() {
    cout << "__Finance Calculators__" << endl;
    while(true) {
        cout << "Make a choice based on the needed calculator:" << endl;
        cout << "- 1. Compount Interst Calculator" << endl;
        cout << "- 2. Exit" << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        if(choice == 1) {
            compoundMenu();
        }
        else if(choice == 2) {
            break;
        }
    }
}

int main() {
    menu();
    return 0;
}