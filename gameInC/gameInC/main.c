//
//  main.c
//  gameInC
//
//  Created by Gabriela Valentina on 06.01.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 5

void print_board(int board[][MAX_LEVEL], int level)
{
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void init_board(int board[][MAX_LEVEL], int level)
{
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level; j++)
        {
            board[i][j] = rand() % 2;
        }
    }
}

int count_adjacent(int board[][MAX_LEVEL], int level, int x, int y)
{
    int count = 0;
    if (x > 0 && board[x - 1][y]) count++;
    if (y > 0 && board[x][y - 1]) count++;
    if (x < level - 1 && board[x + 1][y]) count++;
    if (y < level - 1 && board[x][y + 1]) count++;
    return count;
}

void update_board(int board[][MAX_LEVEL], int level)
{
    int new_board[MAX_LEVEL][MAX_LEVEL];
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level; j++)
        {
            int count = count_adjacent(board, level, i, j);
            if (board[i][j])
            {
                new_board[i][j] = (count == 2 || count == 3);
            }
            else
            {
                new_board[i][j] = (count == 3);
            }
        }
    }
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

int main(void)
{
    int board[MAX_LEVEL][MAX_LEVEL];
    int level;
    int iterations;
    printf("Enter the level of the board (between 1 and %d): ", MAX_LEVEL);
    scanf("%d", &level);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    
    srand(time(NULL));
    init_board(board, level);
    print_board(board, level);
    for (int i = 0; i < iterations; i++)
    {
        update_board(board, level);
        print_board(board, level);
    }
    
    return 0;
}
