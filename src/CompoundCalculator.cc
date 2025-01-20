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


double CompoundCalculator::calculateInterest() const {
    double nxt = compoundFreq * years;
    double rDivn = annualRate / compoundFreq;
    double amount = principal * std::pow(1 + rDivn, nxt);

    if(useMonthlyContribution) {
        amount += (monthlyContribution * ((std::pow(1 + rDivn, nxt) - 1) / rDivn));
    }
    return amount;
}

double CompoundCalculator::calculateContribution() const {
    return (12 * monthlyContribution * years);
}