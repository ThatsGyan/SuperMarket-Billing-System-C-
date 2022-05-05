#include<iostream>
#include<fstream>

using namespace::std;

class shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;

public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();

};

void shopping::menu()
{
m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\ _____________________________________________________\n";
	cout << endl;
	cout << "\t\t\t\                 SuperMarket Main Menu                \n";
	cout << "\t\t\t\t" << endl;
	cout << "\t\t\t\t" << endl;
	cout << "\t\t\t\ _____________________________________________________\n";
	cout << "\t\t\t\t" << endl;
	cout << "\t\t\t\t |		1] Administrator	| \n" << endl;
	cout << "\t\t\t\t |							| \n" << endl;
	cout << "\t\t\t\t |		2] Buyer			| \n" << endl;
	cout << "\t\t\t\t |							| \n" << endl;
	cout << "\t\t\t\t |		3] Exit				| \n" << endl;
	cout << "\t\t\t\t |							| \n" << endl;
	cout << "\t\t\t\t |<<---------Please Select--------->>| \n" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\t\t\t\t Please Login      \n";
		cout << "\t\t\t\t Enter Emai      l \n";
		cin >> email;
		cout << "\t\t\t\t Enter Password    \n";
		cin >> password;

		if (email = "gyann@gmail.com" && password = "Gyann@123")
		{
			administrator();
		}
		else
		{
			cout << "Invalid emai/ password" << endl;
		}
		break;

	case 2:
	{
		buyer();
	}

	case 3:
	{
		exit(0);

	}

	default:
	{
		cout << "please select from the given options" << endl;
	}


	}
	goto m;
}

void shopping::administrator()
{
m:
	int choice;
	cout << "\n\n\n\t\t\t\ Administrator menu\n";
	cout << "\n\t\t\t|   1] Add The Product			|\n";
	cout << "\n\t\t\t|								|\n";
	cout << "\n\t\t\t|   2] Modify The Product      |\n";
	cout << "\n\t\t\t|								|\n";
	cout << "\n\t\t\t|   3] Delete The Product      |\n";
	cout << "\n\t\t\t|								|\n";
	cout << "\n\t\t\t|   4] Back to main menu       |\n";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "<-------------------- Please Enter Your Choice --------------------> "<<endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "Invalid Choice!";

		
	}
	goto m;
	
}

void shopping::buyer()
{
	m:
	int choice;
	cout << "\t\t\t\     Buyer		 \n";
	cout << "___________________________________\n";
	cout << "                                          \n";
	cout << "\t\t\t   Buy Product     \n";
	cout << "                                          \n";
	cout << "\t\t\t\     GO Back     \n";
	cout << "\t\t\t Enter your choice :" << endl;
	cin >> choice;

	switch (choice)
	{

	case 1:
		receipt();
		break;
	case 2:
		menu();
		break;

	default:
		cout << "Invalid choice";
		break;
	}
	goto m;
}
void shopping::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;

	cout << "\n\n\t\t\t  Add new product \n";
	cout << "\n\n\t product code of product\n";
	cin >> pcode;
	cout << "\n\n\t\t Name of the product \n";
	cin >> pname;
	cout << "\n\n\t\t Price of the product \n";
	cin >> price;
	cout << "\n\n\t\t Discount on the product \n";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();

	}
	else
	{
		data >> c >> n >> p >> d;
		while (!data.eof())
		{
			if (c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
			
		}
		data.close();
	}
	if (token == 1)
	{
		goto m;
	}
	else
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
		//39.40//

	}



}
