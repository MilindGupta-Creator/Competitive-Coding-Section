
//The task is to count all the possible paths from top left
//  to bottom right of a m X n matrix with the constraints
//   that from each cell you can either move only to right or down.

#include <bits/stdc++.h>
using namespace std;


#define ll long long
const int md = 1e9 + 7;
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
       
        vector<ll>prev(n,1), curr(n);
        curr[0] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                curr[j] = (curr[j - 1] + prev[j])%md;
            }
            prev = curr;
        }
        return prev[n - 1];
        
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

