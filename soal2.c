#include <stdio.h>

#define MAX 100

int R, C;
char grid[MAX][MAX + 1];
int visited[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dfs(int r, int c) {
    visited[r][c] = 1;
    int size = 1;

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < R &&
            nc >= 0 && nc < C &&
            !visited[nr][nc] &&
            grid[nr][nc] == '1') {

            size += dfs(nr, nc);
        }
    }

    return size;
}

int main(void) {
      scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
    }

    int islands = 0;
    int largest = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            if (grid[i][j] == '1' && !visited[i][j]) {
                islands++;

                int size = dfs(i, j);

                if (size > largest)
                    largest = size;
            }
        }
    }

    printf("ISLANDS %d\n", islands);
    printf("LARGEST %d\n", largest);
    
    return 0;
}
