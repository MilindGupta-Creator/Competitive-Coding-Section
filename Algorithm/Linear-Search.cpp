#include<iostream>
using namespace std;

int linear(int[],int,int);
int main()
{
int ar[50],size,item,i,pos;
cout<<"Enter number of elements=";
cin>>size;
cout<<"Enter Array's Elements=";
for(i=0;i<size;i++)
cin>>ar[i];
cout<<"Enter element which to be searched=";
cin>>item;
pos=linear(ar,size,item);
if(pos==-1)
cout<<"Element not Found";
else
cout<<"Element Found at="<<(pos+1);

return 0;
}
int linear(int ar[],int size,int item)
{
int i;
for(i=0;i<size;i++)
{
    if(ar[i]==item)
    return i;
}    

return -1;

}
