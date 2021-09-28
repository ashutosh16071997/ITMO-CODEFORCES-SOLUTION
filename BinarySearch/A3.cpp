#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
 
int n;
 
vector<ll> pos;
vector<ll> vel;
 
int main() {
	// your code goes here
	cin >> n;
	pos.resize(n);
	vel.resize(n);
	
	for (int i = 0; i < n; i++){
	    cin >> pos[i];
	    cin >> vel[i];
	}
	
	double l = 0, r = 1e9;
	for (int i = 0; i < 100; i++){
	    double mid = (l + r) / 2;
	    double minPos = pos[0] - mid * vel[0];
	    double maxPos = pos[0] + mid * vel[0];
	    for (int i = 1; i < n; i++){
	        minPos = max(minPos, pos[i] - mid * vel[i]);
	        maxPos = min(maxPos, pos[i] + mid * vel[i]);
	    }
	    if (minPos <= maxPos)
	        r = mid;
	    else
	        l = mid;
	}
	
	cout << setprecision(20) << r << endl;
 
	return 0;
}
