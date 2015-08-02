#include <iostream>
#include <cstdio>

#define DEFAULT_SALARY 3000

 

using namespace std;


namespace Records
{

    class Employee
    {
    private:

        unsigned int employeeNumber;
        string firstName;
        string lastName;
        int salary;
        bool hired;


    public:

        Employee();
        ~Employee();
    
        void setEmployeeFirstName(const string& name);
        const string& getEmployeeFirstName() const;

        void setEmployeeNum(unsigned int num);
        unsigned int getEmployeeNum() const;

        void setEmployeeLastName(const string& name);
        const string& getEmployeeLastName() const;

        void setSalary(int getSalary);
        int getSalary() const;

        void hire();
        void fire();

        bool getIsHired() const;

        void promote(int amount);
        void demote(int amount);

        void display() const;

    };
}
