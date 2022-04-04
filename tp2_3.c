#include<stdio.h>
#include<stdlib.h>

#define N 5
#define M 7

int main() 
{
    int i, j;
    int mt[N][M];
    int *punt_matriz;
    punt_matriz= &mt[0][0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(punt_matriz + (i * M + j))= 1 + rand() % 100;
            printf("%d ", *(punt_matriz + (i * M + j)));
        }
        printf("\n");
    }
    
    getchar();
    return 0;
}