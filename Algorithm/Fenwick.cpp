//------------fenwick--------------
template<typename T>
struct Fenwick{
// Declaration - Fenwick<ll> f(n);
private:
    ll n;
    vector<T> bit[2];
public:
    Fenwick(){
    }
    Fenwick(ll maxn){
        n = maxn;
        bit[0] = vector<T>(n+100,0);
        bit[1] = vector<T>(n+100,0);
    }
    void add(ll tree, ll idx, T x){
        while(idx<=n){
            bit[tree][idx]+=x, idx+= (idx & (-idx));
        }
    }
    void range_add(ll l, ll r, T x){
        add(0,l,x);
        add(0,r+1,-x);
        add(1,l,x*(l-1));
        add(1,r+1,-x*r);
    }
    T sum(ll tree, ll idx){
        T total = 0;
        while(idx>0){
            total+=bit[tree][idx];
            idx -= (idx & (-idx));
        }
        return total;
    }
    T prefix_sum(ll idx){
        return sum(0,idx)*idx - sum(1,idx);
    }
    T range_sum(ll l, ll r){
        return prefix_sum(r) - prefix_sum(l-1);
    }
};
