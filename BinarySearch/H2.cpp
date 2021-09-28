#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<int> recipe(26, 0);
vector<int> available(3, 0);
vector<int> prices(3, 0);
ll budget;
 
bool isGood(ll x){
    
    ll b = max(x * recipe[1] - available[0], 0LL);
    ll c = max(x * recipe[2] - available[2], 0LL);
    ll s = max(x * recipe['S' - 'A'] - available[1], 0LL);
    
    ll total = b * prices[0] + c * prices[2] + s * prices[1];
    
    return total <= budget;
    
}
 
 
int main() {
	// your code goes here
	string recipeS;
	
	cin >> recipeS;
	
	for (int i = 0; i < recipeS.length(); i++){
	    recipe[recipeS[i] - 'A'] += 1;
	}
	
	for (int i = 0; i < 3; i++){
	    cin >> available[i];
	}
	
	for (int i = 0; i < 3; i++){
	    cin >> prices[i];
	}
	
	cin >> budget;
	
	ll l = 0, r = 1e14, ans = 0;
	
	while (l < r){
	    ll mid = (l + r) / 2;
	    if (isGood(mid)){
	        ans = mid;
	        l = mid + 1;
	    } else 
	        r = mid;
	}
	
	cout << ans << endl;
	
	return 0;
}
