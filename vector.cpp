/*
* Vector.cpp A program with which to demonstrate the use of vectors.
*
* 29.05.15 Raul Rao, Neu-Isenburg       This file is OpenSource for GitHub.
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

void createVector()
{
    vector <int> Vec;
    
    Vec.push_back(2);
    Vec.push_back(8);
    Vec.push_back(12);
    Vec.push_back(100);
    
    printf("\n So you have input the following: \n");
    for(unsigned int i = 0; i < Vec.size(); i++)
    {
        cout<<Vec[i] << "\n";
    }
    
}

int main(void)
{
    
    createVector();
 return 0;   
}