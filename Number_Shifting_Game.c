//  Project - 1   ===>    A Job Ready Bootcamp in C++, DSA and IOT - MySirG  ===>    C Language
//  Project Statement_01: Number Shifting Game in C Programming Language

// Project Problem Statement:
// You are given a 4x4 matrix with random values filled. e.g
// You have to convert this random matrix to matrix which looks like this
// Game Rules :
// 1. You can move only 1 step at a time with the arrow key.
// 2. You can move numbers at an empty position only.
// 3. For each valid move : your total number of moves will decrease by 1.

// Winning Situation :
// 1. Number in a 4*4 matrix should be in order from 1 to 15

/*------------------------------------------------------------------------------------------------------------------------------------*/

/* Header Files */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>

/* Defined Constants */
#define true 1;
#define false 0;
#define FREE_MOVES 3;

/* Global Variable Declaration */
int puzArr[5][5], row = 1, column = 1;
int curRow = 4, curCol = 4, totalMoves = 0, freeMoves = 0;

/* Global Prototype Declaration */
int getRandVal();
int setRandVal(int);
void clearScreen(int);
void draw15PuzzleBox();
void movePosition(int);
void swapValue(int, int);
void printPosition(char *);
int IsDone(void);

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void main()
{
    char inputKey, arrowKey;

    /* Local Prototype Declaration */
    int loadDefaultData();
    void resetRowColumn();
    void printTotalMoves();
    void printTotalFREEMoves();
    int doFREEMove();

    /* Clear the Screen */
    // clrscr();
    system("cls");
    printf("This is Project-Statement_1: Number_Shifting_Game...");
    printf("\n\n");

    /* Randomize */
    // randomize();
    srand(time(0));

    char playerName;
    printf("Player Name: ");
    scanf("%c", &playerName);

    printf("\n\n");
    printf("\t\tMATRIX PUZZLE");
    printf("\n");
    printf("\t\t-------------\n");
    printf("\t\t-------------\n");
    printf("\n\n");
    printf("\t\tRULES OF THIS GAME");
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("1. You Can Move Only 1 Step At a Time, By Arrow Keys...\n");
    printf("\tMove Up               :    By \"UP\"      Arrow Key...\n");
    printf("\tMove Down             :    By \"DOWN\"    Arrow Key...\n");
    printf("\tMove Left             :    By \"LEFT\"    Arrow Key...\n");
    printf("\tMove Right            :    By \"RIGHT\"   Arrow Key...\n");
    printf("2. You Can Move Number At \"Empty\" Position Only...\n");
    printf("3. For Each Valid Move      :    Your Total Number Of Move Will \"Decreased By 1\"...\n");
    printf("4. Wining Situation         :    Number in a 4x4 Matrix Should Be in Order From 1 To 15...\n");
    printf("\t\tWinning Situation:\n");
    printf("\t\t---------------------\n");
    printf("\t\t|  1 |  2 |  3 |  4 |\n");
    printf("\t\t---------------------\n");
    printf("\t\t|  5 |  6 |  7 |  8 |\n");
    printf("\t\t---------------------\n");
    printf("\t\t|  9 | 10 | 11 | 12 |\n");
    printf("\t\t---------------------\n");
    printf("\t\t| 13 | 14 | 15 | 16 |\n");
    printf("\t\t---------------------\n");
    printf("5. You Can \"EXIT\" The Game, At Any Time, By Pressing \"'E'\" or \"'e'\"...\n");
    printf("So, Try To Win in, \"Minimum Number Of Moves\"...\n\n");
    printf("Enter \"Any Key\" To \"START THE GAME\"...");

    getch();

    /* Set Free Moves */
    freeMoves = FREE_MOVES;

    /* Load Default Data */
    gotoxy(1, 1);
    printf("Please Wait... \nWhile Loading Data !!!");
    loadDefaultData();

    /* Print Loaded Data */
    draw15PuzzleBox();
    /* Detect Arrow Keys in C Program
       Press ESCAPE - 27
       Press ENTER  - 13
       Get out from the Indefinite loop
    */
    while ((inputKey = getch()) != 27)
    {

        /* Set Default Text color as WHITE */
        // textcolor(15);
        // textcolor(WHITE);
        // setTextColor(15);
        system("COLOR 3");
        system("cls");

        /* Find Arrow Key or not */
        if (inputKey == '\0')
        {

            /* Extract actual Arrow Key */
            arrowKey = getch();
            switch (arrowKey)
            {
            case 72:
                movePosition(72);
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
                break;

            case 80:
                movePosition(80);
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
                break;

            case 75:
                movePosition(75);
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
                break;

            case 77:
                movePosition(77);
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
                break;
            }
        }
        else if (inputKey == 13)
        {
            // printf("Enter key pressed..");
            system("cls");
            if (freeMoves > 0)
            {
                doFREEMove();

                /* Increment Moves */
                totalMoves++;
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
            }
            else
            {
                draw15PuzzleBox();
                printTotalMoves();
                printTotalFREEMoves();
            }
        }

        /* Check 15-Puzzle Completion */
        if (IsDone())
        {

            /* Clear the Screen and Announce the Result */
            system("cls");

            /* Print Total Moves */
            printTotalMoves();
            gotoxy(35, 13);
            // textcolor(2);
            system("COLOR 2");
            printPosition("Great!!!");
            getch();

            /* Smoothly End the Program Execution ;) */
            exit(1);
        }
    }
}
/* Assign Random Value */
int loadDefaultData()
{
    int i = 1, j = 1, randVal;

    /* Custom Clear Screen
     0 - Row Wise Clear
     1 - Column Wise Clear
     */
    // randVal = random(1);
    randVal = rand() % 1;
    clearScreen(randVal);
    for (; i <= 4;)
    {
        for (; j <= 4;)
        {

            /* Draw Puzzle Box */
            draw15PuzzleBox();
            /* get Random value */
            randVal = getRandVal();
            if (setRandVal(randVal))
            {

                /* Set the Next Value */
                puzArr[i][j] = randVal;

                /* Increment next Column */
                column = j;
                j++;

                /* Check Is all 15 values set */
                if (i == 4 && j == 4)
                {

                    /* Set Zero to Final Position */
                    puzArr[i][j] = 0;
                    movePosition(0);
                    return 1;
                }
            }
        }

        /* increment to Next Row */
        row = i;
        i++;

        /* Re-initialize the Column value */
        j = 1;
    }

    /* Normal Data Load Completion */
    return 1;
}

/* Get a Random Number from 1 to 15 */
int getRandVal()
{
    int i, randVal;
    int dataArr[15];
    for (i = 0; i < 15; i++)
    {
        dataArr[i] = i + 1;
    }
    randVal = rand() % 15;
    randVal = dataArr[randVal];
    return randVal;
}

/* Check and Set a Random Value to next EMPTY position */
int setRandVal(int checkVal)
{
    int i, j;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {

            /* Is this value already present and Allocated */
            if (puzArr[i][j] == checkVal)
            {
                return false;
            }
        }
    }

    /* Yes, We got a next Rand value for Next position */
    return true;
}

/* Draw the Current Data */
void draw15PuzzleBox()
{
    int i, j, charPos = 177, row = 3;
    // int charSmile=2;

    /* Make Position to Draw the 15-Puzzle Box */
    gotoxy(3, row++);
    for (i = 1; i <= 20; i++)
    {
        printf("%c", charPos);
    }
    gotoxy(3, row);
    printf("%c", charPos);
    gotoxy(4, row++);
    for (i = 1; i <= 18; i++)
    {
        printf(" ");
    }
    printf("%c", charPos);

    for (i = 1; i <= 4; i++)
    {
        gotoxy(3, row++);
        printf("%c", charPos);
        for (j = 1; j <= 4; j++)
        {
            if (puzArr[i][j])
            {
                printf("%4d", puzArr[i][j]);
            }
            else
            {

                // printf("%4c",charSmile);
                printf("    ");
            }
        }
        printf("  %c", charPos);
    }
    gotoxy(3, row);
    printf("%c", charPos);
    gotoxy(4, row++);
    for (i = 1; i <= 18; i++)
    {
        printf(" ");
    }
    printf("%c", charPos);
    gotoxy(3, row++);
    for (i = 1; i <= 20; i++)
    {
        printf("%c", charPos);
    }

    /* Show Current Position Information */
    gotoxy(35, 13);
}

/* Clear the Screen */
void clearScreen(int rowOrColumn)
{
    int i, j;
    for (i = 1; i <= 25; i++)
    {
        for (j = 1; j <= 80; j++)
        {

            /* Row Wise - 0 */
            if (rowOrColumn == 0)
            {
                gotoxy(i, j);
            }

            /* Column Wise - 1 */
            else if (rowOrColumn == 1)
            {
                gotoxy(j, i);
            }
            printf(" ");
        }
        // delay(10);
        Sleep(10);
    }

    /* Show Current Position Information */
    gotoxy(35, 13);
}

/* Reset Global Row & Column */
void resetRowColumn()
{
    row = 1;
    column = 1;
}

/* Move position */
void movePosition(int pos)
{
    int iRow, iCol;

    /* Keep Current Row & Column Positions for SWAP */
    iRow = curRow;
    iCol = curCol;

    /* Show Current Position Information */
    gotoxy(35, 13);
    if (pos == 0)
    {

        /* Set Color as LightGreen */
        // textcolor(10);
        system("COLOR 10");

        printPosition("READY ?");
    }

    /* Up - 72 */
    else if (pos == 72)
    {
        if (curRow < 4)
        {
            curRow++;

            /* Ok, Do Swap */
            swapValue(iRow, iCol);

            /* Increment Total Move */
            totalMoves++;
            // printf("UP (%d,%d)             ", curRow, curCol);
            printPosition("  UP   ");
        }
        else
        {

            /* Set Text color as RED */
            // textcolor(4);
            system("COLOR 4");
            printPosition("INVALID");
        }
    }

    /* Down - 80 */
    else if (pos == 80)
    {
        if (curRow > 1)
        {
            curRow--;

            /* Ok, Do Swap */
            swapValue(iRow, iCol);

            /* Increment Total Move */
            totalMoves++;
            printPosition(" DOWN  ");
        }
        else
        {

            /* Set Text color as RED */
            // textcolor(4);
            system("COLOR 4");
            printPosition("INVALID");
        }
    }

    /* Left - 75 */
    else if (pos == 75)
    {
        if (curCol < 4)
        {
            curCol++;

            /* Ok, Do Swap */
            swapValue(iRow, iCol);

            /* Increment Total Move */
            totalMoves++;
            printPosition(" LEFT  ");
        }
        else
        {

            /* Set Text color as RED */
            // textcolor(4);
            system("COLOR 4");
            printPosition("INVALID");
        }
    }

    /* Right - 77 */
    else if (pos == 77)
    {
        if (curCol > 1)
        {
            curCol--;

            /* Ok, Do Swap */
            swapValue(iRow, iCol);

            /* Increment Total Move */
            totalMoves++;
            printPosition(" RIGHT ");
        }
        else
        {

            /* Set Text color as RED */
            // textcolor(4);
            system("COLOR 4");
            printPosition("INVALID");
        }
    }
}

/* Swap the Value */
void swapValue(int prevRow, int prevCol)
{
    int prevValue, curValue;

    /* getCurrent Swap Value */
    prevValue = puzArr[prevRow][prevCol];
    curValue = puzArr[curRow][curCol];

    /* Swap it, Simply !! */
    puzArr[prevRow][prevCol] = curValue;
    puzArr[curRow][curCol] = prevValue;

    /* Draw Puzzle Box */
    draw15PuzzleBox();
}

/* Check 15-Puzzle Completion */
int IsDone()
{
    int i, j, iSequence = 1;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if (puzArr[i][j] != iSequence)
            {
                return false;
            }

            /* Done, That's it!! */
            if (iSequence == 15)
            {
                return true;
            }
            iSequence++;
        }
    }

    /* Yes, You have done the Magic !! */
    return true;
}

/* Print Total Moves */
void printTotalMoves()
{
    int i, charPos = 176, heart = 3;
    gotoxy(38, 3);
    for (i = 1; i <= 18; i++)
    {
        printf("%c", charPos);
    }
    gotoxy(38, 4);
    printf("%c                %c", charPos, charPos);
    gotoxy(38, 5);
    printf("%c  T%ctal M%cves:  %c", charPos, heart, heart, charPos);
    gotoxy(38, 6);
    printf("%c     %4d       %c", charPos, totalMoves, charPos);
    gotoxy(38, 7);
    printf("%c                %c", charPos, charPos);
    gotoxy(38, 8);
    for (i = 1; i <= 18; i++)
    {
        printf("%c", charPos);
    }
}

/* Print Position in Text */
void printPosition(char *position)
{
    int i, charPos = 176;
    gotoxy(38, 12);
    for (i = 1; i <= 18; i++)
    {
        printf("%c", charPos);
    }
    gotoxy(38, 13);
    printf("%c                %c", charPos, charPos);
    gotoxy(38, 14);
    // cprintf("%c    %7s     %c", charPos, position, charPos);
    _cprintf("%c    %7s     %c", charPos, position, charPos);
    gotoxy(38, 15);
    printf("%c                %c", charPos, charPos);
    gotoxy(38, 16);
    for (i = 1; i <= 18; i++)
    {
        printf("%c", charPos);
    }
}

/* Total Free Moves */
void printTotalFREEMoves()
{
    int i, row = 14, charPos = 176, smile = 3;
    gotoxy(6, row++);
    for (i = 1; i <= 25; i++)
    {
        printf("%c", charPos);
    }
    gotoxy(6, row++);
    printf("%c                       %c", charPos, charPos);
    if (freeMoves > 0)
    {
        gotoxy(6, row++);
        printf("%c      Fr%c%c M%cves       %c", charPos, smile, smile, smile, charPos);
        gotoxy(6, row++);
        printf("%c%11d            %c", charPos, freeMoves, charPos);
    }
    if (freeMoves > 0)
    {
        gotoxy(6, row++);
        printf("%c      Press ENTER      %c", charPos, charPos);
        gotoxy(6, row++);
        printf("%c     Get FREE Move     %c", charPos, charPos);
    }
    else
    {
        gotoxy(6, row++);
        printf("%c     -NO FREE Move-    %c", charPos, charPos);
    }
    gotoxy(6, row++);
    printf("%c                       %c", charPos, charPos);
    gotoxy(6, row++);
    for (i = 1; i <= 25; i++)
    {
        printf("%c", charPos);
    }
}

/* Do FREE Move - Help When User Stuck!! */
int doFREEMove()
{
    int i, j, k, l, iSequence = 1, toSwap;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if (puzArr[i][j] != iSequence)
            {

                /* get iSequence value's Row & Column */
                for (k = 1; k <= 4; k++)
                {
                    for (l = 1; l <= 4; l++)
                    {
                        if (puzArr[k][l] == iSequence)
                        {

                            /* Do FREE Swap */
                            toSwap = puzArr[i][j];
                            puzArr[i][j] = iSequence;
                            puzArr[k][l] = toSwap;
                            freeMoves--;
                            return true;
                        }
                    }
                }
            }
            iSequence++;
        }
    }

    /* Yes, You have done the Magic !! */
    return true;
}

// Reference:
// http://dummiesletusc.blogspot.com/2015/12/15-puzzle-game-in-c-program.html