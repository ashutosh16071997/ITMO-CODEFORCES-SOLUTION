#include <bits/stdc++.h>
 
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
 
typedef long long ll;
 
int n, m;
 
vector<int> parent;
vector<int> sizeVec;
vector<int> exper;
 
 
int _find(int a){
    if (parent[a] == a)
        return a;
    int p = _find(parent[a]);
    if (p != parent[a]){
        exper[a] += exper[parent[a]];
        parent[a] = p;
    }
    return parent[a];
}
 
int getExp(int a){
    int p = _find(a);
    int ex = exper[a];
    if (a != p)
        ex += exper[p];
    return ex;
 
}
 
void _union(int a, int b){
    int pa = _find(a);
    int pb = _find(b);
 
    if (pa == pb)
        return;
 
    if (sizeVec[pa] > sizeVec[pb]){
        parent[pb] = pa;
        sizeVec[pa] += sizeVec[pb];
        exper[pb] -= exper[pa];
    }
    else {
        parent[pa] = pb;
        sizeVec[pb] += sizeVec[pa];
        exper[pa] -= exper[pb];
    }
}
 
void solve(){
    cin >> n >> m;
    parent = vector<int>(n + 1);
    sizeVec = vector<int>(n + 1, 0);
    exper = vector<int>(n + 1, 0);
 
    for (int i =1; i <= n; i++){
        parent[i] = i;
    }
 
    string command;
    int t1, t2;
 
    for (int i = 0; i < m; i++){
        cin >> command;
        if (command == "join"){
            cin >> t1 >> t2;
            _union(t1, t2);
        } else if (command == "add"){
            cin >> t1 >> t2;
            int p = _find(t1);
            exper[p] += t2;
        }
        else {
            cin >> t1;
            cout << getExp(t1)  << endl;
        }
        // cout << "exper:";
        // for (auto a: exper)
        //     cout << a << " ";
        // cout << endl;
        // cout << "parent:";
        // for (auto a: parent)
        //     cout << a << " ";
        // cout << endl << endl;
    }
 
 
}
 
int main(){
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #else 
        FASTIO;
    #endif
 
 
    solve();
 
    return 0;
}
