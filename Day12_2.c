#include <stdio.h>
int main() 
{
    int r,c,i,j;
    int mat[100][100];
    scanf("%d %d",&r,&c);

    for(i=0; i<r;i++) 
    {
        for(j=0; j<c; j++) 
        {
            scanf("%d",&mat[i][j]);
        }
    }
    int temp=1;
    for(i=0; i<r-1; i++) 
    {
        for(j=0; j<c-1; j++) 
        {
            if(mat[i][j] == mat[i+1][j+1])
            {
                temp = 0;
            }
            else
            {
                temp = 1;
            }
        }
    }
    if(temp == 0) 
    {
        printf("Toeplitz matrix");
    }
    else
    {
        printf("Not a toeplitz matrix");
    }

}