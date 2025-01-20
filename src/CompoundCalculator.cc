#include "CompoundCalculator.h"
#include <cmath>

CompoundCalculator::CompoundCalculator(double p, double r, int f, double t, double c, bool useContribution)
    : principal(p), annualRate(r), compoundFreq(f), years(t), monthlyContribution(c), useMonthlyContribution(useContribution) {};


double CompoundCalculator::calculateInterest() const {
    double nxt = compoundFreq * years;
    double rDivn = annualRate / compoundFreq;
    double amount = principal * std::pow(1 + rDivn, nxt);

    if(useMonthlyContribution) {
        amount += (monthlyContribution * ((std::pow(1 + rDivn, nxt) - 1) / rDivn));
    }
    return amount;
}