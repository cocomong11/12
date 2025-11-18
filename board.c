#if 0
int board_initBoard(void);
int board_getBoardStatus(int pos);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);
void board_printBoardStatus(void);
#endif
#define N_BOARD 30
#define BOARDSSTATUS_OK 1
#define BOARDSTATUS_NOK 0

static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;

void board_printBoardStatus(void)
{
	int i;
	printf("------------------BOARD STATUS-------------------");
	for(i=0;i<N_BOARD;i++)
	{
		printf("|");
		if (board_status[i]==BOARDSTATUS_NOK)
		printf("X");
		else
		printf("O");
		
	}
	printf("|\n");
	printf("-----------------------------------------------\n");
}
