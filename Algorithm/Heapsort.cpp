//solution by priyanka Gupta
// Heapsort
//used for sorting ---inplace algo
// time complexity O(nlogn)

#include<bits/stdc++.h>
using namespace std;

//optimized function
void downheapify(vector<int>&a,int parentidx,int len){

    int idx=parentidx,lchild=2*parentidx+1,rchild=2*parentidx+2;
    
    if(lchild < len && a[lchild]>a[idx]){
        idx=lchild;
    }
    if(rchild < len && a[rchild]>a[idx]){
        idx=rchild;
    }

    if(idx==parentidx)return;

    else{
        swap(a[idx],a[parentidx]);
        downheapify(a,idx,len);
    }


}

//using heapsort to sort the vector inplace
void heapsort(vector<int>&heap,int n){

    for(int i=n-1;i>0;i--){
        swap(heap[0],heap[i]);
        downheapify(heap,0,i);
    }

}

//to form heap initially 
void buildheap(vector<int>&heap,int n){
    for(int i=n/2-1;i>=0;i--){
        //using downheapify to build heap
        downheapify(heap,i,n);
    }
}

int main(){

    int n;
    cin>>n;
    vector<int>heap(n);
    for(int i=0;i<n;i++){
        cin>>heap[i];
    }


    buildheap(heap,n);
    heapsort(heap,n);

    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
}
