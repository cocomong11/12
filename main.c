#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand((unsigned)(time(NULL)));
	printf("============================================================\n");
    printf("                   S H A R K   I S L A N D                  \n");
    printf("============================================================\n");
    printf("\n");
    printf("   파도 위를 달리는 생존 레이스, <상어 아일랜드>에 오신 것을 환영합니다!\n");
    printf("\n");
    printf("    규칙 요약\n");
    printf("    - 주사위를 굴려 앞으로 전진합니다.\n");
    printf("    - 지나가는 칸에 동전이 있으면 챙깁니다.\n");
    printf("    - 뒤에서 상어가 점점 다가옵니다...! \n");
    printf("    - 상어에게 잡히지 않고, 동전을 가장 많이 모은 플레이어가 승리합니다!\n");
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("   ▶ 게임을 시작하려면 Enter 키를 누르세요...\n");
    printf("------------------------------------------------------------\n");
    //step 1. initialization
    
    //step 2. turn play(do-while)
    //2-1. status printing
    //2-2. roll diee
    //2-3. move(result)
    //2-4 change turn, shrak move
    
    //step 3. game end
    
    


   printf("\n");
    printf("============================================================\n");
    printf("                     G A M E   O V E R                      \n");
    printf("============================================================\n");
    printf("\n");
    printf("   상어 아일랜드 생존 레이스가 종료되었습니다!\n");
    printf("   결과 화면에서 최종 승자를 확인해 주세요 \n");
    printf("\n");
    printf("   플레이해 주셔서 감사합니다. 또 만나요! \n");
    printf("\n");
    printf("============================================================\n");

	system("PAUSE");
	return 0;
}
