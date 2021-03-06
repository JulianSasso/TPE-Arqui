#include <sudoku.h>

char startingTable[TABLE_SIZE][TABLE_SIZE][TABLE_SIZE][TABLE_SIZE] =
    {{{{0, 0, 0}, {6, 8, 0}, {1, 9, 0}}, {{2, 6, 0}, {0, 7, 0}, {0, 0, 4}},
    {{7, 0, 1}, {0, 9, 0}, {5, 0, 0}}}, {{{8, 2, 0}, {0, 0, 4},
    {0, 5, 0}}, {{1, 0, 0}, {6, 0, 2}, {0, 0, 3}}, {{0, 4, 0}, {9, 0, 0}, {0, 2, 8}}},
    {{{0, 0, 9}, {0, 4, 0}, {7, 0, 3}}, {{3, 0, 0}, {0, 5, 0}, {0, 1, 8}},
    {{0, 7, 4}, {0, 3, 6}, {0, 0, 0}}}};
char table[TABLE_SIZE][TABLE_SIZE][TABLE_SIZE][TABLE_SIZE];
char remainingCount = 45;

char res[TABLE_TOTAL_SIZE][TABLE_TOTAL_SIZE];

void initializeSudoku() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            for (int k = 0; k < TABLE_SIZE; k++) {
                for (int l = 0; l < TABLE_SIZE; l++) {
                    table[i][j][k][l] = startingTable[i][j][k][l];
                }
            }
        }
    }

    remainingCount = 45;
}

int tryAddPlayForSudoku(char number, int rowIndex, int columnIndex) {
    int bigRowIndex = rowIndex / TABLE_SIZE;
    int bigColIndex = columnIndex / TABLE_SIZE;
    int smallRowIndex = rowIndex % TABLE_SIZE;
    int smallColIndex = columnIndex % TABLE_SIZE;
    int isAddedAlready = table[bigRowIndex][bigColIndex][smallRowIndex][smallColIndex] ? 1 : 0;

    if (startingTable[bigRowIndex][bigColIndex][smallRowIndex][smallColIndex]) return IGNORED;

    if (number == 0) {
        table[bigRowIndex][bigColIndex][smallRowIndex][smallColIndex] = number;
        if (isAddedAlready) remainingCount++;
        return ADDED_AND_CAN_CONTINUE;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (table[bigRowIndex][bigColIndex][i][j] == number 
            || table[bigRowIndex][i][smallRowIndex][j] == number 
            || table[i][bigColIndex][j][smallColIndex] == number) {
                return IGNORED;
            }
        }
    }

    table[bigRowIndex][bigColIndex][smallRowIndex][smallColIndex] = number;

    if (!isAddedAlready) remainingCount--;
    return remainingCount == 0 ? ADDED_AND_WON : ADDED_AND_CAN_CONTINUE;
}

char **getStartingNumbers() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            for (int k = 0; k < TABLE_SIZE; k++) {
                for (int l = 0; l < TABLE_SIZE; l++) {
                    res[i * 3 + j][k * 3 + l] = startingTable[i][k][j][l];
                }
            }
        }
    }

    return res;
}
