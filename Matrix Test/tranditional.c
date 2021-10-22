#include <stdio.h>
#include <stdlib.h>

//global variable:
int A_row, A_col, B_row, B_col;

int **ConstructMatrix(int row, int col){
    int **matrix = NULL;
    matrix = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < col;i++){
        matrix[i] = (int *)malloc(sizeof(int) * col);
    }
    return matrix;
}

void readfile(int **A, int **B){
    FILE *fp = fopen("matrix", "r");
    if(fp==NULL)
        printf("hi\n");
    int temp;
    //read A matrix
    for (int i = 0; i < A_row;i++){
        for (int j = 0; j < A_col;j++){
            fscanf(fp, "%d", &temp);
            printf("%d ", temp);
        }
    }


    //read B matrix
    for (int i = 0; i < B_row;i++){
        for (int j = 0; j < B_col;j++){
            fscanf(fp, "%d", &temp);
            printf("%d ", temp);
        }
    }
    fclose(fp);
}

void printMatrix(int **matrix, int row, int col){
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char *argv[]){
    int A_row = atoi(*(argv + 1));
    int A_col = atoi(*(argv + 2));
    int B_row = atoi(*(argv + 3));
    int B_col = atoi(*(argv + 4));

    int **A_matrix = ConstructMatrix(A_row, A_col);
    int **B_matrix = ConstructMatrix(B_row, B_col);
    readfile(A_matrix, B_matrix);
    //printMatrix(A_matrix, A_row, A_col);
    //printMatrix(B_matrix, B_row, B_col);

    return 0;
}