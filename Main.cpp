#include <iostream>
#include <iomanip>
using namespace std;

//imports header file
#include "AirgeadBankingApp.h"


//creates two objects
AirgeadBanking investWithoutDeposit;
AirgeadBanking investWithDeposit;


//defines variables
double initialInvestment;
double monthlyDeposit;
double annualInterest;
int numberOfYears;


//defines user input function
static void userInput()
{
	//defines boolean variable
	bool noError = true;
	
	//outputs text
	cout << setfill('*') << setw(30) << endl;
	cout << "********** Data Input *********" << endl;
	
	//while loop to restart function on runtime error
	while (noError)
	{
		// try/catch to recieve user input and verify the numbers being positive
		try
		{
			//initial investment input
			cout << "Initial Investment Amount: ";
			cin >> initialInvestment;
			cout << endl;
			cin.ignore();
			if (initialInvestment < 0.0)
			{
				throw runtime_error("Positive numbers only");
				noError = false;
			}

			//monthly deposit input
			cout << "Monthly Deposit: ";
			cin >> monthlyDeposit;
			cout << endl;
			cin.ignore();
			if (monthlyDeposit < 0.0)
			{
				throw runtime_error("Positive numbers only");
				noError = false;
			}

			//annual interest input
			cout << "Annual Interest: ";
			cin >> annualInterest;
			cout << endl;
			cin.ignore();
			if (annualInterest < 0.0)
			{
				throw runtime_error("Positive numbers only");
				noError = false;
			}

			//number of years input
			cout << "Number of Years: ";
			cin >> numberOfYears;
			cout << endl;
			cin.ignore();
			if (numberOfYears < 0.0)
			{
				throw runtime_error("Positive numbers only");
				noError = false;
			}
			else
			{
				break;
			}

		}
		catch (const exception& e)
		{
			cout << "Error " << e.what() << endl;
			noError = true;
		}
	}
	
}

//main function
int main() 
{
	//calls user input function
	userInput();

	//sets variables to without deposit object
	investWithoutDeposit.setInititalInvestment(initialInvestment);
	investWithoutDeposit.setAnnualInterest(annualInterest);
	investWithoutDeposit.setNumberYears(numberOfYears);

	//sets variables to with deposit object
	investWithDeposit.setInititalInvestment(initialInvestment);
	investWithDeposit.setMonthlyDeposit(monthlyDeposit);
	investWithDeposit.setAnnualInterest(annualInterest);
	investWithDeposit.setNumberYears(numberOfYears);

	//output prompts user for input to continue
	cout << "Press Enter to continue...";
	
	// detects user input and outputs banking information
	if (getchar())
	{
		cout << "Balances and Interest Without a Monthly Deposit" << endl;
		cout << endl;
		cout << "Year    Year End Amount    Year End Interest Amount" << endl;
		cout << endl;
		investWithoutDeposit.withoutDeposit(investWithoutDeposit.getNumberYears(),
			investWithoutDeposit.getInititalInvestment(), investWithoutDeposit.getAnnualInterest());
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "Balances and Interest With a Monthly Deposit" << endl;
		cout << endl;
		cout << "Year    Year End Amount    Year End Interest Amount" << endl;
		cout << endl;
		investWithDeposit.withDeposit(investWithDeposit.getNumberYears(), investWithDeposit.getMonthlyDeposit(),
			investWithDeposit.getInititalInvestment(), investWithDeposit.getAnnualInterest());
		cout << endl;
		cout << endl;
		cout << endl;
	}
	return 0;
}