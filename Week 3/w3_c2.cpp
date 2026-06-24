#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int,int>
#define loop(s,n) for(int i=s;i<n;i++)
#define input(v,n) for(int i=0;i<n;i++) cin>>v[i]
const int INF = 1e18;

void solve() {
    int n,k;
    cin>>n>>k;
    int rounds=n;
    int seats[k][k];
    for(int i=0;i<k;i++) for(int j=0;j<k;j++) seats[i][j]=0;
    while(rounds--){
        int temp;
        cin>>temp;
        vector<pi> rows(k);
        int best=INF,row_val=-1;
        for(int i=0;i<k;i++){// for each row
            int least=INF;
            int j_val=-1;
            for(int j=0;j<k+1-temp;j++){// for each col
                int val=0;
                for(int l=j;l<j+temp;l++){
                    val+=abs((k+1)/2-l-1)+abs((k+1)/2-i-1);
                    if(seats[i][l]==1){
                        val=INF;
                        break;
                    }
                }
                if(val<least){
                    least=val;
                    j_val=j;
                }
            }
            if(least<best){
                best=least;
                row_val=i;
            }
            rows[i]={least,j_val};
        }
        if(best==INF){
            cout<<-1<<'\n';
            continue;
        }
        // cout<<rows.size()<<" "<<row_val<<" "<<rows[row_val].second<<'\n';
        for(int j=rows[row_val].second;j<rows[row_val].second+temp;j++){
            // cout<<seats[row_val][j]<<' ';
            seats[row_val][j]=1;
            // cout<<seats[row_val][j]<<'\n';
        }
        cout<<row_val+1<<" "<<rows[row_val].second+1<<" "<<rows[row_val].second+1+temp-1<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        solve();

    return 0;
}