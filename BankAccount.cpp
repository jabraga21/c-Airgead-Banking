//
//  BankAccount.cpp
//  Project 2
//
//  Created by Joseph Braga
//
#include <iostream>
#include "BankAccount.hpp"

using namespace std;

BankingInfo::BankingInfo() {
    InitialInvestment = 0.0;
    MonthlyDesposit = 0.0;
    AnnualInterest = 0.0;
    NumberYears = 0;
}

//functions for setters
void BankingInfo::SetInvestment(double Investment) {
    InitialInvestment = Investment;
}
void BankingInfo::SetDeposit(double Deposit) {
    MonthlyDesposit = Deposit;
}
void BankingInfo::SetInterest(double Interest) {
    AnnualInterest = Interest;
}
void BankingInfo::SetYears(int Years) {
    NumberYears = Years;
}

//functions for getters
double BankingInfo::GetInvestment() {
    return InitialInvestment;
}
double BankingInfo::GetDeposit() {
    return MonthlyDesposit;
}
double BankingInfo::GetInterest() {
    return AnnualInterest;
}
int BankingInfo::GetYears() {
    return NumberYears;
}


