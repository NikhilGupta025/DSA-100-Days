#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            
            // 1. Save the top element
            int temp = matrix[i][j];

            // 2. Move left to top
            matrix[i][j] = matrix[n - 1 - j][i];

            // 3. Move bottom to left
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

            // 4. Move right to bottom
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

            // 5. Move top (saved in temp) to right
            matrix[j][n - 1 - i] = temp;
        }
    }

      printf("Rotated Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}