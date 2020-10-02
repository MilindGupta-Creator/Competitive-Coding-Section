#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int total_distance,mileage,n;//
    cin>>total_distance>>mileage>>n;        //n representing number of gas stations.
    vector<int>a(n);
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    a.insert(a.begin(),0);                //starting from 0
    a.push_back(total_distance);          //destination is the total_distance

    i=0;
    int ans=0;
    while (a[i]+mileage<total_distance)     //Runs till the last gas station
    {
        int last=i;                                           //First checkpoint
        while(i<a.size()-1 && (a[i+1]-a[last])<=mileage)      //checking if the distance between the checkpoint and the upcoming gas Station is less than mileage
        {
        i++;//going to the next nearest gas station
        }

        if(i==last)
        {
            cout<<-1;               //checkpoint is same as the upcoming gas station meaning that the mileage can not take the car to the next gas station so exiting the program.
            exit(0);
        }
        if(i<=n)
            ans++;//incrementing the no. of stops.
      
    }
    cout<<ans;
}
