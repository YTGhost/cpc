#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int find_min_time(int c, int n, int a[])
{
    int min_time = 0;
    for (int i = 0; i < n; i++){
        min_time = max(min_time, min(c - a[i], a[i]));
    }
    return min_time;
}

int find_max_time(int c, int n, int a[])
{
    int max_time = 0;
    for (int i = 0; i < n; i++){
        max_time = max(max_time, max(c - a[i], a[i]));
    }
    return max_time;
}

int main()
{
    int t, c, n, b[1000] = {};
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d %d", &c, &n);
        int a[n];
        for (int j = 0; j < n; j++){
            scanf("%d", &a[j]);
        }
        b[(i+1) * 2] = find_max_time(c, n, a);
        b[(i+1) * 2 - 1] = find_min_time(c, n, a);
    }
    for (int i = 1; i <= t; i++){
        printf("%d %d\n", b[i * 2 - 1], b[i * 2]);
    }
    system("pause");
    return 0;
}