#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v) for(int i=0;i<v.size();i++) cin>>v[i]
const int INF = 1e18;

int power(int x,int a){
    if(a<=1) return 0;
    int ans=0;
    while(a%x==0){
        ans++;
        a/=x;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    int zero=-1;
    vvi v(n,vi(n));
    loop(0,n){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            if(v[i][j]==0) zero=i;
        }
    }
    vvi dp2(n,vi(n));
    vvi dp5(n,vi(n));
    
    vi pa2(n*n);
    vi pa5(n*n);
    
    
    vector<char> move2(n*n);
    vector<char> move5(n*n);
    
    
    dp2[n-1][n-1]=power(2,v[n-1][n-1]);
    dp5[n-1][n-1]=power(5,v[n-1][n-1]);
    
    for(int i=n-2;i>-1;i--){
        dp2[n-1][i]=dp2[n-1][i+1]+power(2,v[n-1][i]);
        pa2[(n-1)*n+i]=(n-1)*n+i+1;
        move2[(n-1)*n+i]='R';
        dp5[n-1][i]=dp5[n-1][i+1]+power(5,v[n-1][i]);
        pa5[(n-1)*n+i]=(n-1)*n+i+1;
        move5[(n-1)*n+i]='R';
    }
    
    for(int i=n-2;i>-1;i--){
        dp2[i][n-1]=dp2[i+1][n-1]+power(2,v[i][n-1]);
        pa2[(n-1)+i*n]=(n-1)+(i+1)*n;
        move2[(n-1)+i*n]='D';
        dp5[i][n-1]=dp5[i+1][n-1]+power(5,v[i][n-1]);
        pa5[(n-1)+i*n]=(n-1)+(i+1)*n;
        move5[(n-1)+i*n]='D';
    }
    
    for(int i=n-2;i>-1;i--){
        for(int j=n-2;j>-1;j--){
            dp2[i][j]=power(2,v[i][j])+min(dp2[i+1][j],dp2[i][j+1]);
            if(dp2[i][j+1]<=dp2[i+1][j]){
                pa2[i*n+j]=i*n+j+1;
                move2[i*n+j]='R';
            }
            else{
                pa2[i*n+j]=(i+1)*n+j;
                move2[i*n+j]='D';
            }
            dp5[i][j]=power(5,v[i][j])+min(dp5[i+1][j],dp5[i][j+1]);
            if(dp5[i][j+1]<=dp5[i+1][j]){
                pa5[i*n+j]=i*n+j+1;
                move5[i*n+j]='R';
            }
            else{
                pa5[i*n+j]=(i+1)*n+j;
                move5[i*n+j]='D';
            }
        }
    }


    if(zero!=-1 and 1<=min(dp2[0][0],dp5[0][0])){
        cout<<1<<'\n';
        string s="";
        loop(0,zero) s+='D';
        loop(0,n-1) s+='R';
        loop(zero,n-1) s+='D';
        cout<<s<<'\n';
        return;
    }
    
    if(dp2[0][0]<=dp5[0][0]){
        cout<<dp2[0][0]<<'\n';
        string s="";
        for(int k=0;k!=n*n-1;k=pa2[k]){
            s+=move2[k];
        }
        cout<<s<<'\n';
    }
    else{
        cout<<dp5[0][0]<<'\n';
        string s="";
        for(int k=0;k!=n*n-1;k=pa5[k]){
            s+=move5[k];
        }
        cout<<s<<'\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}