#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <cctype>
#include <cstdio>
#define max 10

using namespace std;

//------------------------------------------------------: Order Module for both Pharmacist and Customer :----------------------------------------------------------//
class Orders
{
public:
	void order();
	void order_list();
	void delete_item();
	void update_order();
	void summarry();
	void quit();

};

struct node
{
	int receiptNo;
	string Cus_Name;
	string date;
	int med_quantity[10];
	string type = { "OTC" };
	int x, menu2[10];
	double med_amt[10];
	string Med_Name[10] = { "Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen" };
	double Medicine[10] = { 2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00 };
	double tot_order;

	node* prev;
	node* next;
	node* link;

}*q, * temp;


node* starting_point = NULL;
node* head_point = NULL;
node* lasting_point = NULL;

void Orders::order()
{
	system("cls");
	int i;
	int options, med_quantity, med_price, None;

	cout << "\nAdd Order Details\n";
	cout << "########################################################################## \n\n";

	node* temp;
	temp = new node;

	cout << "##########################################################################\n";
	cout << "DRUGS ID" << "\tDRUGS TYPE" << "   \t\tDRUGS NAME" << "           DRUGS PRICE(RM)" << endl;
	cout << "##########################################################################\n";
	cout << "0001" << "\t" << "\tOTC" << "\t\t" << "    Probiotics" << "			RM 2.00" << endl;
	cout << "0002" << "\t" << "\tOTC" << "\t\t" << "    Vitamin C(500mg)" << "		RM 3.00" << endl;
	cout << "0003" << "\t" << "\tOTC" << "\t\t" << "    Acid Free C(500mg)" << "		RM 1.00" << endl;
	cout << "0004" << "\t" << "\tOTC" << "\t\t" << "    Women'S Multivate" << "		RM 4.00" << endl;
	cout << "0005" << "\t" << "\tOTC" << "\t\t" << "    Marino Tablet" << "	 	RM 1.00" << endl;
	cout << "0006" << "\t" << "\tOTC" << "\t\t" << "    Maxi Cal Tablet" << " 		RM 5.00" << endl;
	cout << "0007" << "\t" << "\tOTC" << "\t\t" << "    Amino Zinc Tablet" << "		RM 7.00" << endl;
	cout << "0008" << "\t" << "\tOTC" << "\t\t" << "    Burnex" << "			RM 4.00" << endl;//1353fn
	cout << "0009" << "\t" << "\tOTC" << "\t\t" << "    Fabuloss 5" << "			RM 3.00" << endl;
	cout << "0010" << "\t" << "\tOTC" << "\t\t" << "    Royal Propollen" << "		RM 5.00" << endl;
	cout << " " << endl;

	temp = new node;
	cout << "Type Order no: ";
	cin >> temp->receiptNo;
	cout << "Enter Customer Name: ";
	cin >> temp->Cus_Name;
	cout << "Enter Date : ";
	cin >> temp->date;
	cout << "How many Medicine would you like to order:";
	cout << "  ( Maximum is 10 order for each transaction ) \n";
	cout << "  ";
	cin >> temp->x;
	if (temp->x > 10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else
	{
		for (i = 0; i < temp->x; i++)
		{

			cout << "Please enter your selection : ";
			cin >> temp->menu2[i];
			cout << "\nMedicine Name: " << temp->Med_Name[temp->menu2[i] - 1];
			cout << "\tHow many medicine do you want: ";
			cin >> temp->med_quantity[i];
			temp->med_amt[i] = temp->med_quantity[i] * temp->Medicine[temp->menu2[i] - 1];
			cout << "\nThe amount You need to pay is: " << temp->med_amt[i] << " RM" << endl;
			system("PAUSE");
		}
		cout << "##########################################################################" << endl;
		cout << "Order Taken Successfully" << endl;
		cout << "##########################################################################" << endl;
		cout << "Go to Reciept Menu to Pay The Bill" << endl;
		cout << "##########################################################################" << endl;
		system("PAUSE");

		temp->next = NULL;
		if (starting_point != NULL)
		{
			temp->next = starting_point;
		}
		starting_point = temp;
		system("cls");
	}
}
void Orders::order_list()
{
	int i, num, num2;
	bool found;
	system("cls");
	node* temp;

	temp = starting_point;
	found = false;

	cout << " Enter the Reciept Number To Print The Reciept\n";
	cin >> num2;
	cout << "\n";
	cout << "##########################################################################" << endl;
	cout << "\t\tHere is the Order list\n";
	cout << "##########################################################################" << endl;


	if (temp == NULL)
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while (temp != NULL && !found)
	{
		if (temp->receiptNo == num2)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
		if (found)
		{
			cout << "Reciept Number : " << temp->receiptNo;
			cout << "\n";
			cout << "Customer Name: " << temp->Cus_Name << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "##########################################################################" << endl;

			cout << "##########################################################################" << endl;
			cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
			cout << "##########################################################################" << endl;
			for (i = 0;i < temp->x;i++)
			{
				cout << temp->type << "  \t\t";
				cout << temp->Med_Name[temp->menu2[i] - 1] << "\t\t\t  ";
				cout << temp->med_quantity[i] << "\t\t";
				cout << temp->med_amt[i] << " RM" << endl;
				cout << "##########################################################################" << endl;
			}

			temp->tot_order = temp->med_amt[0] + temp->med_amt[1] + temp->med_amt[2] + temp->med_amt[3] + temp->med_amt[4] + temp->med_amt[5] + temp->med_amt[6] + temp->med_amt[7]
				+ temp->med_amt[8] + temp->med_amt[9];
			cout << "Total Bill is : " << temp->tot_order;
			cout << "\n";
			cout << "Type the exact amount You need to pay: ";
			cin >> num;

			cout << "\n";
			cout << "\n";
			cout << "Payment Done\nThank You\n";
			cout << "\n##########################################################################\n";
		}
	}
}

void Orders::delete_item()
{
	system("cls");
	int i, num, count;
	cout << "Enter the data you want to delete \n";
	cin >> num;
	node* q;
	node* temp;
	bool found;

	if (starting_point == NULL)
		cerr << "Can not delete from an empty list.\n";
	else
	{
		if (starting_point->receiptNo == num)
		{
			q = starting_point;
			starting_point = starting_point->next;
			count--;
			if (starting_point == NULL)
				lasting_point = NULL;
			delete q;
			cout << "The Reciept is Deleted Successfully" << endl;
		}
		else
		{
			found = false;
			temp = starting_point;
			q = starting_point->next;

			while ((!found) && (q != NULL))
			{
				if (q->receiptNo != num)
				{
					temp = q;
					q = q->next;
				}
				else
					found = true;
			}

			if (found)
			{
				temp->next = q->next;
				count--;

				if (lasting_point == q)
					lasting_point = temp;
				delete q;
				cout << "The Reciept is Deleted Successfully" << endl;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}

void Orders::update_order()
{
	system("cls");
	int i, ch, sid;
	bool found;
	found = false;
	temp = starting_point;
	cout << "Enter Receipt Number To Modify: ";
	cin >> sid;
	if (temp == NULL && sid == 0)
	{
		cout << "NO RECORD TO MODIFY..!" << endl;
	}

	else
	{
		while (temp != NULL && !found)
		{
			if (temp->receiptNo == sid)
			{
				found = true;
			}
			else
			{
				temp = temp->next;
			}
			if (found)
			{
				cout << "Change  Order Number: ";
				cin >> temp->receiptNo;
				cout << "Change Customer Name: ";
				cin >> temp->Cus_Name;
				cout << "Change Date : ";
				cin >> temp->date;
				cout << "How many New Medicine would you like to Change:" << endl;
				cout << "( Maximum is 10 order for each transaction ) \n";
				cout << "  ";
				cin >> temp->x;
				if (temp->x > 10)
				{
					cout << "The Medicine you order is exceed the maximum amount of order !";
					system("pause");
				}
				else {
					for (i = 0; i < temp->x; i++)
					{

						cout << "Please enter your selection to Change: " << endl;
						cin >> temp->menu2[i];
						cout << "Change Medicine Name: " << temp->Med_Name[temp->menu2[i] - 1] << endl;
						cout << "How many New medicine do you want: ";
						cin >> temp->med_quantity[i];
						temp->med_amt[i] = temp->med_quantity[i] * temp->Medicine[temp->menu2[i] - 1];
						cout << "The amount You need to pay After Modify  is: " << temp->med_amt[i] << " RM" << endl;
						system("PAUSE");
					}
					temp = temp->next;
					system("cls");

				}

				cout << "RECORD MODIFIED....!" << endl;
			}
			else
			{
				if (temp != NULL && temp->receiptNo != sid)
				{
					cout << "Invalid Reciept Number...!" << endl;
				}
			}
		}
	}
}

void Orders::summarry()
{
	int i, num;
	system("cls");
	node* temp;

	temp = starting_point;


	if (temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout << "\n";
		cout << "##########################################################################" << endl;
		cout << " \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout << "##########################################################################" << endl;

		while (temp != NULL)
		{

			cout << "Reciept Number : " << temp->receiptNo;
			cout << "\n";
			cout << "Customer Name: " << temp->Cus_Name << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "*****************************************************************************" << endl;

			cout << "##########################################################################" << endl;
			cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
			cout << "#######++##################++################++###############++##########" << endl;
			for (i = 0;i < temp->x;i++)
			{
				cout << temp->type << "  \t\t";
				cout << temp->Med_Name[temp->menu2[i] - 1] << "\t\t";
				cout << temp->med_quantity[i] << "\t\t";
				cout << temp->med_amt[i] << " RM" << endl;
				cout << "*****************************************************************************" << endl;
			}

			temp->tot_order = temp->med_amt[0] + temp->med_amt[1] + temp->med_amt[2] + temp->med_amt[3] + temp->med_amt[4] + temp->med_amt[5] + temp->med_amt[6] + temp->med_amt[7]
				+ temp->med_amt[8] + temp->med_amt[9];
			cout << "Total Bill is : " << temp->tot_order;

			cout << "\n";
			cout << "\n";
			cout << "\n******************************************************************************\n";

			temp = temp->next;
		}
	}
}
void Orders::quit()
{
	cout << "\nYou choose to exit.\n" << endl;
}


//------------------------------------------------------: Customer Module :----------------------------------------------------------//


//Class for taking Orders of Customers
class Customer_Order
{
private:
	string cus_fname, cus_lname, cus_gender, cus_Email;
	int cus_contact, cus_age;
	int n;
public:
	void cus_order();
};

void Customer_Order::cus_order()
{
	int menu;
	Orders o;
	system("cls");

	cout << "\t\t\t\t========================================-========================================" << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
	cout << "\t\t\t\t			     Welcome to our Pharmacy			     " << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;

	cout << "\t\t\t\tFirst Name: ";
	cin >> cus_fname;

	cout << "\t\t\t\tLast Name: ";
	cin >> cus_lname;

	cout << "\t\t\t\tEmal: ";
	cin >> cus_Email;

	cout << "\t\t\t\tAge: ";
	cin >> cus_age;

	cout << "\t\t\t\tGender: ";
	cin >> cus_gender;

	cout << "\t\t\t\tContact No: ";
	cin >> cus_contact;

	ofstream File(cus_fname + ".txt");
	File << "firs Name: " << cus_fname
		<< "\nLast Name: " << cus_lname
		<< "\nEmail: " << cus_Email
		<< "\nAge: " << cus_age
		<< "\nGender: " << cus_gender
		<< "Contact No" << cus_contact;
	File.close();

	system("PAUSE");
	system("cls");
	do
	{
		cout << "\t\t\t\t========================================-========================================" << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\t		Order List of our Pharmacy		" << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\tPress \"1\" to Order Medicines. Press \"2\" to View Order List" << endl;
		cout << "\t\t\t\tPress \"3\" to Order Summary. Press \"4\" to Quit Order" << endl;
		cout << "\t\t\t\t1)Order Medicines" << endl;
		cout << "\t\t\t\t2)Order List" << endl;
		cout << "\t\t\t\t3)Order Summary" << endl;
		cout << "\t\t\t\t2)Quit Order" << endl;

		cout << "Enter choice: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			o.order();
			cout << "====================-====================" << endl;
			cout << "Do You want to change anything in your Order" << endl;
			cout << "Press \"1\" to Alter your Order. Press \"2\" to Delete Item. Press \"3\" to Exit." << endl;
			cout << "====================-====================" << endl;
			cout << "1)Alter your Order" << endl;
			cout << "2)Delete Item " << endl;
			cout << "2)Exit to Order Menu" << endl;

			cout << "Enter choice: ";
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				o.update_order();
				break;
			}
			case 2:
			{
				o.delete_item();
				break;
			}
			case 3:
			{
				o.quit();
				break;
			}
			default:
			{
				cout << "You enter invalid input\nre-enter the input\n" << endl;
				break;
			}
			}
			system("PAUSE");
			system("cls");
			break;
		}

		case 2:
		{
			o.order_list();
			system("PAUSE");
			break;
		}
		case 3:
		{
			o.summarry();
			system("PAUSE");
			break;
		}
		case 4:
		{
			o.quit();
			goto a;
			break;
		}


		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
			break;
		}
		}
	} while (menu != 6);
a:
	cout << "thank you" << endl;
	system("PAUSE");
}


//------------------------------------------------------: Login Module :----------------------------------------------------------//
//Class for Both customer and Pharmacist login
class Login
{
private:
	int choice;
	string UserName, password, con_password;
public:
	string un, pw;
	string getUserName();
	void sign_up();
	void login();
	void pharmacy_portal();
	void displayUserInfo();
	bool islogin();
	bool is_signed_up();
	bool doesAccountExist();
};
string Login::getUserName()
{
	return UserName;
}

bool Login::doesAccountExist()
{
	ifstream file(UserName + ".txt");
	return file.good();
}

bool Login::islogin()
{
	ifstream read(UserName + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == UserName && pw == password)
	{
		return true; //cout<<"Login Successfull";
	}
	else
	{
		return false; //cout<<"Invalid Login. Please enter correct username or password\n";
	}
}

void Login::sign_up()
{
	system("cls");

	cout << "\t\t\t\t========================================-========================================" << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
	cout << "\t\t\t\t				     Sign Up				     " << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;

	cout << "\t\t\t\tUser Name: ";
	cin >> UserName;

	cout << "\t\t\t\tPassword: ";
	cin >> password;

	cout << "\t\t\t\tConfirm Password:";
	cin >> con_password;

	if (password != con_password)
	{
		cout << "Password doesn't match. Please enter correct password ";
		system("PAUSE");
		system("cls");
		sign_up();
	}

	if (doesAccountExist())
	{
		cout << "\t\t\t\tThere is already an Account with the username:" << UserName;
		cout << "\n\t\t\t\tPlease Sign up with other UserName";
		system("PAUSE");
		sign_up();
	}

	ofstream MyFile(UserName + ".txt");
	MyFile << "UserName: " << UserName << "\npassword: " << password;
	MyFile.close();

	cout << "====================-====================" << endl;
	cout << "Successfully Signed up" << endl;
	cout << "Go to Login Page to Login to Pharmacy" << endl;
	cout << "====================-====================" << endl;
	system("PAUSE");
	system("cls");
}

void Login::login()
{
	system("cls");

	cout << "\t\t\t\t========================================-========================================" << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
	cout << "\t\t\t\t				      Login				      " << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;

	cout << "\t\t\t\t\tUser Name: ";
	cin >> UserName;

	cout << "\t\t\t\t\tPassword: ";
	cin >> password;

	if (doesAccountExist())
	{
		islogin();
	}
	else
	{
		cout << "Account does not exist. Please sign up.\n";
	}
	system("PAUSE");
}

void Login::pharmacy_portal()
{
	system("COLOR 6F");
	system("cls");

	do
	{
		cout << "\t\t\t\t========================================-========================================" << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\t			      Pharmacy Admin Portal      			" << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\tPress \"1\" to Register to Admin Portal.\n\t\t\t\tPress \"2\" to Login to admin Portal" << endl;
		cout << "\t\t\t\t1. Register or Signup to Pharmacy" << endl;
		cout << "\t\t\t\t2. Login to Pharmacy" << endl;

		cout << "\t\t\t\tYour choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			sign_up();
			break;
		}

		case 2:
		{
			login();

			break;
		}

		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
			break;
		}
		}
	} while (choice != 2);
a:
	cout << "You Are Successfully Logged in to the Pharmacy System" << endl;
	system("PAUSE");
}

int main()
{
	int choice1;
	Login l;
	Orders o1;
	Customer_Order c;

	cout << "\n\n\n\t\t\t\t========================================-========================================";
	cout << "\n\t\t\t\t			    Pharmacy Management System			   " << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------";
	cout << "\n\n\n\t\t\t\t  Submitted By : ";
	cout << "\n\n\t\t\t\t\t (1) Ali Hassan ----- F2022376079";
	cout << "\n\n\t\t\t\t\t (2) Zameel Ahmed --- F2022376081";
	cout << "\n\n\t\t\t\t\t (3) Fatima Surraya - F2022376092";
	cout << "\n\n\t\t\t\t\t (4) Meerab Farooq -- F2022376054";
	cout << "\n\n\t\t\t\t\t (5) Mian Azeem ----- F2022376047";
	cout << "\n\n\n\t\t\t\t  Submitted To : ";
	cout << "\n\n\t\t\t\t\t   Sir Mahmood Hussain" << endl;

	system("PAUSE");
	system("cls");

	cout << "\t\t\t\t========================================-========================================" << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
	cout << "\t\t\t\t			Welcome To Pure Care Pharmacy			" << endl;
	cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
	cout << "\t\t\t\tPress \"1\" for Customer.\n\t\t\t\tPress \"2\" for Pharmacist" << endl;
	cout << "\t\t\t\t1. Customer " << endl;
	cout << "\t\t\t\t2. Phrmacist " << endl;

	cout << "\t\t\t\tYour choice: ";
	cin >> choice1;

	switch (choice1)
	{
	case 1:
	{
		c.cus_order();
		break;
	}
	case 2:
	{
		l.pharmacy_portal();

		cout << "\t\t\t\t========================================-========================================" << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\t				  Your Dasboard				  " << endl;
		cout << "\t\t\t\t----------------------------------------=----------------------------------------" << endl;
		cout << "\t\t\t\tPress \"1\" for Checking Latest Sales.\t\tPress \"2\" for signing out" << endl;
		cout << "\t\t\t\t1. Checking Latest Sales. " << endl;
		cout << "\t\t\t\t2. Signout Pharmacy Portal " << endl;

		cout << "\t\t\t\tYour choice: ";
		cin >> choice1;

		switch (choice1)
		{
		case 1:
		{
			o1.summarry();
			system("PAUSE");
			break;
		}

		case 2:
		{
			o1.quit();
			break;
		}

		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
			break;
		}
		}
		system("PAUSE");
		break;
	}

	default:
	{
		cout << "You enter an invalid choice\nre-enter your choice\n" << endl;
		break;
	}
	}

	system("PAUSE");
	return 0;
}