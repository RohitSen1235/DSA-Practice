#include <bits/stdc++.h>

std::vector<int> SmallerElementToLeft(std::vector<int> & arr)
{
    int size=arr.size();
    std::vector<int> left(size);

    std::stack<int> stack;

    for( int i=0;i<size;++i)
    {
        while(!stack.empty() && arr[stack.top()]>=arr[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            left[i]=-1;
        }
        else{
            left[i]=stack.top();
        }

        stack.push(i);
    }
    /*for( int i=0;i<size;++i)
    {
        std::cout<<left[i]<<" ";
    }
    std::cout<<std::endl;*/
    return left;
}

std::vector<int> SmallerElementToRight(std::vector<int> & arr)
{
    int size=arr.size();
    std::vector<int> right(size);

    std::stack<int> stack;

    for( int i=size-1;i>=0;--i)
    {
        while(!stack.empty() && arr[stack.top()]>=arr[i])
        {
            stack.pop();
        }
        if(stack.empty())
        {
            right[i]=size;
        }
        else{
            right[i]=stack.top();
        }

        stack.push(i);
    }
    /*for( int i=0;i<size;++i)
    {
        std::cout<<right[i]<<" ";
    }
    std::cout<<std::endl;*/

    return right; 
}


int largestAreainHistogram(std::vector<int> & arr)
{
    int size =arr.size();
    std::vector<int> left(size),right(size);
    int area=0,max_area=0;

    right=SmallerElementToRight(arr);
    left=SmallerElementToLeft(arr);

    for( int i=0;i<size;++i)
    {
        area=arr[i]*((right[i])-(left[i])-1);

        if(max_area<area)
        {
            max_area=area;
        }
        //std::cout<<area<<" ";
    }
    //std::cout<<std::endl;

    return max_area;
}

int main()
{   
    int n;

    std::cin>>n;

    std::vector<int> histogram(n);

    for( int i=0;i<n;++i)
    {
        std::cin>>histogram[i];
    }

    std::cout<<largestAreainHistogram(histogram)<<std::endl;

    return 0;
}