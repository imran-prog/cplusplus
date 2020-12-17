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
	void show_account() const;	// Function to show data on screen
	void modify();				// Function to add new data
	void dep(int);				// Function to accept amount and add to data
	void draw(int);				// Function to accept credits and sub  data
	void report() const;		// Function to show data in taular form
	int retacno() const;		// Function to return account number
	int retdep() const;			// Function to return balance number
	char rettype() const;				// Function to return type of account
};				// class Ends Here

void Account::create_account() {
	cout << "\nEnter the account number: ";
	cin >> acno;
	cout << "\n\nEnter the Name of the account Holder: ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter Type of account (C/S): ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter the Intitial amount (>= 500 for Saving and >= 1000 for current) : ";
	cin >> deposit;
	cout << "\n\n\nAccount Created...";
}

void Account::show_account() const {
	cout << "\nAccount Number: " << acno;
	cout << "\nAccount Holder Name: ";
	cout << name;
	cout << "\nType of Account: " << type;
	cout << "\nAccount Balance:" << deposit;
}

void Account::modify() {
	cout << "\nAccount Number: " << acno;
	cout << "\n\nModify account Holder name: ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nModify Type of account (C/S): ";
	cin >> type;
	type = toupper(type);
	cout << "\nmodify Account Balanace : ";
	cin >> deposit;
}

void Account::dep(int x) {
	deposit += x;
}

void Account::draw(int x) {
	deposit -= x;
}

void Account::report() const {
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int Account::retacno() const {
	return acno;
}

int Account::retdep() const {
	return deposit;
}

char Account::rettype() const {
	return type;
}

//***************************************************************************
//							FUNCTION DECLARATION
//***************************************************************************

void write_account();		// Function to write record in binary file
void display_sp(int);		// Function to display account details
void modify_account(int);	// Function to modify record of file
void delete_account(int);	// Function to delete record of file
void display_all();			// Function to display all account details
void deposit_withdraw(int, int); //Function to deposit and withdraw amount
void intro();				// Introductry Screen Function

//***************************************************************************
//							THE MAIN FUNCTION
//***************************************************************************

int main() {
	char ch;
	int num;
	intro();

	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. DEPOSIT AMOUNT";
		cout << "\n\n\t03. WITHDRAW AMOUNT";
		cout << "\n\n\t04. BALANCE ENQUIRY";
		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t06. CLOSE AN ACCOUNT";
		cout << "\n\n\t07. MODIFY AN ACCOUNT";
		cout << "\n\n\t08. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout << "\n\n\tEnter the account number: ";
			cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout << "\n\n\tEnter the account number: ";
			cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout << "\n\n\tEnter the account number: ";
			cin >> num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout << "\n\n\tEnter the account number: ";
			cin >> num;
			delete_account(num);
			break;
		case '7':
			cout << "\n\n\tEnter the account number: ";
			cin >> num;
			modify_account(num);
			break;
		case '8':
			cout << "\n\n\tThanks for using Banking Management System";
			break;
		default:
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;
}

//***************************************************************************
//							FUNCTION TO WRITE IN FILE
//***************************************************************************

void write_account() {
	Account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}

//***************************************************************************
//						FUNCTION TO READ SPECIFIC DATA
//***************************************************************************

void display_sp(int n) {
	Account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);

	if(!inFile) {
		cout << "File could not be open!!! Press any key...";
		return;
	}
	cout << "\nBALANCE DETAIL\n";

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {

		if (ac.retacno() == n) {
			ac.show_account();
			flag = true;
		}
	}

	inFile.close();

	if (flag == false) {
		cout << "\n\nAccount Number does not exist";
	}
}

//***************************************************************************
//						FUNCTION TO MODIFY RECORD OF FILE
//***************************************************************************

void modify_account(int n) {
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);

	if (!File) {
		cout << "File could not be open!!! Press any key...";
		return;
	}

	while (!File.eof() && found == false) {
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));

		if (ac.retacno() == n) {
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(Account));
			cout << "\n\n\trecord Updated";
			found = true;
		}
	}

	File.close();
	if (found = -false) {
		cout << "\n\n\tRecord not Found";
	}
}

//***************************************************************************
//						FUNCTION TO DELETE RECORD OF FILE
//***************************************************************************

void delete_account(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
		}
	}

	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted ..";
}

//***************************************************************************
//				FUNCTION TO DISPLAY ALL ACCOUNT DEPOSIT LIST
//***************************************************************************

void display_all()
{
	Account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		ac.report();
	}
	inFile.close();
}

//***************************************************************************
//					FUNCTION TO WITHDRAW AND DEPOSIT AMOUNT
//***************************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.retdep() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

//***************************************************************************
//							INTRODUCTION FUNCTION
//***************************************************************************

void intro() {
	cout << "\n\n\n\t	BANK";
	cout << "\n\n\tMANAGEMENT";
	cout << "\n\n\tSYSTEM";
	cin.get();
}

//***************************************************************************
//								END OF PROJECT
//***************************************************************************
