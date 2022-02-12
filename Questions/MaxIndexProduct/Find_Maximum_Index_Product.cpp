#include <bits/stdc++.h>

using namespace std;

//Brute Force
vector<long int> left (vector<long int> &arr)
{
    int size= arr.size();
    vector<long int> V(size);

    for(int i=0;i<size;++i)
    {
        int j=i;
        while(--j >= 0)
        {
            if(arr[j]>arr[i])
            {
                V[i]=j+1;
                break;
            }
        }

    }

    return V;
}

//Brute Force
vector<long int> right (vector<long int> &arr)
{
    int size= arr.size();
    vector<long int> V(size);

    for(int i=0;i<size;++i)
    {
        int j=i;
        while(++j < size)
        {
            if(arr[j]>arr[i])
            {
                V[i]=j+1;
                break;
            }
        }
        
    }

    return V;
}

//Using Stack
vector<long int> left_Stack (vector<long int> &arr)
{
    int size= arr.size();
    vector<long int> V(size);
    stack<int> stack;
    int i;
    for(i=0;i<size;i++)
    {
        while(!stack.empty() && arr[stack.top()]<=arr[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            V[i]=0;
        }
        else{
            V[i]=stack.top()+1;
        }

        stack.push(i);
    }
    
    return V;
}

//Using Stack
vector<long int> right_Stack (vector<long int> &arr)
{
    int size= arr.size();
    vector<long int> V(size);
    stack<int> stack;
    int i;
    for(i=size-1;i>=0;i--)
    {
        while(!stack.empty() && arr[stack.top()]<=arr[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            V[i]=0;
        }
        else{
            V[i]=stack.top()+1;
        }

        stack.push(i);
    }
    
    return V;
}


long int solve(vector<long int> &arr) 
{
    int size = arr.size();
    vector<long int> Left(size),Right(size);

    Left=left_Stack(arr);
    Right=right_Stack(arr);

    long int IndexProduct=0,product=1;

    for(int i=0;i<size;i++)
    {
        product=Left[i]*Right[i];

        if(IndexProduct<product)
        {
            IndexProduct=product;
        }
    }
    
    return IndexProduct;
}

int main()
{
    int n;
    
    cin>>n;
    
    vector<long int> arr(n);
    //vector<long int> arr ={5,4,3,4,5};
    
    for( int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    
    cout<<solve(arr)<<endl;
    return 0;
}