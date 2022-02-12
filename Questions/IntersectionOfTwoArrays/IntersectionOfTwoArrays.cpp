#include <bits/stdc++.h>

void Intersection(std::vector<int> &Arr, std::vector<int> &Brr)
{
    int n=Arr.size();
    int m=Brr.size();

    std::unordered_set<int> S;

    for( int i=0;i<n;++i)
    {
        S.insert(Arr[i]);
    }
    for( int i=0;i<m;++i)
    {
        if(S.find(Brr[i])!=S.end())
        {
            std::cout<<Brr[i]<<" ";
        }
    }
}

int main()
{   
    int n,m;
    std::cin>>n>>m;
    std::vector<int> A(n),B(m);
    for( int i=0;i<n;++i)
    {
        std::cin>>A[i];
    }
    for( int i=0;i<m;++i)
    {
        std::cin>>B[i];
    }

    Intersection(A,B);
    return 0;
}