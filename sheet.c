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


void parseRows(char* data, int m, char parsedRows[][m]) {
    int row = 0;
    // int col = 0;
    int index = 0;

    for (unsigned long i = 0; i < strlen(data); i++) {
        if (data[i] == '\n') {
            row++;
            index = 0;
        }
        parsedRows[row][index] = data[i];
        index++;
    }

    // char* ptr = &parsedRows[0][0];
    // return ptr;
}


char* irow(int r, int m, char parsedRows[][m]) {

    if (r>0) {
        // int cols = howManyCols(parsedRows[0]);
        // int rows = sizeof parsedRows / parsedRows[0];
        // char parsedRowsUpdated[rows+1][m];



        char* ptr = &parsedRows[0][0];
        return ptr;
    } else {
        printf("ERROR: R must be bigger then 0\n");
        return "ERROR";
    }
}



int main(int argc, char const *argv[]) {

    // char DELIM = ';';
    // int ROW_LENGTH = 120;
    //
    // char data[200];
    // scanf("%[^\f]s",data);
    //
    // int rows = howManyRows(data);
    // // int cols = howManyCols(data);
    //
    // char parsedRows[][ROW_LENGTH];
    // parseRows(data, ROW_LENGTH, parsedRows);

    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);


    return 0;
}
