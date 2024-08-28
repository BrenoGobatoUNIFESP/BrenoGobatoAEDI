#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 10
#define INF 1e9

typedef struct {
    int y, x;
} Point;

typedef struct {
    Point p1, p2;
} Segment;

double distance(Point p1, Point p2) {
    return sqrt((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x));
}

double calculate_total_distance(Segment segments[], int perm[], int n) {
    double total_distance = 0.0;
    Point current = segments[perm[0]].p1;

    for (int i = 0; i < n; i++) {
        total_distance += distance(current, segments[perm[i]].p1);
        total_distance += distance(segments[perm[i]].p1, segments[perm[i]].p2);
        current = segments[perm[i]].p2;
    }

    return total_distance;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double find_minimum_distance(Segment segments[], int perm[], int l, int r, int n, double min_distance) {
    if (l == r) {
        double current_distance = calculate_total_distance(segments, perm, n);
        if (current_distance < min_distance) {
            min_distance = current_distance;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(&perm[l], &perm[i]);
            min_distance = find_minimum_distance(segments, perm, l + 1, r, n, min_distance);
            swap(&perm[l], &perm[i]); // backtrack
        }
    }
    return min_distance;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        scanf("%d", &N);

        Segment segments[MAX_N];
        int perm[MAX_N];

        for (int i = 0; i < N; i++) {
            char y1, y2;
            int x1, x2;
            scanf(" %c%d %c%d", &y1, &x1, &y2, &x2);

            segments[i].p1.y = y1 - 'A';
            segments[i].p1.x = x1;
            segments[i].p2.y = y2 - 'A';
            segments[i].p2.x = x2;
            perm[i] = i;
        }

        double min_ink = find_minimum_distance(segments, perm, 0, N - 1, N, INF);

        if (min_ink < INF) {
            printf("Case %d: %.2lf\n", test_case, min_ink);
        } else {
            printf("Case %d: ~x(\n", test_case);
        }
    }

    return 0;
}
