#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// const char* returnString(char* ahoj){
//     char x[100];
//     scanf("%s", x);
//     strcpy(ahoj, x);
//     // printf("%s\n", x);
//     return ahoj;
// }

int howManyRows(char* data) {
    int rows = 0;
    for (unsigned long i = 0; i < strlen(data); i++) {
        if (data[i] == '\n') {
            rows++;
        }
    }
    return rows;
}

int howManyCols(char* data) {
    int cols = 0;
    for (int i = 0; data[i] != '\n'; i++) {
        if (data[i] == ';') {
            cols++;
        }
    }
    return cols+1;
}

char** fillParsedData(char* data, char** parsedData) {
    int row = 0;
    int col = 0;

    for (unsigned long i = 0; i < strlen(data); i++) {
        if (i==0) {
            parsedData[row][col] = data[i];
        }
    }

    return parsedData;
}



int main() {

    char data[200];
    scanf("%[^\f]s",data);

    int rows = howManyRows(data);
    int cols = howManyCols(data);

    char parsedData[rows+1][cols+1];
    fillParsedData(data, parsedData);



    // char ahoj[100];
    // returnString(ahoj);
    //
    printf("%s\n", data);
    printf("Rows: %d\n", rows);
    printf("Cols: %d\n", cols);
    printf("Parsed: %d\n", parsedData[0][0]);

    return 0;
}
