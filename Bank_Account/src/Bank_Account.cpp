//============================================================================
// Name        : Bank_Account.cpp
// Author      : Egor Abramov
// Version     :
// Copyright   : Your copyright notice
// Description : Bank Account Manager app (training for GitHub), Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//created class with data and needed functions
class BankAccount{
	public:
		int accountNumber;
		string ownerName;
		float balance;

		void menu();
		void deposit();
		void withdraw();
		void displayAccountInfo();
};

//deposit function in BankAccount class
void BankAccount::deposit(){
	float depositAmount;
	cout << "Enter the deposit amount. \n";
	cin >> depositAmount;
	balance = balance + depositAmount;
	cout << "New amount is: " << balance << "\n";
}

//withdraw function in BankAccount class
void BankAccount::withdraw(){
	float withdrawalAmount;
	cout << "Enter the withdrawal amount. \n";
	cin >> withdrawalAmount;
	if (withdrawalAmount > balance){
		cout << "Insufficient amount.\n";
		exit(0);
	}// quits program if funds are insufficient
	balance = balance - withdrawalAmount;
	cout << "New amount is: " << balance << "\n";
}

//display function in BankAccount class
void BankAccount::displayAccountInfo(){
	cout << "Account number: " << accountNumber << "\n";
	cout << "Owner name: " << ownerName << "\n";
	cout << "Current balance: " << balance << "\n";
}

//menu function in BankAccount class
void BankAccount::menu(){
	int choice;
	do{
		cout << "Select your option: 1 to display info; 2 to deposit money; 3 to withdraw money; 0 key to quit:\n";
		cin >> choice;

		switch (choice){
			case 1:
				displayAccountInfo();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 0:
				cout << "Closing app.\n";
		}
	} while (choice !=0); //program works until user inputs 0
}

int main() {
	BankAccount customer1; // creation of a customer1 object in BankAccount class
	customer1.accountNumber = 1;
	customer1.ownerName = "John Doe";
	customer1.balance = 50.49;

	customer1.menu(); //calls menu from BankAccount class through customer1 object

	return 0;
}
