#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "argParser.h"
#include "helper.h"

// const char* returnString(char* ahoj){
//     char x[100];
//     scanf("%s", x);
//     strcpy(ahoj, x);
//     // printf("%s\n", x);
//     return ahoj;
// }






// int getMode(int argc, char* argv[]) {
//     char editTable[][6] = {"irow", "arow", "drow", "drows", "icol", "acol", "dcol", "dcols"};
//     char editData[][8] = {"cset", "tolower", "toupper", "round", "int", "copy", "swap", "move"};
//
//     int editTableScore = 0;
//     int editDataScore = 0;
//     // int argParameterScore = 0;
//
//     // Zrata kolko argumentov bolo zadanych z jednotlivych odvetvi (uprava tabulky/uprava dat)
//     for (int i = 0; i < 7; i++) {
//         for (int x = 1; x < argc; x++) {
//
//             if (strcmp(editTable[i], argv[x]) == 0) {
//                 editTableScore++;
//                 i = i+getArgumentCount(argv[x]);
//             }
//             else if (strcmp(editData[i], argv[x]) == 0) {
//                 editDataScore++;
//             }
//             else {
//
//             }
//         }
//     }
//
//     printf("editTableScore: %d\n", editTableScore);
//     printf("editDataScore: %d\n", editDataScore);
//
//     if (editTableScore != 0 && editDataScore == 0) {
//         printf("Edditing TABLE\n");
//     } else if (editTableScore == 0 && editDataScore != 0) {
//         // return 1;
//         printf("Edditing DATA\n");
//     } else {
//         printf("ERROR - WRONG ARGUMENTS\n");
//     }
//
//     return 0;
// }



int main(int argc, char* argv[]) {


    printf("%d\n", argc);
    argvParser(argc, argv); //Treba dorobit overenie ci funkcia nevratila NULL


    // int rowSize = 10240;
    //
    //
    // char character;
    // char row[rowSize];
    // int rowCounter = 1;
    // int charsInRowCounter = 0;
    //
    //
    // while (scanf("%c", &character) != EOF) {
    //
    //     if (character != '\n') {
    //         if (charsInRowCounter >= rowSize) {
    //             printf("Row can't be bigger than 10KiB! Exiting...\n");
    //             return 1;
    //         } else {
    //             row[charsInRowCounter] = character;
    //             charsInRowCounter++;
    //         }
    //     } else {
    //         row[charsInRowCounter] = '\0';
    //         printf("--------------\n");
    //         printf("Row %d: %s\n", rowCounter, row);
    //
    //         rowCounter++;
    //         charsInRowCounter = 0;
    //
    //     }
    // }


    return 0;
}


























































// getMode(argc, argv);
//
// if (argc > 1) {

    // for (int i = 1; i < argc; i++) {
        //     switch (argv[i]) {
            //        case "irow":
            //    }
            // }



            // } else {
                //     printf("Je treba zadat aspon jeden argument\n");
                //     return 2;
                // }

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

                // printf("argc: %d\n", argc);
                // printf("%s\n", argv[0]);
                // printf("%s\n", argv[1]);
                // printf("%s\n", argv[2]);
