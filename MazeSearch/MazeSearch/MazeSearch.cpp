#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>  //gotoxy() 함수를 사용하기 위한 헤더

#define m 12
#define p 12
#define Max_dir  8   // 총 가능한 이동방향의 수
#define Timestep 1000 // 시간단위는 ms 이므로 1000 이면 1 초를 멈추게 됨.

typedef struct Aoff {
    short int vert;
    short int horiz;
} offsets;

typedef struct  St_element {    // 스택에 저장할 데이터
    short int row;
    short int col;
    short int dir;
} ty_element;

typedef struct ListNode* listPointer;
typedef struct ListNode {       // 연결스택의 노드
    ty_element data;
    listPointer link;
} listNode;

//                            N      NE        E      SE       S       SW        W       NW     
offsets move[Max_dir] = { {-1,0}, {-1,1},  {0,1},  {1,1},   {1,0},  {1,-1},  {0,-1}, {-1,-1} };

int maze[m + 2][p + 2];     // 전역변수로 선언
int mark[m + 2][p + 2];

// push
void push(listPointer* top, ty_element item) {
    listPointer temp;
    temp = (listPointer)malloc(sizeof(listNode));
    temp->data = item;
    temp->link = *top;
    *top = temp;
}

// pop
ty_element pop(listPointer* top) {
    listPointer temp = *top;
    ty_element item;

    item = temp->data;
    *top = temp->link;
    free(temp);
    return item;
}

//reverse 연산
void reverse(listPointer* ptr_top) {
    listPointer cur;
    listPointer temp;
    listPointer next;
    cur = *ptr_top;

    if (!cur || cur->link == NULL)
        return;

    temp = cur;
    cur = cur->link;
    temp->link = NULL;

    while (cur) {
        next = cur->link;
        cur->link = *ptr_top;
        *ptr_top = cur;
        cur = next;
    }
}
void gotoxy(int x, int y) {
    COORD Pos = { x ,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//  미로 경로 탐색 함수.
//  [sy,sx] 에서 시작하여 [dy, dx] 에 도달하는 경로를 찾는다.
int path(int sy, int sx, int dy, int dx)
{
    listPointer top = NULL;  // 스택의 top 변수. 초기에는 NULL.
    int i, j, row, col, nextRow, nextCol, dir, basex, basey, ocount;
    int found, num_bktrack = 0, path_length = 0;
    int EXIT_ROW = dy, EXIT_COL = dx;  // 목표점.
    ty_element position;

    if (maze[sy][sx] == 1 || maze[dy][dx] == 1) {
        printf("입력오류: 출발점이나 목표점이 막힌 셀입니다.\n");
        return 0;
    }

    //maze 행렬 화면 표시 기준점
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    basex = presentCur.dwCursorPosition.X; // 베이스 좌표의 x.
    basey = presentCur.dwCursorPosition.Y; // 베이스 좌표의 y.

    //기준점 [basey,basex]
    for (i = 0; i < m + 2; i++) {
        for (j = 0; j < p + 2; j++) {
            gotoxy(j + basex, i + basey);
            printf("%1d", maze[i][j]);
        }
    }

    // 빈 스택에 출발점을 넣는다.(초기화)
    position.row = sy; position.col = sx;  position.dir = 0;
    push(&top, position);

    // mark 정보초기화. 바운더리를 제외한 내부 셀에 모두 0 (방문안함)으로 초기화한다.
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            mark[1 + i][1 + j] = 0;
        }
    }
    mark[sy][sx] = 1;

    gotoxy(sx + basex, sy + basey);
    printf(">");
    Sleep(Timestep);

    found = 0;
    while (top != NULL) {
        position = pop(&top);
        row = position.row;  col = position.col;  dir = position.dir;
        while (dir < Max_dir) {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
                found = 1; // 1 경로 탐색 성공
                gotoxy(nextCol + basex, nextRow + basey);
                printf("<");
                break;
            }
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
                position.row = row; position.col = col;   position.dir = ++dir;
                push(&top, position);
                row = nextRow; col = nextCol;
                gotoxy(col + basex, row + basey);
                printf("*");
                Sleep(Timestep);
                dir = 0;
                mark[row][col] = 1;
            }
            else
                ++dir;
        }

        if (found)
            break;


        gotoxy(col + basex, row + basey);
        printf("%c", '$');
        num_bktrack++;
        Sleep(Timestep);
    }

    gotoxy(0, basey + m + 2);
    printf("\n");

    if (found) {
        printf("찾은 경로(row,col):\n");
        reverse(&top);
        ocount = 0;
        while (top)
        {
            position = top->data;
            if ((ocount != 0) && (ocount % 6 == 0))
                printf("\n");
            printf("[%2d, %2d] ", position.row, position.col);
            ocount++;
            top = top->link;

        }

        printf("[%2d, %2d] ", row, col);
        printf("[%2d, %2d]\n\n", EXIT_ROW, EXIT_COL);
        path_length = ocount + 2;
        printf("경로길이= %d,  백트래킹수= %d\n\n", path_length, num_bktrack);
    }
    else
        printf("가능 경로가 없음.\n");
    return 1;
}

void main() {
    int i, j, res;
    int starty, startx, endy, endx;
    FILE* fp;
    fp = fopen("maze_14_2.txt", "r");
    if (!fp) {
        printf("file open failed.\n");
        getchar();
    }


    for (i = 0; i < m + 2; i++) {
        for (j = 0; j < p + 2; j++) {
            res = fscanf(fp, "%d", &maze[i][j]);
            if (res != 1) {
                printf("화일에서 maze 읽기 실패.\n");
                getchar();
            }
        }
    }

    while (1) {
        printf("출발점, 목표점은?(4개의 정수; 종료는 Control+D Enter): ");
        res = scanf("%d%d%d%d", &starty, &startx, &endy, &endx);
        if (res != 4)
            break;

        path(starty, startx, endy, endx);
    }

}
