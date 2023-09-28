#include <stdio.h>
int length;
int height1;
int length1;
int height2;

int input(int matrix[][height1], int row, int col)
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
int input1(int matrix[][height2], int row, int col)
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

void mult(int matrix1[length][height1], int matrix2[length1][height2], int l, int h, int l1, int h1, int rl, int rh)
{
    int i;
    int j;
    int k;
    int val1 = 0;
    int result[rl][rh];

    if((l == h1) || (l1 == h))
    {
        printf("\n\nmatrix 1\n");
        for(i = 0; i<l; i++){
            for(j = 0; j<h; j++){
                for(k = 0; k<h; k++){
                    val1 += (matrix1[i][k] * matrix2[k][j]);
                }
                printf(" %d ", matrix1[i][j]);
                if(j == (h-1)){
                    printf("\n");
                }
                result[i][j] = val1;
                val1 = 0;
            }
        }

        printf("\nmatrix 2\n");
        for(i = 0; i<l1; i++){
            for(j = 0; j<h1; j++){
                printf(" %d ", matrix2[i][j]);

                if(j == (h1-1)){
                    printf("\n");
                }
            }
        }

        printf("\nResult is: \n");
        for(i = 0; i<(sizeof(result)/sizeof(result[i])); i++){
            for(j = 0; j<(sizeof(result[i])/sizeof(result[i][j])); j++){
                printf(" %d ", result[i][j]);

                if(j == (h1-1)){
                    printf("\n");
                }
            }
        }

    }else{
        printf("Cannot compute\n");
    }


}


int main()
{

    printf("Enter length for matrix 1: ");
    scanf("%d", &length);
    printf("Enter height for matrix 1: ");
    scanf("%d", &height1);

    printf("Enter length for matrix 2: ");
    scanf("%d", &length1);
    printf("Enter height for matrix 2: ");
    scanf("%d", &height2);

    int matrix1[length][height1];
    int matrix2[length1][height2];

    printf("\n\nMatrix 1:\n");
    input(matrix1, length, height1);

    printf("\n\nMatrix 2:\n");
    input1(matrix2, length1, height2);


    int rl;
    int rh;


    if(length < length1){
            if(height1 < height2){
                rl = length;
                rh = height1;
            }else if(height1 > height2){
                rl = length;
                rh = height2;
            }else if(height1 == height2){
                rl = length;
                rh = height1;
            }
        }else if(length > length1){
            if(height1 < height2){
                rl = length1;
                rh = height1;
            }else if(height1 > height2){
                rl = length;
                rh = height2;
            }else if(height1 == height2){
                rl = length1;
                rh = height1;
            }
        }else if(length == length1){
            if(height1 < height2){
                rl = length;
                rh = height1;
            }else if(height1 > height2){
                rl = length;
                rh = height2;
            }else if(height1 == height2){
                rl = length;
                rh = height1;
            }
        }

    mult(matrix1, matrix2, length, height1, length1, height2, rl, rh);



    return 0;
}
