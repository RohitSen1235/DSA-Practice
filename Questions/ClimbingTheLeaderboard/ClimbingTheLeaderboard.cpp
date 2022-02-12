#include <iostream>
#include <vector>

using namespace std;


vector<int> removeDuplicates(vector<int> sortedArray)
{
    vector<int> result;
    result.push_back(sortedArray.at(0));
    for( int i=1;i<sortedArray.size();++i)
    {
       if(sortedArray.at(i-1)>sortedArray.at(i))
       {
           result.push_back(sortedArray.at(i));
       } 
    }
    
    return result;
}


void selectionSort(vector<int> & inputArray )
{
    for( int i=0;i<inputArray.size()-1;++i)
    {
        for(int j=i+1;j<inputArray.size();++j)
        {
            if(inputArray.at(i)<inputArray.at(j))
            {
                int temp=inputArray.at(j);
                inputArray.at(j)=inputArray.at(i);
                inputArray.at(i)=temp;
            }
        }
    }
}
int BinarySearch(vector<int> sortedArray, int searchElement)
{
    int start=0;
    int end=sortedArray.size();
    int mid;
    while(start<=end)
    {
        mid=(int)(start+end)/2;
        
        if( sortedArray.at(mid)==searchElement)
        {
            return mid;
        }
        else if(sortedArray.at(mid)>searchElement)
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

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) 
{
    vector<int> ranks;
    
    vector<int> currentLeaderBoard;
    
    for( int j=0;j< ranked.size();++j)
    {
        currentLeaderBoard.push_back(ranked.at(j));
    }
    
    for( int i=0;i<player.size();++i)
    {
        
        currentLeaderBoard.push_back(player.at(i));
        
        selectionSort(currentLeaderBoard);
        
        vector<int> uniqueScores = removeDuplicates(currentLeaderBoard);
    
        int temp=BinarySearch(uniqueScores,player.at(i));
        
        ranks.push_back(temp+1);
    
    }
    return ranks;
}

int main()
{
    int n_ranked,n_player;
    
    cin>>n_ranked;
    vector<int> ranked;
    
    for( int i=0;i<n_ranked;++i)
    {
        int temp;
        cin>>temp;
        ranked.push_back(temp);
    }
    
    cin>>n_player;
    vector<int> player;
    
    for(int i=0;i<n_player;++i)
    {
        int temp;
        cin>>temp;
        player.push_back(temp);
    }
    
    vector<int> result=climbingLeaderboard(ranked,player);
    
    for( int i=0;i<result.size();++i)
    {
        cout<<result.at(i)<<endl;
    }
    return 0;
}

