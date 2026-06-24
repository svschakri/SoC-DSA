#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
int main(){
    int n,sum=0;
    cin>>n;
    vector<int> memo(n+1);
    memo[0]=0;
    for(int i=1;i<n+1;i++){
        if(i<7){
            memo[i]=1+sum;
            sum+=memo[i];
        }
        else{
            memo[i]=sum%MOD;
            sum=(sum%MOD+(memo[i]%MOD-memo[i-6]%MOD)%MOD)%MOD;
        }
    }
    cout<<(memo[n]%MOD+MOD)%MOD<<'\n';
}
