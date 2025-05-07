#include <stdio.h>

void exploreIsland(char** map, int totalRows, int* rowLengths, int x, int y) {
    if (x < 0 || x >= totalRows || y < 0 || y >= rowLengths[x] || map[x][y] == '0')
        return;

    map[x][y] = '0';

    exploreIsland(map, totalRows, rowLengths, x - 1, y);
    exploreIsland(map, totalRows, rowLengths, x + 1, y);
    exploreIsland(map, totalRows, rowLengths, x, y - 1);
    exploreIsland(map, totalRows, rowLengths, x, y + 1);
}

// counts the number of islands in the map
int numIslands(char** map, int totalRows, int* rowLengths) {
    int count = 0;

    for (int row = 0; row < totalRows; row++) {
        for (int col = 0; col < rowLengths[row]; col++) {
            if (map[row][col] == '1') {
                count++;
                exploreIsland(map, totalRows, rowLengths, row, col);
            }
        }
    }

    return count;
}