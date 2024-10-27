//
//  main.cpp
//  Project 2
//
//  Created by Joseph Braga
//

#include <iostream>
#include "BankAccount.hpp"
#include <vector>
#include <iomanip>

using namespace std;


void InitialDisplay() {
    cout << "*********************************************" << endl;
    cout << "********************DATA*********************" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " << endl;
    cout << "Number of Years: " << endl;
    
    cout << "Press any key to continue..." << endl;
    
    system("read");
}

void CalculateBalanceWithout(double InitialInvestment, double MonthlyDeposit, double AnnualInterest, int NumberYears, vector<double>& balances, vector<double>& interest) {
    
    double compoundMonthly;
    double YearEndBalanceWithout;
    double YearEarnedInterestWithout;
    
    YearEndBalanceWithout = InitialInvestment;
    
    for (int i = 1; i <= NumberYears; i++) {
        
        compoundMonthly = YearEndBalanceWithout * (AnnualInterest / 100) / 12;
        YearEarnedInterestWithout = compoundMonthly * 12;
        YearEndBalanceWithout = YearEndBalanceWithout + YearEarnedInterestWithout;
        
        balances.push_back(YearEndBalanceWithout);
        interest.push_back(YearEndBalanceWithout - InitialInvestment);
    }
}

void CalculateBalanceWith(double InitialInvestment, double MonthlyDeposit, double AnnualInterest, int NumberYears, vector<double>& balances, vector<double>& interest) {
    int i;
    int month;
    double compoundMonthly;
    
    double YearEndBalanceWith = InitialInvestment;
    
    for (i = 1; i <= NumberYears; i++) {
        for (month = 0; month < 12; month++) {
            YearEndBalanceWith = YearEndBalanceWith + MonthlyDeposit;
            compoundMonthly = YearEndBalanceWith * (AnnualInterest /100) / 12;
            YearEndBalanceWith = YearEndBalanceWith + compoundMonthly;
            
        }
        balances.push_back(YearEndBalanceWith);
        interest.push_back(YearEndBalanceWith - InitialInvestment - (MonthlyDeposit * 12 * i));
    }
}

void BalanceWithFormat(const vector<double>& balances, const vector<double>& interest) {
    cout << "          Balance and Interest With Additional Monthly Deposits         " << endl;
    cout << "========================================================================" << endl;
    cout << "  Year           Year End Balance               Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    
    for (size_t i = 0; i < balances.size(); i++) {
        cout << setw(5) << (i +1);
        cout << setw(30) << fixed << setprecision(2) << balances[i];
        cout << setw(30) << fixed << setprecision(2) << interest[i] << endl;
    }
    
}

void BalanceWithoutFormat(const vector<double>& balances, const vector<double>& interest) {
    cout << "        Balance and Interest Without Additional Monthly Deposits        " << endl;
    cout << "========================================================================" << endl;
    cout << "  Year           Year End Balance               Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    
    
    for (size_t i = 0; i < balances.size(); i++) {
        cout << setw(5) << (i +1);
        cout << setw(30) << fixed << setprecision(2) << balances[i];
        cout << setw(30) << fixed << setprecision(2) << interest[i] << endl;
    }
    
}

void GetUserInputs(BankingInfo& bankingInfo) {
    BankingInfo InitialInvestment, MonthlyDeposit, AnnualInterest, NumberYears;
    double Investment;
    double Deposit;
    double Interest;
    int Years;
    
    cout << "Please provide answers for the following instructions..." << endl;
    
    cout << endl;
    
    cout << "Enter your Initial Investment Amount: ";
    cin >> Investment;
    InitialInvestment.SetInvestment(Investment);
    
    cout << "Enter your Monthly Deposit: ";
    cin >> Deposit;
    MonthlyDeposit.SetDeposit(Deposit);
    
    cout << "Enter the asking Interest Rate ";
    cin >> Interest;
    AnnualInterest.SetInterest(Interest);
    
    cout << "Enter the number of years wanted: ";
    cin >> Years;
    NumberYears.SetYears(Years);
    
    cout << "Thank you for your input, one moment pleae..." << endl;
    
    cout << endl;
    
}


int main() {
    InitialDisplay();
    
    cout << endl;
    
    BankingInfo bankingInfo;
    GetUserInputs(bankingInfo);
    
    double initialInvestment = bankingInfo.GetInvestment();
    double monthlyDeposit = bankingInfo.GetDeposit();
    double annualInterest = bankingInfo.GetInterest();
    int numberYears = bankingInfo.GetYears();
    
    vector<double> noDepsoitBalances, noDepositInterest;
    vector<double> depositBalances, depositInterest;
    
    CalculateBalanceWith(initialInvestment, monthlyDeposit, annualInterest, numberYears, depositBalances, depositInterest);
    
    CalculateBalanceWithout(initialInvestment, monthlyDeposit, annualInterest, numberYears, noDepsoitBalances, noDepositInterest);
    
    BalanceWithoutFormat(noDepsoitBalances, noDepositInterest);
    
    cout << endl;
    
    BalanceWithFormat(depositBalances, depositInterest);
    
    
    
    
    cout << endl;
    cout << endl;
    
    
    return 0;
    
    
    
    
    
    
    
    
    
    
};
