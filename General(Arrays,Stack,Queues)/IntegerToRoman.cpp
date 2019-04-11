// C++ Program to convert decimal number to
// roman numerals
#include <bits/stdc++.h>
using namespace std;

int den[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
char str[][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

void printRoman(int num)
{
    int i=0;
    while(num!=0)
    {
        int q=num/den[i];
        for(int j=0;j<q;j++)
            cout<<str[i];
        num-=q*den[i];
        i++;
    }
}

//Driver program
int main()
{
    int number = 3549;

    printRoman(number);

    return 0;
}
