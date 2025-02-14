/* Loan Amortization Program

File Name: LabOne_Recursion_WilsonJ.cpp
This program calculates the monthly payment for a loan
and produces an amortization schedule


Created by: Judah T. Wilson
Created Date: 08/22/2024
Modified by: 09/05/2024
*/
#include <iostream>
#include <iomanip>

using namespace std;

// Functions
void getVars(double& t, double& i, int& l, double& payment, double& balance);

int Amortize(int& months, double& payment, double& t, double& interest, double& balance, int& l, double& i);


int main()
{

	// Varaiables in the lab
	double t = 0; //Loan (t)otal
	double i = 0; //Rate of (i)nterest
	double payment = 0; //Monthly payments 
	double interest = 0; //Interest
	double balance = 0; //Lefover balance

	int l = 0; //(l)oan payment period
	int months = 1; //Period of time to pay loan (only given a 5, 10, 15 year time frame)

	getVars(t, i, l, payment, balance);

	// This will serve as the heading for the information printed
	cout << left << setw(14) << "Payment" << setw(12) << "Ammount" << setw(13) << "Interest" << setw(14) << "Principle" << "Balance" << endl << endl;

	cout << right << setw(60) << balance << endl;;

	Amortize(months, payment, t, interest, balance, l, i);


	system("pause");
	return 0;
}

//Function gets variable input from user; interest rate, how long the loan is for, and displays the principle.
void getVars(double& t, double& i, int& l, double& payment, double& balance) {


	cout << endl << "Enter the loan amount:	 ";
	cin >> t;

	while (t <= 0) { // Checks for error
		cout << endl << "!Error! Enter in a positive integer:  ";

		cin.clear(); // Clears the error
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove any and all excess characters

		cin >> t; // Puts input variable back in

	}

	cout << endl << "What is the interest rate:  ";
	cin >> i;

	while (i <= 0) // Checks for error
	{
		cout << endl << "!Error! Enter in a positive integer:  ";

		cin.clear(); // Clears the error 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> i;

	}

	cout << endl << "Enter the period over which the loan is to be paid (must be 5, 10, or 15 years):   ";
	cin >> l;

	while (l != 5 && l != 10 && l != 15) // Checks for error
	{
		cout << endl << "!Error! Enter in a positive integer (must be 5, 10, or 15):  ";

		cin.clear(); // Clears tthe error
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> l;
	}

	i = 0.01 * (i / 12); // This converts the input into proper values to use
	l = l * 12;
	balance = t;

	payment = t * ((i * pow((1 + i), l)) / (pow((1 + i), l) - 1)); // This will calculate the monthly payments


	//This will display the information for the user

	cout << endl << "Loan amount: $" << fixed << showpoint << setprecision(2) << t << endl;
	cout << "Annual Interest Rate: " << resetiosflags(ios::fixed | ios::showpoint) << i * (12 / 0.01) << "%" << endl;
	cout << "Period over which the loan is to be paid: " << l / 12 << " Years or " << l << " months." << endl;
	cout << "Required Monthly Payment: $" << fixed << showpoint << setprecision(2) << payment << endl;


}


// This is the Amortization function which will recursively calculate 

int Amortize(int& months, double& payment, double& t, double& interest, double& balance, int& l, double& i)
{


	if (months > l)
	{
		return 1;

	}


	else
	{
		interest = balance * i;
		t = payment - interest;
		balance = balance + interest - payment;

		if (balance <= 0.00)
			balance = 0.00;

		// This will serve as the recursion statement
		cout << left << setw(10) << months << right << setw(11) << payment << setw(13) << interest << setw(14) << t << setw(12) << balance << endl;

		Amortize(months = months + 1, payment, t, interest, balance, l, i); // This is the function calling for the recursion 
	}


}