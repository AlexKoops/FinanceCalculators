#include <iostream>
#include <iomanip>

#include "Compound.h"

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
            double amount = 0;
            amount = returnInterestOnInput();
            cout << "The return amount will be: " << setprecision(2) << amount << endl << endl;
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