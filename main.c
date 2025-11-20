#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE 6
#define N_PLAYER 3
#define MAXLENGTH 30

#define PLAYERSTATUS_LIVE 0
#define PLAYERSTATUS_DIE 1
#define PLAYERSTATUS_END 2

char player_name[N_PLAYER][MAXLENGTH];
int player_position[N_PLAYER];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAXLENGTH] = {"LIVE", "DIE", "END"};


int rollDie(void)
{
    return (rand() % MAX_DIE) + 1;
}

void printPlayerPosition(int player)
{
    int i;
    for (i = 0; i < N_BOARD; i++)
    {
        printf("|");
        if (i == player_position[player])
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_OK)
                printf(" ");
            else
                printf("X");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("========== PLAYER STATUS ==========\n");
    for (i = 0; i < N_PLAYER; i++)
    {
        printf("%s : pos %d, coin %d, status %s\n",
               player_name[i],
               player_position[i],
               player_coin[i],
               player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("===================================\n");
}

void initPlayer(void)
{
    int i;
    for (i = 0; i < N_PLAYER; i++)
    {
        printf("Player %d name: ", i);
        scanf("%s", player_name[i]);
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));

    printf("============================================================\n");
    printf("                   S H A R K   I S L A N D                  \n");
    printf("============================================================\n\n");

    board_initBoard();
    initPlayer();

    int turn = 0;
    int die_result;
    int pos;
    int dummy;

    while (1)   
    {
        board_printBoardStatus();
        printPlayerStatus();

        printf("\n%s turn! Press any number to roll die: ", player_name[turn]);
        scanf("%d", &dummy);

        die_result = rollDie();

        printf("Die result = %d\n", die_result);

        player_position[turn] += die_result;
        if (player_position[turn] >= N_BOARD - 1)
        {
            player_position[turn] = N_BOARD - 1;
            player_status[turn] = PLAYERSTATUS_END;
            printf("%s reached the end!\n", player_name[turn]);
        }

        printf("%s moved to %d\n", player_name[turn], player_position[turn]);

        int gained = board_getBoardCoin(player_position[turn]);
        if (gained > 0)
        {
            player_coin[turn] += gained;
            printf(">> %s gained %d coin!\n", player_name[turn], gained);
        }

        turn = (turn + 1) % N_PLAYER;
    }

    return 0;
}

