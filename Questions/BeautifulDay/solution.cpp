#include <bits/stdc++.h>

using namespace std;

int reverse(int num)
{
    int rev=0;
    while(num>0)
    {
        rev= rev*10 + num%10 ;
        num =num/10;
    }
    return rev;
}

int beautifulDays(int i, int j, int k) 
{
    int count=0;
    for(int num=i;num<=j;num++)
    {
        int delta=abs(num-reverse(num));

        if(delta%k==0)
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    int i,j,k;
    
    cin>>i>>j>>k;
    
    cout<<beautifulDays(i, j, k);
    
    return 0;
}
