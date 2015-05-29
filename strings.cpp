/*
* This program demonstates why a string is in a way an array of characters. The for-loop always reads out
* the i-th character and because i is always smaller than s[i], it will first read out the s[0], then 
* the s[1], s[2] which shows how an array works.
*
* Raul Rao, 29.05,  Neu-Isenburg,   This file is OpenSource for GitHub  
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void readOut(char * s)
{
    for(int i = 0; i < s[i];  i++)
    {
        cout<<s[i]<<"\n";   
    }
}

int main(int argc, char* argv[])
{   
    char * string = "Hello, My name is Steve. ";
    readOut(string);
    return 0;   
}