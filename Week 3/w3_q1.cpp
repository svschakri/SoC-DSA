#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    vector<int> dur(n),dead(n);
    for(int i=0;i<n;i++){
        cin>>dur[i]>>dead[i];
    }
    sort(dur.begin(),dur.end());
    int sum_dead=0,sum_dur=0,time=0;
    for(int i=0;i<n;i++){
        time+=dur[i];
        sum_dead+=dead[i];
        sum_dur+=time;
    }
    cout<<sum_dead-sum_dur<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}