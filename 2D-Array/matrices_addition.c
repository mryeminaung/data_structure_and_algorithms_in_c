#include <stdio.h>

#define ROW_MAX 50
#define COL_MAX 50

int readMatrix(int m[ROW_MAX][COL_MAX], int nRow, int nCol);
int addMatrix(int m1[ROW_MAX][COL_MAX], int m2[ROW_MAX][COL_MAX], int m3[ROW_MAX][COL_MAX], int nRow, int nCol);
int displayMatrix(int m[ROW_MAX][COL_MAX], int nRow, int nCol);

int main()
{
    int m1[ROW_MAX][COL_MAX], m2[ROW_MAX][COL_MAX], m3[ROW_MAX][COL_MAX];
    int nRow1, nCol1, nRow2, nCol2;
    nRow1 = 2, nCol1 = 2;

    printf("For matrix 1\n");
    readMatrix(m1, nRow1, nCol1);
    printf("For matrix 2 :\n");
    readMatrix(m2, nRow1, nCol1);

    addMatrix(m1, m2, m3, nRow1, nCol1);

    printf("\tMATRIX 1\n");
    displayMatrix(m1, nRow1, nCol1);

    printf("\tMATRIX 2\n");
    displayMatrix(m2, nRow1, nCol1);

    printf("\tResult Matrix\n");
    displayMatrix(m3, nRow1, nCol1);

    return 0;
}

int readMatrix(int m[ROW_MAX][COL_MAX], int nRow, int nCol)
{
    for (int row = 0; row < nRow; row++)
    {
        printf("Reading inputs for Row %d : \n", row + 1);
        for (int col = 0; col < nCol; col++)
        {
            scanf("%d", &m[row][col]);
        }
        printf("\n");
    }
}

int addMatrix(int m1[ROW_MAX][COL_MAX], int m2[ROW_MAX][COL_MAX], int m3[ROW_MAX][COL_MAX], int nRow, int nCol)
{
    printf("Adding two matrices...");

    for (int row = 0; row < nRow; row++)
    {
        for (int col = 0; col < nCol; col++)
        {
            m3[row][col] = m1[row][col] + m2[row][col];
        }
        printf("\n");
    }
}

int displayMatrix(int m[ROW_MAX][COL_MAX], int nRow, int nCol)
{
    for (int row = 0; row < nRow; row++)
    {
        for (int col = 0; col < nCol; col++)
        {
            printf("%d ", m[row][col]);
        }
        printf("\n");
    }
}
