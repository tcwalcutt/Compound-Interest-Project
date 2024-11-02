/*
Thomas Walcutt
*/


//defines header
#ifndef AIRGEADBANKINGAPP_H
#define AIRGEADBANKINGAPP_H


//creates class AirgeadBanking
class AirgeadBanking
{
//declares public variables
public:
	void setInititalInvestment(double t_amount);
	void setMonthlyDeposit(double t_deposit);
	void setAnnualInterest(double t_interest);
	void setNumberYears(int t_years);

	double getInititalInvestment()const;
	double getMonthlyDeposit() const;
	double getAnnualInterest() const;
	int getNumberYears() const;

	
	void printDetails(int year, double amount, double interest);
	double withoutDeposit(int year, double balance, double interest);
	double withDeposit(int year, double deposit, double balance, double interest);
//delcares private variables
private:
	double m_amount;
	double m_deposit;
	double m_interest;
	int m_years;
};


#endif