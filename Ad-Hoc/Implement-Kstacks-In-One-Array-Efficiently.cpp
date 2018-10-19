#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k,free1;

int *arr,*top,*next;

void initialize()
{
    arr=(int*)malloc(sizeof(int)*n);
    top=(int*)malloc(sizeof(int)*k);
    next=(int*)malloc(sizeof(int)*n);

    for(int i=0;i<k;i++)
        top[i] = -1;

    for(int i=0;i<n-1;i++)
        next[i]=i+1;

    next[n-1] = -1;

    free1 = 0;
}

bool isFull()
{
    if(free1==-1) return true;
    return false;
}

bool isEmpty(int sn)
{
    if(top[sn]==-1)
        return true;
    return false;
}

void push(int ele,int sn)
{
    if(isFull())
        return;

    int i = free1;
    free1 = next[i];
    next[i] = top[sn];
    top[sn] = i;

    arr[i] = ele;
}

int pop(int sn)
{
    if(isEmpty(sn))
        return -1;

     int i = top[sn];
     top[sn] = next[i];
     next[i] = free1;
     free1 = i;

     return arr[i];
}

int main()
{
    cout<<"Enter the maximum array size:";
    cin>>n;
    cout<<"Enter the number of stacks:";
    cin>>k;

    int popped_value;

    initialize();

    push(1,0);
    push(2,0);
    push(3,1);
    push(4,2);

    if((popped_value=pop(1))!=-1)
        cout<<"Popped element from 2nd Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack2 is empty"<<endl;

    if((popped_value=pop(0))!=-1)
        cout<<"Popped element from 1st Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack1 is empty"<<endl;

    push(5,0);
    push(6,1);

    if((popped_value=pop(2))!=-1)
        cout<<"Popped element from 3rd Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack3 is empty"<<endl;

    push(7,2);
    push(8,1);

    if((popped_value=pop(0))!=-1)
        cout<<"Popped element from 1st Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack1 is empty"<<endl;

    if((popped_value=pop(1))!=-1)
        cout<<"Popped element from 2nd Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack2 is empty"<<endl;

    if((popped_value=pop(2))!=-1)
        cout<<"Popped element from 3rd Stack is: "<<popped_value<<endl;
    else
        cout<<"Stack3 is empty"<<endl;

    push(9,2);
}
