#include <iostream>
#include <vector>

using namespace std;

void print(int n,int input[])
{
    //for debugging only
    for(int i=0;i<n;++i)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

int BinarySearch(int n,int sortedArray[], int searchElement)
{
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        
        if( searchElement==sortedArray[mid])
        {
            return mid;
        }
        else if(searchElement>sortedArray[mid] && searchElement<sortedArray[mid-1])
        {
            return mid;
        }
        else if(searchElement<sortedArray[mid] && searchElement>=sortedArray[mid+1])
        {
            return mid +1;
        }
        else if(searchElement<sortedArray[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    
    return -1;
}

int climbingLeaderboard(int n_ranked,int n_player,int ranked[], int player[], int* &playerRanks) 
{
    int ranks[n_ranked];
    
    ranks[0]=1;
    for( int i=1;i<n_ranked;++i)
    {
        if(ranked[i]==ranked[i-1])
        {
            ranks[i]=ranks[i-1];
        }
        else
        {
            ranks[i]=ranks[i-1]+1;
        }
    }
    
    print(n_ranked,ranks);

    for(int i=0;i<n_player;++i)
    {
        if(player[i]>ranked[0])
        {
            playerRanks[i]=1;
        }
        else if (player[i]<ranked[n_ranked-1])
        {
            playerRanks[i]=ranks[n_ranked-1] +1;
        }
        else
        {
            //binary search
            int index = BinarySearch(n_ranked,ranked,player[i]);
            playerRanks[i]=ranks[index];
        }
    }
    return 0;
}

int main()
{
    int n_ranked,n_player;
    
    cin>>n_ranked;
    int ranked[n_ranked];
    
    for( int i=0;i<n_ranked;++i)
    {
        cin>>ranked[i];
    }
    
    cin>>n_player;
    int player[n_player];
    
    for(int i=0;i<n_player;++i)
    {
        cin>>player[i];
    }
    int* result =new int[n_player];
    climbingLeaderboard(n_ranked,n_player,ranked,player,result);
    
    for( int i=0;i<n_player;++i)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}

