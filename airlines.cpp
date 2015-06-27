#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <fstream>

using namespace std;

class Airline
{
private:                  //encapsulate data, lock down properties
    int miles;
    string name;
	bool hasEliteSuperStatus;
	string from;
	string destination;

public:

	Airline()
	{
		miles = 0;
		name = " ";
		hasEliteSuperStatus = false;
		from = "Frankfurt";
		destination = "New York"; 
	}
	
	void setName(const string& nameIn)
	{
		name = nameIn;
	}
	
	const string& getName()
	{
		return name;
	}
	
	int calcPrice()
	{
		if(getEliteSuperStatus() == true)
		{
			return 0;
		}
		
		else
		{
			return miles * 0.1;
		}
	}
	
	void setMiles(int n)
	{
		miles = n;
	}
	
	int getMiles()
	{
		return miles;
	}
	
	void setEliteSuperStatus(bool status)
	{
		hasEliteSuperStatus = status;
	}
	
	bool getEliteSuperStatus()
	{
		return hasEliteSuperStatus;
	}
	
	void setFrom(const string &fr)
	{
		from = fr;
	}
	
	const string &getFrom()
	{
		return from;
	}
	
	void setDestination(const string& dest)
	{
		destination = dest;
	}
	
	const string& getDestination()
	{
		return destination;
	}
	
	void list()
	{
		cout<<"AirIndia \n";
		cout<<"Emirates \n";
		cout<<"Ethiad \n";
		cout<<"Lufthansa \n";
		cout<<"SingapurAirlines \n \n \n";
		
		return;
	}
	
	string selectAirline()
	{
		cout<<"Please select an Airline:   (If you want to view list press y): ";
		
		string c;
		
		cin>>c;
		
		if(c == "y")
		{
			list();
			
			do
			{	
				cout<<"Enter an airline: ";
				cin>>c;
				
			}while(c == "y" || c == "");
			
			return c;
			
		}
		
		else if(c != "y")
		{
			return c;
		}
		
		else
		{
			cout<<"Alright, visit us again! \n";
			return "Unknown";		
		}
	}
	
	string createTicketNumber()
	{
		string ticketnumber = "FLY5355";
		
		return ticketnumber;
	}
	
	void buy()
	{	
		int price = calcPrice();
		
		cout<<"PRICE: "<<price<<"\n \n";
			
		string airline = selectAirline();
		
	    cout<<"Please state your destination: ";
	    string destination;
	
	    cin>>destination;
	
	    this->setDestination(destination);
	
	    cout<<"From where?: ";
	    string from;
	
	    cin>>from;
	
	    this->setFrom(from);
	
	
	    this->setMiles(10000);
		
		if(airline == "Unknown")
		{
			return;
		}
		
		cout<<"Want to buy? ... ";
		char yn;
		
		cin>>yn;
		
		if(yn == 'Y' || yn == 'y')
		{
			
			cout<<"Enter your Company (Visa, MasterCard, American Express, PayPal): ";
			
			string company;
			cin>>company;
			
			cout<<"Enter your Credit Card Number (xxxxxxxxxxxxxx): ";
			long long int creditcardnumber;
			cin>>creditcardnumber;
			
			cout<<"Enter your PIN: ";
			int PIN; 
			cin>>PIN;
			
			cout<<"Enter passport number: ";
			string passportnumber;
			
			cin>>passportnumber;
			
			
			
			cout<<"Alright, complete payment?: ";
			char c;
			
			cin>>c;
			
			if(c == 'Y' || c == 'y')
			{
				cout<<"Ticket bought!\n";
				cout<<"Email will be sent to you! \n";
			}
			
			cout<<"Allright, Ticket details: \n \n \n";
			
			string ticketnumber = createTicketNumber();
			
			cout<<"Name: "<<name<<"\n";
			cout<<"Ticket Number: "<<ticketnumber<<"\n";
			cout<<"Premimum Member: "<<hasEliteSuperStatus<<"\n";
			cout<<"From: "<<from<<"\n";
			cout<<"To: "<<destination<<"\n";
			cout<<"Company: "<<airline<<"\n";
			cout<<"Credit Card: "<<creditcardnumber<<"\n";
			cout<<"Credit Card Company: "<<company<<"\n";
			cout<<"PIN: "<<PIN<<"\n";
			cout<<"Passport number: "<<passportnumber<<"\n";
			
			std::ofstream myfile;
			myfile.open("text.txt");
			
			if(myfile.is_open())
			{
				myfile<<name<<"\n";
				myfile<<ticketnumber<<"\n";
				if(hasEliteSuperStatus == true)
				{
					myfile<<"Yes \n";
				}
				
				else 
				{
					myfile<<"No\n";
				}
				
				myfile<<from<<"\n";
				myfile<<destination<<"\n";
				myfile<<airline<<"\n";
				myfile<<creditcardnumber<<"\n";
				myfile<<company<<"\n";
				myfile<<PIN<<"\n";
				myfile<<passportnumber<<"\n";
				myfile<<price<<"\n";
				myfile<<miles<<"\n";
				
				myfile.close();
			}
			
			else 
			{
				cout<<"Unable to open file \n";
			}
			
		}
		
		else
		{
			cout<<"Ok \n";
		}
	}    

};


int main(int argc, char* argv[])
{
	Airline ticket;
	
	cout<<"Enter your name: ";
	
	string name;
	cin>>name;
	
	ticket.setName(name);
	
	cout<<"Enter your Premium password: ";
	
	string password = "iamrich";
	
	string p;
	
	cin>>p;
	
	if(p == password)
	{
		ticket.setEliteSuperStatus(true);
	}
	

	
	
	ticket.buy();
	
	
	return 0;
	
}
