#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int n,c;
    cin>>n>>c;
    vi v(n);
    input(v,n);
    // for calulating tot
    // for every a from 0,c add (a+1)(c-a+1)
    // it is same as cal from 0,c+1 a*(c+2-a)== a*c+a*2-a*a
    // c+1*c+2*c/2+c+1*c+2-((c+1)*(c+2)*(2*c+3))/6
    // see what is wrong in process
    int tot=0;
    // for every element a sub c-a+1;
    // for every element a sub a-(a+1)/2 +1;
    // means totally sub c+2-(a+1)/2
    // add n*(n-1)/2
    int odd=0,even=0;
    for (auto a: v){
        tot-=(c+1-a);
        tot-=(a/2+1);
        if(a%2==0) even++;
        else odd++;
    }
    tot+=(odd*(odd+1))/2;
    tot+=(even*(even+1))/2;
    tot+=((c+1)*(c+2))/2;
    cout<<tot<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}