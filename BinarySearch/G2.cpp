#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
 
int k, n;
vector<ll> students;
 
 
bool isGood(ll x){
    ll total = x * k;
    
    for (int i = 0; i < n; i++){
        total -= min(students[i], x);
    }
    
    return total <= 0;
    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> k >> n;
    
    students.resize(n);
    for (int i = 0; i < n; i++){
        cin >> students[i];
    }
    
    ll l = 0, r = 1e15, mid, ans = 0;
    
    while (l < r){
        mid = (l + r) / 2;
        if (isGood(mid)){
            ans = mid;
            l = mid + 1;
        } else
            r = mid;
            
            
        // cout << l << " " << r << endl;   
    }
    
    
    cout << ans << endl;
	
	
}
