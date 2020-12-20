#include <iostream>
#include <cstdlib>

using namespace std;
long long num[200],temp[200];

void mergesort(long long lo, long long hi)
{
    if(lo==hi)
        return;
    int mid = (lo+hi)/2;

    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int i,j,k;
    for(i=0,j=mid+1,k=lo; k<=hi; k++)
    {
        if(i==mid+1)
            temp[k] = num[j++];
        else if(j == hi+1)
            temp[k] = num[i++];
        else if(num[i]<num[j])
            temp[k] = num[i++];
        else
            temp[k] = num[j++];
    }
    for(k=lo; k<=hi; k++)
    {
        num[k]=temp[k];
    }
}

int main()
{
    long long ndata,i;
    cout<< "Enter the number of integer: ";
    cin>> ndata;
    for(i=0; i<ndata; i++)
    {
        num[i] = rand() % ndata;
        cout<<num[i]<< " ";
    }
    cout<<endl;
    mergesort(0, ndata-1);
    cout<< "Sorted Data: "<<endl;
    for(i=0; i<ndata; i++)
    {
        cout<<num[i]<< " ";
    }
    cout<<endl;
    return 0;
}
