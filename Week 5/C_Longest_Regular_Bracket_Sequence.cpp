#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void saturate(string& s){
    int l=-1,r=-1;
    for(int i=0;i<(long long)s.size();i++){
        if(s[i]==')') r=i;
        if(s[s.size()-i-1]=='(') l=s.size()-i-1;
    }
    if(l==-1 or r==-1){
        s="";
        return;
    }
    string t="";
    for(int i=l;i<=r;i++){
        t+=s[i];
    }
    s=t;
}

void solve() {
    string s;
    cin>>s;
    saturate(s);
    int size=0,cnt=0;
    int window=0,l=0,r=0;
    while(r<(long long)s.size()){
        if(s[r]=='(') window++;
        else window--;
        if(window<0){
            r++;
            l=r;
            window=0;
        }
        else if(window==0){
            if(r-l+1>size){
                size=r-l+1;
                cnt=1;
            }
            else if(r-l+1==size) {
                cnt++;
            }
            r++;
        }
        else r++;
    }
    int a=false;
    if(window>0) a=true;
    while(r>l){
        if(s[l]=='('){
            window--;
        }
        else window++;
        if(window==0){
            if(r-l>size and a){
                size=r-l;
                cnt=1;
            }
            else if(r-l==size and a) cnt++;
        }
        l++;
    }
    if(r-l>size){
        size=r-l;
        cnt=1;
    }
    else if(r-l==size) cnt++;
    if(size==0) cnt=1;
    cout<<size<<' '<<cnt<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}