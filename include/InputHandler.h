#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

class InputHandler {
public:
    static double getPrincipalAmount();
    static double getMonthlyContribution();
    static double getAnnualInterestRate();
    static double getYears();
    static int getCompFreq();
    static bool askForMonthlyContribution();
};


#endif // INPUT_HANDLER_H