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
        cout << "- 2. Compare 2 scenarios" << endl;
        cout << "- 3. Exit" << endl;
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

            calculator.printInfo();
            cout << endl << "The future balance will be: " << fixed << setprecision(2) << result << endl;
            cout << "Total principal: " << fixed << setprecision(2) << totalContributions << endl;
            cout << "Total interest: " << fixed << setprecision(2) << (result - totalContributions) << endl << endl;

            calculator.plotInvestment();
        }
        else if(choice == 2) {
            cout << "You will first be prompted to input the info for scenario 1 then scenario 2." << endl << endl;
            cout << "Input info for scenario 1: " << endl;
            double principal1 = InputHandler::getPrincipalAmount();
            double rate1 = InputHandler::getAnnualInterestRate();
            int freq1 = InputHandler::getCompFreq();
            double years1 = InputHandler::getYears();
            bool useMonthly1 = InputHandler::askForMonthlyContribution();
            double contribution1 = useMonthly1 ? InputHandler::getMonthlyContribution() : 0.0;
            CompoundCalculator calculator1(principal1, rate1, freq1, years1, contribution1, useMonthly1);

            cout << endl << "Input info for scenario 2: " << endl;
            double principal2 = InputHandler::getPrincipalAmount();
            double rate2 = InputHandler::getAnnualInterestRate();
            int freq2 = InputHandler::getCompFreq();
            double years2 = InputHandler::getYears();
            bool useMonthly2 = InputHandler::askForMonthlyContribution();
            double contribution2 = useMonthly2 ? InputHandler::getMonthlyContribution() : 0.0;

            CompoundCalculator calculator2(principal2, rate2, freq2, years2, contribution2, useMonthly2);

            CompoundCalculator::compareScenarios(calculator1, calculator2);
            cout << endl;
        }
        else if(choice == 3) {
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