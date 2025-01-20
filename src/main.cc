#include <iostream>
#include <iomanip>

#include "InputHandler.h"   
#include "CompoundCalculator.h"

using namespace std;

void menu() {
    cout << "__Finance Calculators__" << endl;
    while(true) {
        cout << "Make a choice based on the needed calculator:" << endl;
        cout << "1. Compount Interst Calculator" << endl;
        cout << "2. Exit" << endl;

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

            cout << endl << "The final amount will be: " << fixed << setprecision(2) << result << endl << endl;
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