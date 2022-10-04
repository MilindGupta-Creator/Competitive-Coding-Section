
#include<bits/stdc++.h>
using namespace std;
void shellsort(int arr[],int size)
{
    for(int gap=size/2; gap>=1 ; gap/=2)
    {
        for(int j=gap;j<size;j++)
        {
            for(int i=j-gap;i>=0;i=i-gap)
            {
                if(arr[i+gap]>arr[i])
                {
                    break;
                }
                else
                {
                    int temp=arr[i+gap];
                    arr[i+gap]=arr[i];
                    arr[i]=temp;
                }
            }
        }
    }
}
void printarray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={15,19,23,29,31,7,9,5,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    shellsort(arr,size);
    printarray(arr,size);

    return 0;
}