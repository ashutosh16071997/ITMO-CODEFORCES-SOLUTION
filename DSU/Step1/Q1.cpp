#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
vector<long long int>p;
vector<long long int>r;
int findset(int val)
{
    if(val == p[val])
    return val;
    return p[val] = findset(p[val]);

}
bool issame(long long int a,long long int b)
{
    long long int val1 = findset(a);
    long long int val2 = findset(b);
    return val1 == val2;
}
void unionSet(long long int a, long long int b)   {
    if ( !issame(a, b))          
    { long long int x = findset(a); 
      long long int y = findset(b);
      if (r[x] > r[y])   
               p[x] = y;
      else {                   
             p[x] = y;
            if (r[x] == r[y])       
              r[y] ++;
               } 
    }
  }

int main()
{
    cin>>n>>m;
    p.resize(n+1,0);
    r.resize(n+1,0);
    for(int i = 0;i<n+1;i++)
    p[i] = i;
    while(m--)
    {
        string str;long long int a;long long int b;
        cin>>str>>a>>b;
        if (str == "union")
        {
            unionSet(a,b);
        }
        
    else
     {
         if(issame(a,b))
          cout<<"YES"<<endl;
        else
          cout<<"NO"<<endl;
     }
    }
    return 0;
}
