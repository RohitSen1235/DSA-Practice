#include <bits/stdc++.h>

using namespace std;


long int largestRectangle(vector<long int>& h) 
{
    stack<int> S;
    int n = h.size();
    //vector<long int> left(n),right(n);
    long int area=0,max_area=0;
    
    //S.push(0); //initial stack 
    int i;
    for( i=0;i<n;)
    {
        if(S.empty() || h[S.top()]<= h[i])
        {
            S.push(i++);
        }
        else
        {
            int top =S.top();
            S.pop();
            if(S.empty())
            {
                area=h[top]*i;
            }
            else
            {
                area=h[top]*(i-S.top()-1);
            }
            if(max_area<area)
            {
                max_area=area;
            }
        }
    }

    while(!S.empty())
    {
        int top =S.top();
        S.pop();

        if(S.empty())
        {
            area=h[top]*i;
        }
        else
        {
            area=h[top]*(i-S.top()-1);
        }
        if(max_area<area)
        {
            max_area=area;
        }
    }
    return max_area;
}

int main()
{
    int n;
    
    cin>>n;

    vector<long int> h(n);
    
    
    for( int i=0;i<n;i++)
    {
        std::cin>>h[i];
    }

    cout<<largestRectangle(h);
    return 0;
}
