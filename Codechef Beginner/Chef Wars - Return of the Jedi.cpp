//August Long Challenge 2020
#include<iostream>
#include<string>
using namespace std;
 
int main()
{//input
  long long int i,j;
  long long int h,p;
 long long int t;
 //input of test case
  cin>>t;
  while (t--)
  {
    cin>>h>>p;
     //checking if h is greater than 2 time p & printing "1" if false and "0" if true  .
    if(h>2*p)
    {
      cout<<"0"<<endl;
    }
    else 
    {
      cout<<"1"<<endl;
    }
  }
}