/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5 : Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 3 Juni 2026
 *   Nama (NIM)          :Audrin NAufal Fikri Frederick (13224044)
 *   Nama File           : Pulau Roblox.c
 *   Deskripsi           : Membuat Grid berukuran R x C. Tiap grid dapat berisi 0(tidak ada) / 1(pulau). Apabila terdapat grid berisi 1 dengan posisi bersebelahan (nempel atas,bawah,kanan,kiri) dengan grid 1 lainnya,
 *                         maka Grid tersebut saling terhubung membentuk pulau yang lebih besar. Program yang dibuat akan menerima R x C(yg merupakan ukuran grid), baris1,baris2,barisn.
 *                         Memberikan keluaran ISLAND (jumlah PUlau), LARGEST (ukuran pulau terbesar).
 * 
 */
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
                    largest = size-1;
            }
        }
    }

    printf("ISLANDS %d\n", islands);
    printf("LARGEST %d\n", largest);

    return 0;
}
