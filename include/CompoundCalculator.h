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

    void plotInvestment();
    static void compareScenarios(CompoundCalculator &scenario1, CompoundCalculator &scenario2);
    void printInfo();

    double calculateInterest() const;
    double calculateContribution() const;

    /*------------------------------------------------------------------------------------------------------------------*/
    
    // Getters
    double getPrincipal() const {
        return principal;
    }

    double getAnnualRate() const {
        return annualRate;
    }

    int getCompoundFreq() const {
        return compoundFreq;
    }

    double getYears() const {
        return years;
    }

    double getMonthlyContribution() const {
        return monthlyContribution;
    }

    bool isUsingMonthlyContribution() const {
        return useMonthlyContribution;
    }

};

#endif // COMPOUND_CALCULATOR_H