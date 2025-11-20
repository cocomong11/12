#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_COINPOS 12
#define MAX_COIN 4

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

void board_printBoardStatus(void)
{
    int i;
    printf("------------- BOARD STATUS -------------\n");
    for (i = 0; i < N_BOARD; i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_OK)
            printf("O");
        else
            printf("X");
    }
    printf("|\n");
}

int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int tmp = board_coin[pos];
    board_coin[pos] = 0;  
    return tmp;
}

int board_initBoard(void)
{
    int i;

    for (i = 0; i < N_BOARD; i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }

    for (i = 0; i < N_COINPOS; i++)
    {
        while (1)
        {
            int pos = rand() % N_BOARD;
            if (board_coin[pos] == 0)
            {
                board_coin[pos] = (rand() % MAX_COIN) + 1;
                break;
            }
        }
    }
    return 0;
}

