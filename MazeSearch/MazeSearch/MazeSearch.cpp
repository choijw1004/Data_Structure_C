#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>  //gotoxy() �Լ��� ����ϱ� ���� ���

#define m 12
#define p 12
#define Max_dir  8   // �� ������ �̵������� ��
#define Timestep 1000 // �ð������� ms �̹Ƿ� 1000 �̸� 1 �ʸ� ���߰� ��.

typedef struct Aoff {
    short int vert;
    short int horiz;
} offsets;

typedef struct  St_element {    // ���ÿ� ������ ������
    short int row;
    short int col;
    short int dir;
} ty_element;

typedef struct ListNode* listPointer;
typedef struct ListNode {       // ���ὺ���� ���
    ty_element data;
    listPointer link;
} listNode;

//                            N      NE        E      SE       S       SW        W       NW     
offsets move[Max_dir] = { {-1,0}, {-1,1},  {0,1},  {1,1},   {1,0},  {1,-1},  {0,-1}, {-1,-1} };

int maze[m + 2][p + 2];     // ���������� ����
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

//reverse ����
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

//  �̷� ��� Ž�� �Լ�.
//  [sy,sx] ���� �����Ͽ� [dy, dx] �� �����ϴ� ��θ� ã�´�.
int path(int sy, int sx, int dy, int dx)
{
    listPointer top = NULL;  // ������ top ����. �ʱ⿡�� NULL.
    int i, j, row, col, nextRow, nextCol, dir, basex, basey, ocount;
    int found, num_bktrack = 0, path_length = 0;
    int EXIT_ROW = dy, EXIT_COL = dx;  // ��ǥ��.
    ty_element position;

    if (maze[sy][sx] == 1 || maze[dy][dx] == 1) {
        printf("�Է¿���: ������̳� ��ǥ���� ���� ���Դϴ�.\n");
        return 0;
    }

    //maze ��� ȭ�� ǥ�� ������
    CONSOLE_SCREEN_BUFFER_INFO presentCur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
    basex = presentCur.dwCursorPosition.X; // ���̽� ��ǥ�� x.
    basey = presentCur.dwCursorPosition.Y; // ���̽� ��ǥ�� y.

    //������ [basey,basex]
    for (i = 0; i < m + 2; i++) {
        for (j = 0; j < p + 2; j++) {
            gotoxy(j + basex, i + basey);
            printf("%1d", maze[i][j]);
        }
    }

    // �� ���ÿ� ������� �ִ´�.(�ʱ�ȭ)
    position.row = sy; position.col = sx;  position.dir = 0;
    push(&top, position);

    // mark �����ʱ�ȭ. �ٿ������ ������ ���� ���� ��� 0 (�湮����)���� �ʱ�ȭ�Ѵ�.
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
                found = 1; // 1 ��� Ž�� ����
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
        printf("ã�� ���(row,col):\n");
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
        printf("��α���= %d,  ��Ʈ��ŷ��= %d\n\n", path_length, num_bktrack);
    }
    else
        printf("���� ��ΰ� ����.\n");
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
                printf("ȭ�Ͽ��� maze �б� ����.\n");
                getchar();
            }
        }
    }

    while (1) {
        printf("�����, ��ǥ����?(4���� ����; ����� Control+D Enter): ");
        res = scanf("%d%d%d%d", &starty, &startx, &endy, &endx);
        if (res != 4)
            break;

        path(starty, startx, endy, endx);
    }

}
