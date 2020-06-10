#include <stdio.h>
#include <stdlib.h>


int main()
{
    int N, M;
    
    int spin = 1;
    int cnt = 0;
    
    scanf("%d %d", &N, &M);
    
    spin = N + M - 1;
    
    int **array = (int**)malloc(sizeof(int*)*N);
    
    for (int i = 0; i < N; i++)
    {
        array[i] = (int*)malloc(sizeof(int)*M);
        for (int j = 0; j < M; j++)
        {
            array[i][j] = 0;
        }
    }
    
    int num = 0;
    
    for (int mSpin = 0; mSpin <= spin; mSpin++)
    {
        for (int i = 0; i < N; i++)
        {
            int j = mSpin - i;
            
            if ((j < M) && (j >= 0))
            {
                cnt += 1;
                array[i][j] = cnt;
            }
        }
    }
    
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
