#define BOARDSTATUS_OK 1
#define BOARDSTATUS_NOK 0
#define N_BOARD 30

#define SHARK_INITPOS -4
#define MAX_SHARKSTEP 3 

int board_initBoard(void);
int board_getBoardStatus(int pos);
int board_getSharkPosition(void);
int board_stepShark(void);
int board_getBoardCoin(int pos);
void board_printBoardStatus(void);


