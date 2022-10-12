#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define intt int
#define sz(x) x.size()
#define pb push_back
#define pb2 pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bend(x) x.begin(), x.end()
#define vi vector<ll>
#define mapp map<ll, ll>
#define sett set<ll>
#define ve vector
#define un_m unordered_map<ll, ll>
#define f(i, a, b) for (i = a; i < b; i++)
#define f2(i, a) for (auto i = a.begin(); i != a.end(); i++)
#define maxxx INT32_MAX
#define mp make_pair
#define in(t) scanf("%lld",&t)
#define out(t) printf("%lld",t)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PQ priority_queue
#define ts(s) to_string(s)

const unsigned int mod = 1000000007;
string yes = "YES", no = "NO";
bool isPowerOfTwo (ll x)
{

    return x && (!(x&(x-1)));
}

void sol() {
    ll n{},d{},ds{},x{},k{},i{},j{},tt{},w=-1,t{},y{},cnt{},ans{},m,sum{};
    string s="";
    cin>>n;
    if(isPowerOfTwo(n) && n!=1)
    {
        cout<<n+1;
        return;
    }
    x=n;
    cout<<(x&(x-1)?x&-x:x+1+(x&1));
}


// driver function
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    ll tc = 1; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        sol();
        cout << endl;
    }

    return 0;
}