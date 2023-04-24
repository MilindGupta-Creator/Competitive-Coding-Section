//Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


#include<bits/stdc++.h>
using namespace std;


// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        
        int low = 0;
        int high = n-1;
        int mid = 0;
        
        while(mid<=high){
            switch(a[mid]){
                case 0:{
                    swap(a[low], a[mid]);
                    low++;
                    mid++;
                    break;
                }
                case 1:{
                    mid++;
                    break;
                }
                case 2:{
                    swap(a[mid], a[high]);
                    high--;
                    break;
                }
            }
        }
    }
    
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        ob.sort012(A,N);
        for(int i=0;i<N;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
}