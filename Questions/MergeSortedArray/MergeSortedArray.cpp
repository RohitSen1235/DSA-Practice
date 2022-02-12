#include <iostream>

void swap (int &a,int &b)
{
    int temp =a;
    a=b;
    b=temp;
}
void mergeSortedArray (int m,int Arr[],int n, int Brr[])
{
    swap(m,n);
    int i=n-1;
    int j=m-1;
    int total =n+m-1;

    while(i>=0 &&j>=0)
    {
        //when both i and j are positive, i.e, n and m are >0 
        if(Arr[i]>Brr[j])
        {
            Arr[total--]=Arr[i--];
        }
        else
        {
            Arr[total--]=Brr[j--];
        }
    }
    while(j>=0)
    {
        // when j is positive but i<0, i e m is 0;
        Arr[total--]=Brr[j--];
    }

    for( int i=0;i<n+m;i++)
    {
        std::cout<<Arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    int n,m;

    std::cin>>m>>n;

    int Arr[m+n],Brr[n];

    for( int i=0;i<m;i++)
    {
        std::cin>>Arr[i];
    }
    for(int i=0;i<n;i++)
    {
        std::cin>>Brr[i];
    }

    mergeSortedArray(m,Arr,n,Brr);

    return 0;
}