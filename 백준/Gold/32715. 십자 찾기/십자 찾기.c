#include <stdio.h>

#define MAX_N 2500
#define MAX_M 2500

static int s_grid[MAX_N][MAX_M];
static int s_up[MAX_N][MAX_M];
static int s_down[MAX_N][MAX_M];
static int s_left[MAX_N][MAX_M];
static int s_right[MAX_N][MAX_M];

int main(void)
{
    int n, m, k;
    int i, j;
    int count;
    int min_val;

    (void)scanf("%d %d", &n, &m);
    (void)scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            (void)scanf("%d", &s_grid[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (s_grid[i][j] == 1)
            {
                s_up[i][j] = (i == 0) ? 1 : s_up[i - 1][j] + 1;
                s_left[i][j] = (j == 0) ? 1 : s_left[i][j - 1] + 1;
            }
            else
            {
                s_up[i][j] = 0;
                s_left[i][j] = 0;
            }
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        for (j = m - 1; j >= 0; j--)
        {
            if (s_grid[i][j] == 1)
            {
                s_down[i][j] = (i == n - 1) ? 1 : s_down[i + 1][j] + 1;
                s_right[i][j] = (j == m - 1) ? 1 : s_right[i][j + 1] + 1;
            }
            else
            {
                s_down[i][j] = 0;
                s_right[i][j] = 0;
            }
        }
    }

    count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (s_grid[i][j] == 0)
            {
                continue;
            }

            min_val = s_up[i][j];
            if (s_down[i][j] < min_val) 
            { 
                min_val = s_down[i][j]; 
            }
            if (s_left[i][j] < min_val) 
            { 
                min_val = s_left[i][j]; 
            }
            if (s_right[i][j] < min_val) 
            { 
                min_val = s_right[i][j]; 
            }

            if (min_val >= k + 1)
            {
                count++;
            }
        }
    }

    (void)printf("%d\n", count);

    return 0;
}