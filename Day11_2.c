#include <stdio.h>
int main() {
    int i, j, r, c;
    scanf("%d %d",&r,&c);

    int mat[r][c], transpose[r][c];
    for(i = 0; i<r; i++) {
        for(j = 0; j<c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for(i = 0; i<r; i++) {
        for(j = 0; j<c; j++) {
            transpose[j][i] = mat[i][j];
        }
    }
    printf("Transpose of the matrix: \n");
    for(i = 0; i<c; i++) {
        for(j = 0; j<r; j++){
            printf("%2d", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}

    