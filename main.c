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
        printf("%s : position %d, coins %d, status %s\n",
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
        printf("Enter Player %d name: ", i);
        scanf("%s", player_name[i]);
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
    }
}

void checkDie(void)
{
    int i;
    for (i = 0; i < N_PLAYER; i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
            {
                player_status[i] = PLAYERSTATUS_DIE;
                printf("So Sad! player %s is died...\n", player_name[i]);
            }
        }
    }
}

int game_end(void)
{
    int i;
    int alive = 0;

    for (i = 0; i < N_PLAYER; i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
            alive++;
    }

    if (alive == 0) return 1; 
    return 0;
}

int getWinner(void)
{
    int i;
    int winner = -1;
    int max_coin = -1;

    for (i = 0; i < N_PLAYER; i++)
    {
        if (player_status[i] != PLAYERSTATUS_DIE)
        {
            if (player_coin[i] > max_coin)
            {
                max_coin = player_coin[i];
                winner = i;
            }
        }
    }

    return winner;
}

int main(void)
{
    srand((unsigned)time(NULL));

    // ================= START SCREEN ======================
    printf("============================================================\n");
    printf("                   S H A R K   I S L A N D                  \n");
    printf("============================================================\n\n");


    printf("------------------------------------------------------------\n");
    printf("   ¢º Press ENTER to start the game...\n");
    printf("------------------------------------------------------------\n");

    getchar(); 
    getchar();

    board_initBoard();
    initPlayer();

    int turn = 0;
    int dum;
    int die_result;

    do
    {
        board_printBoardStatus();
        printPlayerStatus();

        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1) % N_PLAYER;
            continue;
        }

        printf("\n%s's turn! Press any key to roll the die...\n", player_name[turn]);
        getchar(); getchar();

        die_result = rollDie();
        printf("Die result = %d\n", die_result);

        player_position[turn] += die_result;
        if (player_position[turn] >= N_BOARD - 1)
        {
            player_position[turn] = N_BOARD - 1;
            player_status[turn] = PLAYERSTATUS_END;
            printf("%s reached the END!\n", player_name[turn]);
        }

        int gained = board_getBoardCoin(player_position[turn]);
        if (gained > 0)
        {
            player_coin[turn] += gained;
            printf(">> %s collected %d coin(s)!\n", player_name[turn], gained);
        }

        turn = (turn + 1) % N_PLAYER;

        // ------------------- SHARK TURN ----------------------
        if (turn == 0)
        {
            int new_pos = board_stepShark();
            printf("\n>> The shark moved to %d!\n", new_pos);
            checkDie();

            printf("\nPress ENTER to continue to the next round...\n");
            getchar(); getchar();
        }

    } while (!game_end());

    // ================= END SCREEN ======================
    printf("\n============================================================\n");
    printf("                     G A M E   O V E R                      \n");
    printf("============================================================\n\n");


    int winner = getWinner();
    printf("  Winner: %s  (Coins: %d)\n",
           player_name[winner], player_coin[winner]);

    printf("============================================================\n");

    return 0;
}

