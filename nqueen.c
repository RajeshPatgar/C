#include <stdio.h>
#include <math.h>

int x[20];
int board[20][20];

#define FALSE 0
#define TRUE 1

int place(int k, int i)
{
    int j;
    for (j = 1; j <= k; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return FALSE;
    }
    return TRUE;
}

void nqueens(int k, int n)
{
    int i, a;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (a = 1; a <= n; a++)
                {
                    for (int b = 1; b <= n; b++)
                    {
                        if (x[a] == b)
                            board[a][b] = 1;
                        else
                            board[a][b] = 0;
                        printf("%d ", board[a][b]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
                nqueens(k + 1, n);
        }
    }
}

int main()
{
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    printf("\nThe solution to the N Queens problem is:\n");
    nqueens(1, n);
    return 0;
}
