/******************************************************************************

                            Work of Milan Grewal

*******************************************************************************/

#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

struct CustomerAccount
{

	string name;
	string address;
	string city;
	string state;
	int zip;
	double phoneNum;
	double accountBalance;
	string lastPayment;
};

CustomerAccount customerInput(CustomerAccount&);
int getCustomer(CustomerAccount[], int, string);
void display(CustomerAccount[], int);
int main()
{

	const int SIZE = 20;

	CustomerAccount customers[SIZE];
	CustomerAccount customer;

	int userChoice;
	string fullName;
	int modify;
	int count = NULL;
	do {
		cout << "1. Add the details of a new customer" << endl;
		cout << "2. Change the details of a customer" << endl;
		cout << "3. Display the details of all customers" << endl;
		cout << "4. Exit" << endl;
		cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			customers[count] = customerInput(customer);
			count++;
			break;
		case 2:
			cout << endl << "Enter full name of customer to be modified: ";
			cin >> fullName;
			modify = getCustomer(customers, count, fullName);
			if (modify == -1)
				cout << endl << "Wrong customer name to modify" << endl;
			else
			{
				customers[modify] = customerInput(customer);
				if (customers[modify].name != fullName)
				{
					cout << endl << "Cannot change the name" << endl;
					customers[modify].name = fullName;
				}
			}
			break;
		case 3:
			display(customers, count);
			break;
		case 4:
			exit(0);
		default:
			cout << "Enter 1,2,3 or 4 only." << endl;
		}
	}
		while (userChoice != 4 && count < SIZE);
		{
			system("pause");
		}

		return 0;
	
}


CustomerAccount customerInput(CustomerAccount& cust)
{

	cout << endl;
	cout << "Enter the name of a customer: ";
	cin >> cust.name;
	
	cout << "Enter the address of a customer: ";
	cin >> cust.address;

	cout << "Enter the city of a customer: ";
	cin >> cust.city;

	cout << "Enter the state of a customer: ";
	cin >> cust.state;

	cout << "Enter the ZIP code: ";
	cin >> cust.zip;
	
	cout << "Enter the phone number: ";
	cin >> cust.phoneNum;
	
	cout << "Enter the account balance: $";
	cin >> cust.accountBalance;
	
	while (cust.accountBalance < 0)
	{
		cout << "Enter the positive value: $";
		cin >> cust.accountBalance;
	}
	
	cout << "Enter the date of last payment in the form of-dd/mm/yyyy: ";
	cin >> cust.lastPayment;
	return cust;
}

int getCustomer(CustomerAccount cust[], int size, string name)
{
	int customer = -1;
	
	for (int i = 0; i < size; i++)
	{
		if (cust[i].name == name)
		{
			customer = i;
			break;
		}
	}
	return customer;
}

void display(CustomerAccount cust[], int size)
{

	if (size == 0)
		cout << endl << "No customers in the array to display." << endl;
	else
	{
		
		for (int i = 0; i < size; i++)
		{
			
			cout << endl;
			cout << "Name of a customer: " << cust[i].name << endl;
		
			cout << "Address of a customer: " << cust[i].address << endl;
			
			cout << "City of a customer: " << cust[i].city << endl;
			
			cout << "ZIP code: " << setprecision(10) << cust[i].zip << endl;
		
			cout << "Phone number: " << setprecision(15) << cust[i].phoneNum << endl;
		
			cout << "Account balance: $" << setprecision(15) << cust[i].accountBalance << endl;
			
			cout << "Date of last payment: " << cust[i].lastPayment << endl;
		}
	}
}
