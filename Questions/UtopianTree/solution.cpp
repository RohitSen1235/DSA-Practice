#include <bits/stdc++.h>

using namespace std;

int utopianTree(int n) 
{
    int Height=1;
    
    for( int i=1;i<=n;++i)
    {
        if(i%2==0)
        {
            Height++;
        }
        else
        {
            Height*=2;
        }
    }
    
    return Height;
}

int bin_utopianTree(int n)
{
    return (1<<((n/2)+1))-1<<n%2;
}

int main()
{
    int t;
    cin>>t;
    
    int growthCycles[t];
    
    for( int i=0;i<t;++i)
    {
        cin>>growthCycles[i];
    }
    
    for(int i=0;i<t;++i)
    {
        cout<<bin_utopianTree(growthCycles[i])<<endl;
    }
    
    return 0;
}
