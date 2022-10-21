#include <stdio.h>
#include <stdbool.h>

int count = 0;
bool issafe(int n, int board[n][n], int row, int col)
{
    //  column
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    // row
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == 1)
        {
            return false;
        }
    }
    return true;
}

bool nQueen(int n, int board[n][n], int row)
{
    if (row == n)
    {
        count++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("............................\n");
        return true;
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (issafe(n, board, row, i))
        {
            board[row][i] = 1;

            flag = nQueen(n, board, row + 1) || flag;
            board[row][i] = 0;
        }
    }
    return flag;
}

void main()
{
    int n;
    printf("Enter size of chess of board : ");
    scanf("%d", &n);
    int board[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    if (nQueen(n, board, 0))
    {
    }
    else
    {
        printf("Solution does not exit : \n");
    }
    printf("Total number of possible solution is : %d", count);
}
