#include <iostream>
#include <vector>

std::vector<std::vector<int>> PascalsTriangle_wrong(int nRows)
{
    std::vector<std::vector<int>> pT;
    int num=1;
    int count =0;

    while(count<nRows)
    {
        int currentNum=num;
        std::vector<int> temp;
        
        while(currentNum>0)
        {
            int digit=currentNum%10;

            temp.push_back(digit);

            currentNum/=10;
        }
        count++;
        pT.push_back(temp);
        num*=11;

    }

    return pT;
}

std::vector<std::vector<int>> PascalsTriangle(int nRows)
{
    std::vector<std::vector<int>> pT(nRows);
    
    for(int i=0;i<nRows;++i)
    {
        pT[i].resize(i+1);
        pT[i][0]=pT[i][i]=1;
        for(int j=1;j<i;++j)
        {
            pT[i][j]=pT[i-1][j-1]+pT[i-1][j];
        }
    }
    
    return pT;
}

int main ()
{
    int nRows=12;
    
    std::vector<std::vector<int>> Triangle;
    
    //Triangle=PascalsTriangle_wrong(nRows);
    Triangle=PascalsTriangle(nRows);

    for( int i=0;i<Triangle.size();++i)
    {
        for( int j=0;j<Triangle[i].size();++j)
        {
            std::cout<<Triangle[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;

}