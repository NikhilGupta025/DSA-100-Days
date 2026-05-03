#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, time;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    Node queue[rows * cols];
    int front = 0, rear = 0;

    int fresh = 0;
    int maxTime = 0;

    // Step 1: Add all rotten oranges to queue & count fresh
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j, 0};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Step 2: BFS traversal
    while (front < rear) {
        Node curr = queue[front++];
        int x = curr.x;
        int y = curr.y;
        int time = curr.time;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                grid[nx][ny] = 2; // make it rotten
                fresh--;

                queue[rear++] = (Node){nx, ny, time + 1};

                if (time + 1 > maxTime)
                    maxTime = time + 1;
            }
        }
    }

    // Step 3: Check if any fresh orange left
    if (fresh > 0)
        return -1;

    return maxTime;
}