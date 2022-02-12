#include <iostream>
#include <string.h>

class Leaderboard
{
    int _n;
    int _m;
    int* _leaderboard;
    int* _playerscores;
    int* _playerRanks;

    void PRINT(int* &);

public:
    Leaderboard()
    {

    }
    Leaderboard(int n, int m, int ranked[],int player[])
    {
        _n=n;
        _m=m;
        _leaderboard =new int[n];
        memcpy(_leaderboard,ranked,sizeof(int)*n);
        _playerscores= new int[m];
        memcpy(_playerscores,player,sizeof(int)*m);
        _playerRanks =new int[m];
    }
    int BinarySearch(int );

    void ClimbingTheLeaderboard();
};

void Leaderboard::PRINT(int* & input)
{
    for(int i=0;i<_m;++i)
    {
        std::cout<<input[i]<<std::endl;
    }
}
int Leaderboard::BinarySearch(int searchElement)
{
    int start=0;
    int end=_n-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        
        if( searchElement==_leaderboard[mid])
        {
            return mid;
        }
        else if(searchElement>_leaderboard[mid] && searchElement<_leaderboard[mid-1])
        {
            return mid;
        }
        else if(searchElement<_leaderboard[mid] && searchElement>=_leaderboard[mid+1])
        {
            return mid +1;
        }
        else if(searchElement<_leaderboard[mid])
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

void Leaderboard::ClimbingTheLeaderboard()
{
    int ranks[_n];
    
    ranks[0]=1;
    for( int i=1;i<_n;++i)
    {
        if(_leaderboard[i]==_leaderboard[i-1])
        {
            ranks[i]=ranks[i-1];
        }
        else
        {
            ranks[i]=ranks[i-1]+1;
        }
    }
    
    //PRINT(ranks);

    for(int i=0;i<_m;++i)
    {
        if(_playerscores[i]>_leaderboard[0])
        {
            _playerRanks[i]=1;
        }
        else if (_playerscores[i]<_leaderboard[_n-1])
        {
            _playerRanks[i]=ranks[_n-1] +1;
        }
        else
        {
            //binary search
            int index = BinarySearch(_playerscores[i]);
            _playerRanks[i]=ranks[index];
        }
    }

    PRINT(_playerRanks);
}

int main()
{
    int n_ranked,n_player;
    
    std::cin>>n_ranked;
    int ranked[n_ranked];
    
    for( int i=0;i<n_ranked;++i)
    {
        std::cin>>ranked[i];
    }
    
    std::cin>>n_player;
    int player[n_player];
    
    for(int i=0;i<n_player;++i)
    {
        std::cin>>player[i];
    }
    int* result =new int[n_player];
    Leaderboard obj(n_ranked,n_player,ranked,player);
    obj.ClimbingTheLeaderboard();
    
    return 0;
}