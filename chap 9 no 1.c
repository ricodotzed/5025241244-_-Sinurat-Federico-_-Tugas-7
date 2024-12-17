#include <stdio.h>


int is_grid(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

int blob_check(int grid[5][5], int x, int y) {
    if (!is_grid(x, y) || grid[x][y] == 0) {
        return 0;
    }

    grid[x][y] = 0;
    int blob_size = 1;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        blob_size += blob_check(grid, x + dx[i], y + dy[i]);
    }

    return blob_size;
}

int main() {
    int grid[5][5];
    int x, y;

    printf("Enter the grid values (0 or 1) for a %dx%d grid:\n", 5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter the coordinates (x y) of the cell to check the blob size: ");
    scanf("%d %d", &x, &y);

    int size = blob_check(grid, x, y);
    printf("The size of the blob at (%d, %d) is: %d\n", x, y, size);

    return 0;
}