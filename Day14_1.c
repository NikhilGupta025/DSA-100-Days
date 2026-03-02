#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int isIdentity = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if( i == j && a[i][j] != 1)
            {
                isIdentity = 0;
                break;
            }
           else if (i != j && a[i][j] != 0)
           {
                isIdentity = 0;
                break;
            }
        }
        if (isIdentity == 0) {
            break;
        }
    }
    if (isIdentity == 1) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is NOT an Identity Matrix.\n");
    }
    return 0;
    
}