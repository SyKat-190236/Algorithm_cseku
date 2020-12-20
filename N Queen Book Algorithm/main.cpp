#include <iostream>
#include <cmath>

using namespace std;

int x[9]={0,0,0,0,0,0,0,0,0};

bool Place(int k, int j)
{
    for(int i=1; i<=k-1; i++)
    {
        if((x[i]==j)||(abs(x[i]-j)==abs(i-k)))
            return false;
    }
    return true;
}
void NQueen(int k,int n)
{
    for(int j=1; j<=n; j++)
    {
        if(Place(k,j))
        {
            x[k]=j;
            if(k==n)
            {
                for(int i=1; i<=8; i++)
                {
                    cout<<x[i]<<" ";
                }
                cout<<endl;
            }
            else
            {
                NQueen(k+1,n);
            }
        }
    }
}

int main()
{
    NQueen(1,8);

    return 0;
}
