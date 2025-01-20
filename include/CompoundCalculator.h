#ifndef COMPOUND_CALCULATOR_H
#define COMPOUND_CALCULATOR_H

class CompoundCalculator {
private:
    double principal;
    double annualRate;
    int compoundFreq;
    double years;
    double monthlyContribution;
    bool useMonthlyContribution;

public:
    CompoundCalculator(double principal, double rate, int freq, double time, double contribution, bool useContribution);

    double calculateInterest() const;

};

#endif // COMPOUND_CALCULATOR_H