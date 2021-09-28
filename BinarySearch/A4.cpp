#include <bits/stdc++.h>
 
#define FASTIO ios_base::sync_with_stdio(false);
using namespace std;
 
typedef long long ll;
 
ll n, d;
vector<int> nos;
 
 
int s, e;
 
bool isGood(double x){
    // cout << x << endl;
    vector<double> prefArr(n + 1, 0);
    
    for (int i = 0; i < n; i++){
        prefArr[i + 1] = prefArr[i] + nos[i] - x;
    }
    
    // for (auto a: prefArr)
    //     cout << a << " ";
    // cout << endl;
    
    double minEle = 0;
    int ind = 0;
    
    for (int i = d; i <= n; i++){
        if (minEle <= prefArr[i]){
            s = ind + 1; e = i;
            return true;   
        }
        
        if (prefArr[i - d + 1] < minEle){
            ind = i - d + 1;
            minEle = prefArr[i - d + 1];
        }
        
        minEle = min(minEle, prefArr[i - d + 1]);
    }
    
    return false;
    
}
 
int main() {
	// your code goes here
	FASTIO
	
	cin >> n >> d;
	
// 	cout << n << endl;
	
	nos.resize(n);
	
	for (int i = 0; i < n; i++){
	    cin >> nos[i];
	}
	
	double l = 0, r = 1e9, mid;
	
	for (int i = 0; i < 50; i++){
	    mid = (l + r) / 2;
	    if (isGood(mid))
	        l = mid;
	    else
	        r = mid;
	        
	}
	
	isGood(l);
	
	cout << s << " " << e << endl;
	
	return 0;
}