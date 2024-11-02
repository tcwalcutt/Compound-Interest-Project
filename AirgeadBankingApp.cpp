#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


//imports header
#include "AirgeadBankingApp.h"

//defines set functions
void AirgeadBanking::setInititalInvestment(double t_amount)
{
	m_amount = t_amount;
}
void AirgeadBanking::setMonthlyDeposit(double t_deposit)
{
	m_deposit = t_deposit;
}
void AirgeadBanking::setAnnualInterest(double t_interest)
{
	m_interest = t_interest;
}
void AirgeadBanking::setNumberYears(int t_years)
{
	m_years = t_years;
}

//defines get functions
double AirgeadBanking::getInititalInvestment()const 
{
	return m_amount;
}
double AirgeadBanking::getMonthlyDeposit() const
{
	return m_deposit;
}
double AirgeadBanking::getAnnualInterest() const
{
	return m_interest;
}
int AirgeadBanking::getNumberYears() const
{
	return m_years;
}


//defines print details function
void AirgeadBanking::printDetails(int year, double amount, double interest) 
{
	cout << endl;
	cout << year << "       $";
	cout <<  fixed << setprecision(2) << amount;
	cout << "              $";
	cout << fixed << setprecision(2) << interest << endl;
}


//defines withoutDeposit function
double AirgeadBanking::withoutDeposit(int year, double balance, double interest)
{
	//defines variables
	double newInterestAmount = (interest / 100) / 12;
	double principalInterest = 0;
	double totalInterest = 0;
	double principalTotal = balance;
	double basePrincipal = balance;
	int i;

	// loops through each month
	for (i = 1; i <= year * 12; ++i)
	{
		basePrincipal = principalTotal;
		principalInterest = basePrincipal * newInterestAmount;
		totalInterest += principalInterest;
		principalTotal = basePrincipal + principalInterest;
		
		//executes each year
		if (i % 12 == 0)
		{
			printDetails((i / 12), principalTotal, totalInterest);
			totalInterest = 0;

		}
		
	}
	return principalTotal;
}

//defines with deposit function
double AirgeadBanking::withDeposit(int year, double deposit, double balance, double interest)
{
	//defines variables
	double newInterestAmount = (interest/100)/12;
	double principalInterest = 0;
	double totalInterest = 0;
	double principalTotal = balance;
	double basePrincipal = balance;
	int i;

	//loops through each month
	for (i = 1; i <= year * 12; ++i)
	{
		basePrincipal = principalTotal;
		principalInterest = basePrincipal * newInterestAmount;
		totalInterest += principalInterest;
		principalTotal = basePrincipal + principalInterest + deposit;
		
		//executes each year
		if (i % 12 == 0)
		{
			printDetails((i / 12), principalTotal, totalInterest);
			totalInterest = 0;
		
		}

	}
	return principalTotal;
	
}

