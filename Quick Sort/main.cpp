#include <iostream>
#include <cstdlib>

using namespace std;

int a[10000000];
long long num_shifted=0,num_comparision=0;

long long makepart(int a[], long long first, long long last)
{
    long long part_value=a[first];
    long long i=first;
    long long j=last;
    do
    {
        do
        {
            i=i+1;
            num_comparision++;
        }while(a[i]<part_value);
        do
        {
            j=j-1;
            num_comparision++;
        }while(a[j]>part_value);
        if(i<j)
        {
            swap(a[i],a[j]);
            num_shifted++;

        }
    }while(i<j);
    a[first]=a[j];
    a[j]=part_value;
    num_shifted++;
    return j;
}

void quicksort(long long f, long long l)
{
    long long j;
    if(f<l)
    {
        j=makepart(a,f,l+1);
        quicksort(f,j-1);
        quicksort(j+1,l);
    }
}

int main()
{
    long long i,n;
    cout<< "Enter the number of integer: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        a[i] = rand()%n+1;
        cout<< a[i]<< " ";
    }
    quicksort(0,n-1);
    cout<< "\nSorted Data is : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<< a[i]<< " ";
    }
    cout<<endl;
    cout<< "Number of data shifted : "<<num_shifted<<endl;
    cout<< "Number of data compared : : "<<num_comparision<<endl;
    return 0;
}
