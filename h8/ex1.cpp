#include<bits/stdc++.h>
#include"assignment.h"
using namespace std;
void ex1_reverse_array()
{
    string input[100];
    int i=0;
    while (cin>>input[i]) i++;
    i--;
    while (i>=0)
    {
        cout<<input[i]<<" ";
        i--;
    }
    return;
}
int main()
{
    ex1_reverse_array();
    return 0;
}