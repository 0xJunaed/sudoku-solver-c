#include <stdio.h>
#include <string.h>
#define ROW 9
#define COL 9

int puzzel[ROW][COL] = {
    {0, 0, 0, 7, 3, 8, 0, 0, 0},
    {2, 0, 0, 0, 9, 0, 0, 0, 0},
    {9, 4, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 0, 0, 0, 7, 0, 1, 0},
    {6, 0, 5, 0, 0, 0, 0, 4, 0},
    {0, 8, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 9, 0, 0, 0, 3, 0, 8},
    {0, 3, 0, 1, 0, 0, 7, 0, 0}
};

void print_puzzel(int puzzel[ROW][COL]);
int valid_move(int puzzel[ROW][COL], int row, int col, int value);
int solve_puzzel(int puzzel[ROW][COL], int row, int col);

int main()
{
    printf("Welcome To Suddoku Game Oswer - 6XDOT.\n");
    printf("Original Puzzel : \n");
    print_puzzel(puzzel);
    if (solve_puzzel(puzzel, 0, 0))
    {
        printf("\nThe Solved Puzzel Is :) \n");
        print_puzzel(puzzel);
    }
    else
        printf("Puzzel Is No Solved !!! :(\n");

    return 0;
}

int solve_puzzel(int puzzel[ROW][COL], int row, int col)
{

    if (col == COL)
    {
        col = 0;
        row++;
        if (row == ROW) //  if funtion come in this postion mean he done all the work
        {
            return 1; //  last line that's mean puzzel was solved
        }
    }

    if (puzzel[row][col] > 0)
    {
        return solve_puzzel(puzzel, row, col + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (valid_move(puzzel, row, col, i)) // valid_movie will return 1 if the resut is true or false 0
        {
            // if the gues number is right for the postion then fill the number but temporarry
            puzzel[row][col] = i;
            // then continue for the next postion mean call the same function continuesly
            if (solve_puzzel(puzzel, row, col + 1)) // and this way will continue until the last postion and fill up the number
            {
                return 1; // then return to mean we have solve the number postion at this stage
            }
            // assume first condition is right then second also right and this way continue at some point our
            // number get wrong then these code will backtrack come back to the old postion and try different number on poistion
            // at the moment we have already saved the number one the so that's why by using this code will making insure the poistion
            puzzel[row][col] = 0; // should un change / or we can say assinge to the postion zero to try the program on more time
            // not will be effect if the first condition goes to wrong !!
        }
    }
    return 0; // after every thing if we didn't make to solve the quetion then return false bcz the suddoku can't be solved
    // or have problem on suddoku values !!
}

int valid_move(int puzzel[ROW][COL], int row, int col, int value)
{

    // checking row and col are valid ? !!
    for (int i = 0; i < COL; i++)
    {
        if (puzzel[row][i] == value)
        {
            return 0;
        }
        if (puzzel[i][col] == value)
        {
            return 0;
        }
    }

    // valid square
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzel[r + i][c + j] == value)
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_puzzel(int puzzel[ROW][COL])
{
    printf("\n+-------+-------+-------+\n");
    for (int R = 0; R < ROW; R++)
    {
        printf("| ");
        for (int C = 0; C < COL; C++)
        {
            if (puzzel[R][C] > 0)
            {
                printf("%d ", puzzel[R][C]);
            }
            else
            {
                printf("  ");
            }

            if ((C + 1) % 3 == 0)
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((R + 1) % 3 == 0)
        {
            printf("+-------+-------+-------+\n");
        }
    }
}
