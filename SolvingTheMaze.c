#include <stdio.h>

#define ROWS 12
#define COLUMNS 12

void getStartPoint(char wMaze[][COLUMNS], int *wStartRow, int *wStartColumn)
{
    for (int i = 0, j = 0; wMaze[i][j] != '.'; i++)
    {
        *wStartRow = i + 1;
        *wStartColumn = j;
    }
}

void mazeTraverse(char wMaze[][COLUMNS], int wStartRow, int wStartColumn)
{
    int i = wStartRow, j = wStartColumn, x = 0;
    while (j < 11)
    {
        wMaze[i][j] = 'x';

        // x=1,2,3,4 these are for prevent the bugs like turning back without going along the way, this is reducing priority of back door

        if (wMaze[i][j + 1] == '.' && x != 1)
        {
            j = j + 1;
            x = 3;
            goto label;
        }
        if (wMaze[i + 1][j] == '.' && x != 2)
        {
            i = i + 1;
            x = 4;
            goto label;
        }

        if (wMaze[i][j - 1] == '.' && x != 3)
        {
            j = j - 1;
            x = 1;
            goto label;
        }

        if (wMaze[i - 1][j] == '.' && x != 4)
        {
            i = i - 1;
            x = 2;
            goto label;
        }

        if (wMaze[i][j + 1] != '#' && x != 1)
        {
            j = j + 1;
            x = 3;
            goto label;
        }
        if (wMaze[i + 1][j] != '#' && x != 2)
        {
            i = i + 1;
            x = 4;
            goto label;
        }

        if (wMaze[i][j - 1] != '#' && x != 3)
        {
            j = j - 1;
            x = 1;
            goto label;
        }

        if (wMaze[i - 1][j] != '#' && x != 4)
        {
            i = i - 1;
            x = 2;
            goto label;
        }
        x++; // if there is no way around to go thats mean it should return , x++ makes him return behind
    label:

        for (int n = 0; n < ROWS; n++)
        {
            for (int m = 0; m < COLUMNS; m++)
            {
                printf("%c ", wMaze[n][m]);
            }
            printf("\n");
        }

        sleep(1);

        printf("\e[1;1H\e[2J");
        printf("\n\n\n\n\n\n\n");
    }
}

int main()
{
    int startRow, startColumn;

    char maze[ROWS][COLUMNS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    getStartPoint(maze, &startRow, &startColumn);

    mazeTraverse(maze, startRow, startColumn);

    return 0;
}
