// Lab10b-Classes-Bank_Account_Transfer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
using namespace std;
class BankAcct
{

public:
	BankAcct(string name, double balance);
	BankAcct(string name);
	BankAcct();
	/* Member function to display an account. */
	void display(int i);
	/* Member function to add to the account. */
	void deposit(double amt);
	void withdraw(double amt);
	void transfer(BankAcct& accountName, double amount);
	void accountAdd(string newName, double startingAmount); \
		void postInterest(int timePassed);
private:
	string name;
	double balance;
	double interest = 0.042;
	int time;
};

int main()
{
	double amount = 0;
	const int MAX_ACCOUNTS = 10;
	char choice = 'a';
	int numberOfAccounts = 0;
	BankAcct accounts[MAX_ACCOUNTS];
	int accountSelection = 0;
	int accountSelection2 = 0;
	string v1;
	double v2;
	int v3 = 0;
	/* Some code to make doubles have two decimal points */
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (tolower(choice) != 'q') {
		cout << "ACCOUNT\t\t\t" << "BALANCE\n";
		for (int i = 0; i < numberOfAccounts; i++) {
			accounts[i].display(i);

		}
		cout << "(A)dd   (D)eposit    (W)ithdraw     (T)ransfer    (M)editate    (Q)uit: ";
		cin >> choice;

		switch (tolower(choice)) {

			if (numberOfAccounts >= MAX_ACCOUNTS) {
				cout << "We are at account capacity, unable to add";
				break;
			}
		case 'a':
			cout << "Enter the account name and starting balance: ";
			cin >> v1 >> v2;
			accounts[numberOfAccounts].accountAdd(v1, v2);
			numberOfAccounts++;
			break;
		case 'd':       // added 'd' option to deposit money. Added new variables to accommodate the new feature. 
			cout << "Which account would you like to make a deposit to? (Please use corresponding number)\n";
			cin >> accountSelection;
			cout << "How much would you like to deposit?: ";
			cin >> v2;
			accounts[accountSelection].deposit(v2);
			break;
		case 'w':       // added 'w' option to withdraw money. 
			cout << "Which account would you like to withdraw from? (Please use corresponding number)\n";
			cin >> accountSelection;
			cout << "How much would you like to withdraw?: ";
			cin >> v2;
			accounts[accountSelection].withdraw(v2);
			break;
		case 't':		//transfer funds from one account to another
			cout << "Which account would you like to withdraw from? (Please use corresponding number)\n";
			cin >> accountSelection;
			cout << "What account do you want to transfer to? (Please use corresponding number)\n";
			cin >> accountSelection2;
			cout << "How much would you like to transfer?: ";
			cin >> v2;
			accounts[accountSelection].transfer(accounts[accountSelection2], v2);
			break;
		case 'm':		//added option to let time pass to accumlate wealth
			cout << "How long do you want to wait? (years)\n";
			cin >> v3;
			for (int i = 0; i < numberOfAccounts; i++) {
				accounts[i].postInterest(v3);
			}
			break;
		case 'q':
			cout << "Quitting ...\n";
			break;
		default:
			cout << "Unrecognized Command\n";
			break;
		}
	}
	system("pause");
	return 0;
}
// Overloaded Constructor definitions for varying initial value calls. 
BankAcct::BankAcct(string n, double bal)
{
	name = n;
	balance = bal;
}
BankAcct::BankAcct(string n)
{
	name = n;
	balance = 0;
}
BankAcct::BankAcct()
{
	name = "---";
	balance = 0;
}
void BankAcct::display(int i)
{
	cout << "(" << i << ") " << name << "\t\t" << "$" << balance << endl;
}
void BankAcct::deposit(double amt)
{
	balance += amt;
}

void BankAcct::withdraw(double amt)
{
	balance -= amt;
}

void BankAcct::transfer(BankAcct& accountName, double amount)
{
	//subtract from current account
	withdraw(amount);
	//add to target account
	accountName.deposit(amount);
}

void BankAcct::accountAdd(string newName, double startingAmount)
{
	name = newName;
	balance = startingAmount;
}

void BankAcct::postInterest(int timePassed)
{
	balance = balance * (1 + interest * timePassed);
}
