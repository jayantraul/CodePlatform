/**
*   Jayant Raul Rao, 13.07.15
*   jraulrao@gmail.com
*   
*   Implements the User Interface and the main starting point for the Employee Application
*
*/


#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Database.cpp"

//use namespaces in User Interface

using namespace std;
using namespace Records;

//Function prototypes

int displayMenu();
void clearScreen();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void search(Database& db);
void doDemote(Database& db);

// main function with argc, argv[]

/**
*   While the boolean done is not true, call the function displayMenu and try to validate the selection of the 
*   user with a switch statement.
*/

int main(int argc, char* argv[])
{   
    Database employeeDB;
    bool done = false;
    
    while(!done)
    {
        int selection = displayMenu();
        switch (selection)
        {
            case 1:
                doHire(employeeDB);
                break;
            
            case 2:
                doFire(employeeDB);
                break;
               
            case 3:
                doPromote(employeeDB);
                break;
             
            case 4:
                search(employeeDB);
                break;
            
            case 5:
                employeeDB.displayAll();
                
                break;
            
            case 6:
                employeeDB.displayCurrent();
                
                break;
             
            case 7:
                employeeDB.displayFormer();
                
                break;
            
            case 8:
                doDemote(employeeDB);
                break; 
            
            case 0:
                done = true;
                break;
            
            default:
                cerr<<"You did not state something valid... \n";
                break;
        }
    }
    
    return 0;
}

/**
*   Show menu, take selection, and return the selection
*
*/

int displayMenu()
{
    int selection;
    char c;
    
    if(c == 'Q')
    {
        abort();
    }
    
    clearScreen();
    
    do
    {
        cout<<"Employee Management System \n \n";
        cout<<"MENU \n \n";
    
        cout<<"1) Hire a new Employee"<<endl;
        cout<<"2) Fire a new Employee"<<endl;
        cout<<"3) Promote an Employee"<<endl;
        cout<<"4) Search for an Employee"<<endl;
        cout<<"5) Display the entire DB"<<endl;
        cout<<"6) Display current employees"<<endl;
        cout<<"7) Demote an employee..."<<endl;
        cout<<"0) Exit program"<<endl;
        cout<<"---> ";
        cin>>selection;
    
    }while(!selection);
    
    return selection;
}

/**
*   Simply clear the command line interface 
*/

void clearScreen()
{
    //system("clear");
}

/**
*   Loop through the Database using the element function of the Database class. Enabling search by name and 
*   by employee number.
*/

void search(Database& db)
{
    printf("Search by name or by Number? (n / N): ");
    char c;
    cin>>c;
    
    string firstName;
    string lastName;
    Employee emp;
    int employeeNumber;
    char ca;
    
    switch(c)
    {
        case 'n':
            printf("Enter his first name: ");
            cin>>firstName;
            printf("Enter his last name: ");
            cin>>lastName;
            
            emp = db.getEmployeeByName(firstName, lastName);
            emp.display();
            
            printf("Press any button...");
            
            cin>>ca;
            
            if(ca)
            {
                displayMenu();
            }
            
            break;
            
        case 'N':
            printf("Enter his employee number: ");
            cin>>employeeNumber;
            
            emp = db.getEmployee(employeeNumber);
            emp.display();
            printf("Press any button...");
            
            cin>>ca;
            
            if(ca)
            {   
                
                displayMenu();
            }
        
        default:
            
            displayMenu(); 
    }
    
    return;
} 

/**
* Hire an Employee and creating a new Object and adding it two the Database.
*/  

void doHire(Database& db)
{
    string firstName;
    string lastName;
    
    cout<<"First Name: ";
    cin>>firstName;
    
    cout<<"Last Name: ";
    cin>>lastName;
    
    try
    {   
        db.addEmployee(firstName, lastName);
    }
    
    catch(const std::exception& exception)
    {
        cerr<<"Unable to add Employee in Database: "<<exception.what();
        printf("Press any button...");
        char c;
        cin>>c;
            
        if(c)
        {   
            
            displayMenu();
        }
    }
    
    
    printf("Press any button...");
    char c;
    cin>>c;
            
    if(c)
    {   
       
        displayMenu();
    }
    
}  

/**
* Fire an Employee and catch error.
*/ 

void doFire(Database& db)
{
    int employeeNumber;
    cout << "Employee number? "; 
    cin >> employeeNumber;
    
    try 
    {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } 
    
    catch (const std::exception& exception) 
    {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
        
        displayMenu();
    }
    
    
    displayMenu();
}

/**
* Increase the Salary by Tries
*/

void doPromote(Database& db)
{
    int employeeNumber;
    int raiseAmount;
    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? "; cin >> raiseAmount;
    
    try 
    {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } 
    
    catch (const std::exception& exception) 
    {
        cerr << "Unable to promote employee: " << exception.what() << endl;
        
        displayMenu(); 
    }
    
    
    displayMenu();
    
    return;
}

/**
* Decrease Salary by tries and catches
*/

void doDemote(Database &db)
{
    int employeeNumber;
    int deAmount;
    
    cout<<"Employee Number: ";
    cin>>employeeNumber;
    
    cout<<"How much to decrease ? : ";
    cin>>deAmount;
    
    try
    {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.demote(deAmount);
    }
    catch(const std::exception& exception)
    {
        cerr<<"Unable to demote employee: "<<exception.what()<<endl;
    }
    
    
    displayMenu();
}

