/*
* Pointers are an important concept of C++ although not many languages ave them. With pointers it is 
* possible save adresses and so hold references to variables and even change their values. The con-
* cept of pointers allows to play around with memory and dynamical allocation. And even strings are
* actually pointers, char *, a pointer to the first character.
* In this example a fuction fn is declared which takes as param a pointer on an in int. In the body
* this pointer is dereferenced and this value is set to 10. The function parent takes no arguments and 
* initializes a variable n1 which is 0 in its body. A reference to it is passed to fn and now fn is 
* changing the value of n1 to 10.
*
*
* Raul Rao, 29.05.15, Neu-Isenburg    This file is OpenSource to GitHub.
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

void fn(int * pNArg)
{
    *pNArg = 10;
}
void parent()
{
    int n1 = 0;
    fn(&n1);
    cout<<n1<<"\n";
}

int main(void)
{
    parent();
    return 0;
}