#include <bits/stdc++.h>

void nearestSmallElementToLeft(std::vector<int> & arr)
{
    int size= arr.size();
    std::vector<int> V(size);
    //stack should have indexes of the elements to the left
    std::stack<int> stack;
    for(int i=0;i<size;++i)
    {
        while(!stack.empty() && arr[stack.top()]>= arr[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            //element smaller than  i-th element does not exist to the left
            V[i]=-1;
        }
        else{
            //element smaller than i-th element exists
            //index of element is printed out
            V[i]=stack.top();
        }

        // index is pushed to the stack, for analysis of next elements
        // in case i-th element is less than the next (i+1)th element
        stack.push(i);
    }
    for( int i=0;i<size;++i)
    {
        std::cout<<V[i]<<" ";
    }
    std::cout<<std::endl;
}

void nearestSmallElementToRight(std::vector<int> &arr)
{
    int size=arr.size();
    std::vector<int> V(size);
    //stack should have indexes of elements to the right 
    std::stack<int> stack;

    for( int i=size-1;i>=0;--i)
    //for(int i=0;i<size;++i)
    {
        while(!stack.empty() && arr[stack.top()]>=arr[i])
        {    
            //pop elements from the stack till we find an element < i-th element
            stack.pop();
        }
        if(stack.empty())
        {
            //stack empty means there is no element to the right < i-th element
            V[i]=-1;
        }
        else{
            //stack not empty, means we found an element < i-th element
            V[i]=stack.top();
        }

        //push current element to the stack 
        stack.push(i);
    }
    for( int i=0;i<size;++i)
    {
        std::cout<<V[i]<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    int n;

    std::cin>>n;

    std::vector<int> arr(n);

    for( int i=0;i<n;++i)
    {
        std::cin>>arr[i];
    }

    std::cout<<"L:";
    nearestSmallElementToLeft(arr);
    std::cout<<"R:";
    nearestSmallElementToRight(arr);

    return 0;
}
