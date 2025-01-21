#include "CompoundCalculator.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>

CompoundCalculator::CompoundCalculator(double p, double r, int f, double t, double c, bool useContribution)
    : principal(p), annualRate(r), compoundFreq(f), years(t), monthlyContribution(c), useMonthlyContribution(useContribution) {};

void CompoundCalculator::plotInvestment() {
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Investment Growth Over Time'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time Periods'\n");
        fprintf(gnuplotPipe, "set ylabel 'Investment Value'\n");
        fprintf(gnuplotPipe, "plot '-' using 1:2 with lines title 'Growth'\n");

        double amount = principal;
        for (int i = 0; i <= years * compoundFreq; i++) {
            if (useMonthlyContribution && i % (compoundFreq / 12) == 0) {
                amount += monthlyContribution;
            }
            amount *= (1 + annualRate / compoundFreq);
            fprintf(gnuplotPipe, "%d %f\n", i, amount);
        }

        fprintf(gnuplotPipe, "e\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
    } else {
        std::cout << "Error: Could not open GNUplot.\n";
    }
}

void CompoundCalculator::printInfo() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << " + intitial amount was: $" << this->getPrincipal() << std::endl;
    std::cout << " + monthly contribution was: $" << this->getMonthlyContribution() << std::endl;
    std::cout << " + interest rate was: " << std::setprecision(0) << (this->getAnnualRate() * 100) << "%" << std::endl;
    std::cout << " + compound rate per year was: " << std::setprecision(0) << this->getCompoundFreq() << " time(s)" << std::endl;
    std::cout << " + length of the investment in years: " << std::setprecision(0) << this->getYears() << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void CompoundCalculator::compareScenarios(CompoundCalculator &scenario1, CompoundCalculator &scenario2) {
    double amount1 = scenario1.calculateInterest();
    double amount2 = scenario2.calculateInterest();

    std::cout << std::endl << "Scenario 1 info: " << std::endl;
    scenario1.printInfo();
    std::cout << "The final amount is: $" << std::setprecision(2) << amount1 << std::endl << std::endl;
    std::cout << "Scenario 2 info: " << std::endl;
    scenario2.printInfo();
    std::cout << "The final amount is: $" << std::setprecision(2) << amount2 << std::endl << std::endl;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "When comparing the two final amounts, ";

    if (amount1 < amount2) {
        std::cout << "scenario 2 resulted in an increase of $" << (amount2 - amount1)
                  << " compared to scenario 1." << std::endl;
    } else if (amount1 > amount2) {
        std::cout << "scenario 1 resulted in an increase of $" << (amount1 - amount2)
                  << " compared to scenario 2." << std::endl;
    } else {
        std::cout << "both scenarios resulted in the same final amount of $" << amount1 << "." << std::endl;
    }
}

double CompoundCalculator::calculateInterest() const {
    double nxt = compoundFreq * years;
    double rDivn = annualRate / compoundFreq;
    double amount = principal * std::pow(1 + rDivn, nxt);

    if(useMonthlyContribution) {
        amount += (monthlyContribution * ((std::pow(1 + (annualRate / 12), (12 * years)) - 1) / (annualRate / 12)));
    }
    return amount;
}


double CompoundCalculator::calculateContribution() const {
    return (principal + (12 * monthlyContribution * years));
}