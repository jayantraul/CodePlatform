/*
* Recursion means recursively defining something. Example: the factorial which can be used to define it. 3! = 3 * 2!. 
* So we can say that 1! = 1 and through recursion it is possible to define every other value. 2! = 2 * 1! = 2, so 3!  
* = 3 * 2 = 6 and so the coputer can compute the factorial value.
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int fact(int n)
{
	long long int result;
	
	if (n == 1)
	{
		return 1;
	}
	result = n * fact(n-1);
	
	return result;
}

int main(int argc, char *argv[]) 
{
	printf("Please input some the to be factorialized numer: ");
	long long n;
	cin>>n;	
	cout<<"Result: "<<fact(n);
}