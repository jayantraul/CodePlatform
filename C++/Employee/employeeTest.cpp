#include <iostream>
#include <cstdio>

#include "employee.cpp"

using namespace std;
using namespace Records;

int main(int argc, char* argv[])
{
    cout<<"Testing the Employee Class..."<<"\n";
    Employee emp;
    emp.setEmployeeFirstName("John");
    emp.setEmployeeLastName("Harvard");
    emp.setEmployeeNum(1);
    emp.setSalary(DEFAULT_SALARY);
    emp.hire();
    emp.display();
    
    return 0;
}
