#include <stdio.h>
int main() {
    int r,c;
    scanf("%d %d", &r, &c);
    int sum[r][c];
    int mat1[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d",&mat1[i][j]);
        }
    }

    int mat2[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d",&mat2[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    
    printf("Sum of the two matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
