#include <iostream>
#include <vector>

#include "employee.cpp"
#define K_FIRST_EMPLOYEE_NUMBER 1000

using namespace std;

namespace Records
{
    class Database
    {
    private:
        
        vector<Employee> Employees;
        int mNextEmployeeNumber;
    
    
    public:
        
        Database();
        
        Employee& addEmployee(const string& firstName, const string& lastName);
        Employee& getEmployee(int empNumber);     
        Employee& getEmployeeByName(const string& firstName, const string& lastName);
        
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;
    };    

}

