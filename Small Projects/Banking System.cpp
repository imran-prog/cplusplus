//***************************************************************************
//						HEADER FILES USED IN PROJECT
//***************************************************************************

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

//***************************************************************************
//							CLASS USED IN PROJECT
//***************************************************************************

class Account {
	int acno;
	char name[50];
	int deposit;
	char type;

public:
	void create_account();		// Function to get data from user
	void show_acount() const;	// Function to show data on screen
	void modify();				// Function to add new data
	void dep(int);				// Function to accept amount and add to data
	void draw(int);				// Function to accept credits and sub  data
	void report() const;		// Function to show data in taular form
	int retacno() const;		// Function to return account number
	int retdep() const;			// Function to return balance number
	void rettype();				// Function to return type of account
};				// class Ends Here

def Account::create_account() {
	cout << "Enter the account number: ";
	cin << acno;
}

def Account::show_acount() {

}

def Account::modify() {

}

def Account::dep() {

}

def Account::draw() {

}

def Account::report() {

}


//***************************************************************************
//							THE MAIN FUNCTION
//***************************************************************************

int main() {
	// Data Goes Here
}