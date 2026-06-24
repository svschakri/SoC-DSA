#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

struct Range {
    int l, r, idx;
};



void solve(){
    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> rights;

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
        rights.push_back(ranges[i].r);
    }

    // coordinate compression
    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    auto compress = [&](int x) {
        return lower_bound(rights.begin(), rights.end(), x) - rights.begin() + 1;
    };

    sort(ranges.begin(), ranges.end(),
         [](const Range &a, const Range &b) {
             if (a.l == b.l) return a.r > b.r;
             return a.l < b.l;
         });

    vector<int> contains(n), contained(n);

    int m = rights.size();

    // contains
    Fenwick bit1(m);

    for (int i = n - 1; i >= 0; i--) {
        int x = compress(ranges[i].r);

        contains[ranges[i].idx] = bit1.query(x);

        bit1.update(x, 1);
    }

    // contained by
    Fenwick bit2(m);

    for (int i = 0; i < n; i++) {
        int x = compress(ranges[i].r);

        contained[ranges[i].idx] =
            i - bit2.query(x - 1);

        bit2.update(x, 1);
    }

    for (int x : contains) cout << x << ' ';
    cout << '\n';

    for (int x : contained) cout << x << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    
}