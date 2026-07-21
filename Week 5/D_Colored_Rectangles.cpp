#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v) for(int i=0;i<v.size();i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int r,b,g;
    cin>>r>>b>>g;
    vi red(r),blue(b),green(g);
    input(red);
    input(blue);
    input(green);
    sort(red.rbegin(),red.rend());
    sort(blue.rbegin(),blue.rend());
    sort(green.rbegin(),green.rend());

    int l1=0,l2=0,l3=0;
    int tot=0;
    while(true){
        if(l1<r and l2<b and l3<g){
            int temp=min({red[l1],blue[l2],green[l3]});
            if(red[l1]=temp){
                tot+=blue[l2++]*green[l3++];  
            }
            else if(blue[l2]=temp){
                tot+=red[l1++]*green[l3++];  
            }
            else if(green[l3]=temp){
                tot+=blue[l2++]*red[l1++];  
            }
        }
        else if(l1<r and l2<b){
            tot+=blue[l2++]*red[l1++];  
        }
        else if(l3<g and l2<b){
            tot+=blue[l2++]*green[l3++];  
        }
        else if(l1<r and l3<g){
            tot+=green[l3++]*red[l1++];  
        }
        else break;
    }
    cout<<tot<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}