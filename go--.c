#include <stdio.h>
#include <string.h>

#define MAXN 500

char board[MAXN][MAXN]; // Tabuleiro NxN
int black_prefix[MAXN + 1][MAXN + 1];
int white_prefix[MAXN + 1][MAXN + 1];
int n, p;

// Function to calculate the number of stones in a given sub-area using prefix sums
int countStonesInArea(int prefix[MAXN + 1][MAXN + 1], int row1, int col1, int row2, int col2) {
    return prefix[row2][col2] - prefix[row1 - 1][col2] - prefix[row2][col1 - 1] + prefix[row1 - 1][col1 - 1];
}

int main() {
    scanf("%d %d", &n, &p);
    
    // Initialize the board and prefix sum arrays
    memset(board, '.', sizeof(board));
    memset(black_prefix, 0, sizeof(black_prefix));
    memset(white_prefix, 0, sizeof(white_prefix));

    // Read the positions of black stones
    for (int i = 0; i < p; i++) {
        int l, c;
        scanf("%d %d", &l, &c);
        board[l - 1][c - 1] = 'P';  // Mark black stone
    }

    // Read the positions of white stones
    for (int i = 0; i < p; i++) {
        int l, c;
        scanf("%d %d", &l, &c);
        board[l - 1][c - 1] = 'B';  // Mark white stone
    }

    // Build prefix sums for black and white stones
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            black_prefix[i][j] = black_prefix[i - 1][j] + black_prefix[i][j - 1] - black_prefix[i - 1][j - 1];
            white_prefix[i][j] = white_prefix[i - 1][j] + white_prefix[i][j - 1] - white_prefix[i - 1][j - 1];
            if (board[i - 1][j - 1] == 'P') black_prefix[i][j]++;
            if (board[i - 1][j - 1] == 'B') white_prefix[i][j]++;
        }
    }

    int black_areas = 0;
    int white_areas = 0;

    // Count sub-areas for each size
    for (int size = 1; size <= n; size++) {
        for (int i = 1; i <= n - size + 1; i++) {
            for (int j = 1; j <= n - size + 1; j++) {
                // Calculate the number of stones in the current sub-area
                int total_black = countStonesInArea(black_prefix, i, j, i + size - 1, j + size - 1);
                int total_white = countStonesInArea(white_prefix, i, j, i + size - 1, j + size - 1);
                
                // If only black stones are present in this sub-area
                if (total_black > 0 && total_white == 0) {
                    black_areas++;
                } 
                // If only white stones are present in this sub-area
                else if (total_white > 0 && total_black == 0) {
                    white_areas++;
                }
            }
        }
    }

    printf("%d %d\n", black_areas, white_areas);

    return 0;
}
