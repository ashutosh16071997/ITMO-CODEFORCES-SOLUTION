#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
string t, p;
vector<int> permute;
 
 
bool isGood(int n){
    string s2 = t;
    string temp = "";
    for (int i = 0; i < n; i++){
        s2[permute[i] - 1] = '0';
    }
    for (int i = 0; i < s2.length(); i++){
        if (s2[i] != '0')
            temp += s2[i];
    }
    // cout << temp << endl;
    int j = 0;
    for (int i = 0; i < temp.length() && j < p.length(); i++){
        if (p[j] == temp[i])
            j++;
    }
    
    return j == p.length();
    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> t >> p;
    
    int n = t.length();
    permute.resize(n);
    
    for (int i = 0; i < n; i++){
        cin >> permute[i];
    }
    
    int l = 0, r = n;
    
    while (l + 1 < r){
        int mid = (l + r) / 2;
        if (isGood(mid)){
            l = mid;
        } else
            r = mid;
            
        // cout << l << " " << r << endl;
    }
    
    cout << l << endl;
    
    
	
	
}

