#include<bits/stdc++.h>
using namespace std;



bool good(int n, int k, vector<pair<ll,ll>>& v, ll M) {
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (M > v[i].second) {
            count += min(v[i].second, M) - v[i].first + 1;
        } else if (M > v[i].first) {
            count += M - v[i].first;
        }
    }

    return count <= k;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    ll L = -1e10;
    ll R = 1e10;
    while (R > L + 1) {
        ll M = (L + R) / 2;
        if (good(n, k, v, M)) {
            L = M;
        } else {
            R = M;
        }
    }

    cout << L << endl;

    return 0;
}