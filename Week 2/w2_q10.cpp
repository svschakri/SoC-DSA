#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & (-idx);
        }
        return res;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};


void solve() {
    int n,q;
    cin>>n>>q;
    vi rows(n+1),cols(n+1);
    Fenwick rowbit(n),colbit(n);
    while(q--){
        int t,x1,y1;
        cin>>t>>x1>>y1;
        if(t==1){
            if(rows[x1]==0){
                rowbit.add(x1,1);
            }
            rows[x1]++;
            if(cols[y1]==0){
                colbit.add(y1,1);
            }
            cols[y1]++;
        }
        else if(t==2){
            if(rows[x1]==1){
                rowbit.add(x1,-1);
            }
            rows[x1]--;
            if(cols[y1]==1){
                colbit.add(y1,-1);
            }
            cols[y1]--;
        }
        else{
            int x2,y2;
            cin>>x2>>y2;
            bool ans_r=rowbit.rangeSum(x1,x2)==(x2-x1+1);
            bool ans_c=colbit.rangeSum(y1,y2)==(y2-y1+1);
            if(ans_r or ans_c) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}