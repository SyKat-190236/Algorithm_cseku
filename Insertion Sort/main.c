#include <stdio.h>
#include <stdlib.h>
int main() {
    long num[100],x,i,j,nos=0;
    for(i=0; i<100; i++)
    {
        if(rand()<0)
        {
            num[i] =(-rand()) % 100;
        }
        else{
            num[i] =rand() % 100;
        }
    }
    for(i=0; i<100; i++)
    {
        x = num[i];
        j = i - 1;
        while(i>=0 && num[j]>x)
        {
            num[j+1] = num[j];
            nos++;
            j--;
        }
        num[j+1] = x;
    }
    printf("%ld\n\n",nos);
    for(i=0; i<100; i++)
    {
        printf("%ld, ",num[i]);
    }
    return 0;
}
