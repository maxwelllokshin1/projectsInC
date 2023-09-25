#include <stdio.h>
int length;
int height;


int input(int matrix[][height], int row, int col)
{
    int i;
    int j;

    for(i = 0; i < row; i++)
    {
        for(j = 0;  j < col; j++)
        {
            printf("Enter value for [%d, %d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix[row][col];
}

void flip(int array1[length][height], int array2[length][height], int row, int col)
{

    int i;
    int j;
    int k=col - 1;

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            array2[j][k] = array1[i][j];
        }
        k--;
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {

            printf("%d", array2[i][j]);
            if (j == (col - 1))
            {
                printf("\n");
            }
        }
    }
}   

int main()
{
    int i, j;

    printf("Length of array: ");
    scanf("%d", &length);
    printf("Height of array: ");
    scanf("%d", &height);
    //int upright[3][3] = {{1,0,0},{1,0,0},{1,0,0}};
    int upright[length][height];
    input(upright, length,height);


    int sider[height][length], upsidedown[length][height], sidel[height][length];


    printf("Regular = \n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < height; j++)
        {
            printf("%d", upright[i][j]);

            if (j == (height - 1))
            {
                printf("\n");
            }
        }
    }
    printf("\n90 degrees = \n");
    flip(upright, sider, height, length);
    printf("\n180 degrees = \n");
    flip(sider, upsidedown, length, height);
    printf("\n270 degrees = \n");
    flip(upsidedown, sidel, height, length);
    printf("\n360 degrees = \n");
    flip(sidel, upright, length, height);
    
    return 0;
}
