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
   int x,n;
   cin>>x>>n;
   priority_queue<int,vector<int>,greater<int>> v;
   loop(0,n){
    int temp;
    cin>>temp;
    v.push(temp);
   };
   int cost=0;
   while(v.size()>1){
    int a=v.top();v.pop();
    int b=v.top();v.pop();
    cost+=a+b;
    v.push(a+b);
   }
   cout<<cost<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}