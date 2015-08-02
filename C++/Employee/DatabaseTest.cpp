#include <iostream>
#include <cstdio>

#include "Database.cpp"

using namespace std;
using namespace Records;

int main(int argc, char* argv[])
{
    Database myDB;
    
    Employee& emp = myDB.addEmployee("John", "Harvard");
    
    // Sadly our company is not doing well at the moment, that why we have to ...
    
    emp.fire();
    
    Employee& emp2 = myDB.addEmployee("David", "Malan");
    emp2.setSalary(100000);
    emp2.promote(10000);
    
    Employee& emp3 = myDB.addEmployee("Raul", "Rao");
    emp3.setSalary(10000000);
    emp3.promote(1000000);
    
    cout<<"Currently all Employees are: \n \n";
    
    myDB.displayAll();
    
    cout<<"Currently employed: \n \n";
    
    myDB.displayCurrent();
    
    cout<<"Former employees \n \n";
    
    myDB.displayFormer();
    
    return 0;
    
}   
