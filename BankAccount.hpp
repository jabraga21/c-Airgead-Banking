//
//  BankAccount.hpp
//  Project 2
//
//  Created by Joseph Braga
//

#ifndef BankAccount_hpp
#define BankAccount_hpp
#include <string>
#include <stdio.h>
using namespace std;


class BankingInfo {
public:
    
    BankingInfo();
    //setters
    void SetInvestment(double Investment);
    void SetDeposit(double Deposit);
    void SetInterest(double Interest);
    void SetYears(int Years);
    //getters
    double GetInvestment();
    double GetDeposit();
    double GetInterest();
    int GetYears();
    
private:
    
    double InitialInvestment;
    double MonthlyDesposit;
    double AnnualInterest;
    int NumberYears;
};




#endif /* BankAccount_hpp */
