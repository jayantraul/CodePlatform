#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "employee.h"

using namespace std;

namespace Records
{
    Employee::Employee()
    {
        employeeNumber = 0;
        firstName = "";
        lastName = "";
        salary = 0;
        hired = true;
    }

    Employee::~Employee()
    {
        //TODO
    }

    /*
     * Sets property hired to either true or false in hire of fire
     *
     */

    void Employee::hire()
    {
        if(hired == true)
        {
            //cout<<"Employee is already hired \n";
        }

        else
        {
            hired = true;
        }
    }


    
    void Employee::fire()
    {
        if(hired == false)
        {
            cout<<"Employee is not employed by you. You cannot fire him. \n";
        }

        else
        {
            hired = false;
        }
    }

    /*
     * promote and demote add or subtract the Salary from the Employee.setSalary is going to set the new salary to be the value of getSalary
     * plus the value of the amount. The demote works the opposite way by simply subtracting the value. 
     *
     */

    void Employee::promote(int amount)
    {
        setSalary(getSalary() + amount);
    }

    void Employee::demote(int amount)
    {   
        if(salary - amount <= 0)
        {
            printf("Cannot demote any more. Otherwise get rid of him by firing him. ");
        }

        else
        {
            setSalary(getSalary() - amount);
        }
    }

    /*
     * 
     *
     */

    void Employee::setSalary(int getSalary)
    {
        salary = getSalary;
    }

    int Employee::getSalary() const
    {
        return salary;
    }

    /*  
     *  
     *
     */

    void Employee::setEmployeeFirstName(const string& name)
    {
        firstName = name;
    }

    const string& Employee::getEmployeeFirstName() const
    {
        return firstName;
    }

    /*
     *
     *
     */

    void Employee::setEmployeeLastName(const string& name)
    {
        lastName = name;
    }

    const string& Employee::getEmployeeLastName() const
    {
        return lastName;
    }

    /*
     *
     */

    void Employee::setEmployeeNum(unsigned int num)
    {
        employeeNumber = num;
    }

    unsigned int Employee::getEmployeeNum() const
    {   
        if(employeeNumber == 0)
        {
            cout<<"This employee is not yet properly part of your company \n";
        }
            
        return employeeNumber;
    }
    
    bool Employee::getIsHired() const
    {
        return hired; 
    }    
 
    void Employee::display() const
    {
        cout<<"Employee: "<<getEmployeeLastName()<<", "<<getEmployeeFirstName()<<"\n";
        cout<<"------------------------"<<"\n";
        cout<<"Is "<<(hired ? "Current Employee" : "Former Employee. ")<<"\n";
        if(hired == true)
        {   
            cout<<"Employee Number: "<<getEmployeeNum()<<"\n";
            cout<<"Salary: $"<<getSalary()<<"\n";
            cout<<endl;
        }
        
    }
    
}



