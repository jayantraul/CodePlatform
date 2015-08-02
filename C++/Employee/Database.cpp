#include <iostream>
#include <stdexcept>

#include "Database.h"

using namespace std;

namespace Records
{
    Database::Database()
    {
        mNextEmployeeNumber = K_FIRST_EMPLOYEE_NUMBER;
    }
    
    Employee& Database::addEmployee(const string& firstName, const string& lastName)
    {
        Employee theEmployee;
        theEmployee.setEmployeeFirstName(firstName);
        theEmployee.setEmployeeLastName(lastName);
        theEmployee.setEmployeeNum(mNextEmployeeNumber++);
        theEmployee.hire();
        Employees.push_back(theEmployee);
        
        return Employees[Employees.size() - 1];
    }
    
    Employee& Database::getEmployee(int empNumber)
    {
        for(auto& emp : Employees)
        {
            if(emp.getEmployeeNum() == empNumber)
            {
                return emp;
            }
        }
        
        throw runtime_error("No employee found! \n");
    } 
    
    Employee& Database::getEmployeeByName(const string& firstName, const string& lastName)
    {
        for(auto& emp : Employees)
        {
            if(emp.getEmployeeFirstName() == firstName && emp.getEmployeeLastName() == lastName)
            {   
                return emp;
            }
        }
        
        throw runtime_error("No employee found \n");
    } 
    
    /**
    *   Iterating over the Employees.
    *
    */
    
    void Database::displayAll() const
    {
        for(const auto& emp : Employees)
        {
            emp.display();
        }
    }
    
    void Database::displayCurrent() const
    {   
        for(const auto& emp : Employees)
        {
            if(emp.getIsHired() == true)
            {   
                emp.display();
            }
        }
    }
    
    void Database::displayFormer() const
    {
        for(const auto& emp : Employees)
        {
            if(emp.getIsHired() == false)
            {
                emp.display();   
            }   
        }
    }   
}    
