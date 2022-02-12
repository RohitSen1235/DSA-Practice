#include<iostream>

using namespace std;

int factorial(int num)
{
    int product=1;
    for( int i=2;i<=num;++i)
    {
        product*=i;
    }
    return product;
}

int f(int num)
{
    //calculates the sum of factorial of each digit in num;
    //Ex: num=342 => f(num)=3!+4!+2! =32
    int sum=0;
    while(num>0)
    {
        sum+=factorial(num%10);
        num=num/10;
    }
    
    return sum;
}

int sf(int num)
{
    //calculates the sum of digits in result of f(num)
    //Ex: num =342 => f(num)= 32 => sf(num)= 3+2 =5
    int factorial_sum=f(num);
    int sum=0;
    while(factorial_sum>0)
    {
        sum+= factorial_sum%10;
        factorial_sum=factorial_sum/10;
    }
    return sum;
}

int g(int num)
{   
    //not corrent function
    for( int i=0;i<10000;++i)
    {
        if(sf(i)==num)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    /*int q,n,m;

    for(int i=0;i<q;++i)
    {
        cin>>n>>m;

    }*/
    int n;
    cin>>n;
    int res=sf(n);
    cout<<" => "<<res<<endl;
    int res2=g(15);
    cout<<res2<<endl;
}