#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();
int n, m, d;

pair<bool, vector<int>> chk(int mid, vector<vector<pair<int,int>>>& adj, bool f){
    int n = adj.size();
    vector<int> par(n, -1);
    vector<bool> vis(n, false);
    queue<int> pq;
    pq.push(0);
    vis[0] = 1;
    int cnt = 0;
    if(d == 0)
        return {false, {}};

    while(!pq.empty()){
        int zzz = pq.size();
        while(zzz--){
            auto u = pq.front();
            pq.pop();
            if(u == n-1)
                break;
            for(auto &zz: adj[u]){
                // cout << zz.first << endl;
                if(zz.second > mid)
                    continue;
                if(!vis[zz.first]){
                    vis[zz.first] = 1;
                    par[zz.first] = u;
                    pq.push(zz.first);
                }
            }
        }
        cnt++;
        // cout << endl << endl;
        if(cnt == d)
            break;
    }

    if(par[n-1] == -1)
        return {false, {}};

    if(!f)
        return {true, {}};

    // for(int i: par)
    //     cout << i << " ";
    vector<int> res;
    int j=n-1;
    while(j!=0){
        res.push_back(j);
        j=par[j];
    }
    res.push_back(0);
    reverse(res.begin(), res.end());

    // for(int i: res)
    //     cout << i << " ";
    return {1,res};
}

void solve(int tc = 1){
    cin >> n >> m >> d;
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back({y, z});
    }

    int l = 0, r = INT_MAX;
    vector<int> res;

    while(l < r){
        int mid = l + (r-l)/2;
        auto z = chk(mid, adj, 0);
        if(z.first){
            r = mid;
        }
        else
            l = mid+1;
    }

    // chk(4, adj, 1);

    if(r == INT_MAX){
        cout << -1 << endl;
        return;
    }

    auto z = chk(r, adj, 1);

    cout << z.second.size()-1 << endl;
    for(int i: z.second)
        cout << i+1 << " ";
}
 
signed main(){
    init();
    int t = 1;
    //cin >> t;
 
    for(int i=1; i<=t; i++){
        solve(i);
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}
