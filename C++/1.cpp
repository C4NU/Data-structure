#include <iostream>
using namespace std;

int main()
{
    int C;
    int j = 0;
    int N[1000]={0,};
    int Array[1000]={0,};
    float avg = 0;
    float ArrayAvg[1000]={0,};
    int lastindex = 0;
    
    scanf("%d", &C);
    
    for(int i=0; i<C; i++)
    {
        scanf("%d", &N[i]);
        
        for(j = lastindex; j<N[i]+lastindex; j++)
        {
            scanf("%d", &Array[j]);
        }
        
        lastindex = j;
    }1
    
    for(int i=0; i<C; i++)
    {
        for(int j=0; j<N[i]; j++)
        {
            avg += Array[j];
        }
        ArrayAvg[i] = avg /= N[i];
        avg = 0;
    }
    
    for(int i=0; i<C; i++)
    {
    
    }
}
