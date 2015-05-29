/*
* Type inference is one of the new features of C++ 11 which allows you to not declare the type of the variable directly but 
* using the auto keyword, the variable takes the type of the assignment. This is especially useful to either save time or be 
* more dynamic in using programming. 
*
* Raul Rao, 29.05.15, Neu-Isenburg, Germany    
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

int sum(int arg1, int arg2)
{
	return arg1 + arg2;
}

int main(int argc, char *argv[]) 
{	
	auto x = 6;
	printf("Input: \n");
	cin>>x;
	auto y = x;
	cout<<x;
	return 0;
}