#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct command_s {
    char* name;
    int paramCount;
} command;

command commands[] = {{"irow", 1}, {"arow", 0}, {"drow", 1}, {"drows", 2}, {"icol", 1}, {"acol", 0}, {"dcol", 1}, {"dcols", 2}, {"cset", 2}, {"tolower", 1}, {"toupper", 1}, {"round", 1}, {"int", 1}, {"copy", 2}, {"swap", 2}, {"move", 2}};
int knownCommandsCount = 16;


// +-----------------+
// | Pomocne funkcie |
// +-----------------+
char* getDelims(char** argv) {

    if ( strcmp(argv[1], "-d") == 0 ) {
        return argv[2];
    } else {
        return NULL;
    }

}



int isDelim(char* delim, char x) {
    // Vrati 1 ak x je delimiter

    for (unsigned long i = 0; i < strlen(delim); i++) {
        if ( delim[i] == x ) {
            return 1;
        }
    }

    return 0;

}



command getCommandInfo(char* arg) {
    // Vrati strukturu command s menom arg
    for (int i = 0; i < knownCommandsCount; i++) {
        if ( strcmp(arg, commands[i].name) == 0 ) {
            return commands[i];
        }
    }
    printf("Error in getCommandInfo(): Command not found\n");
    command error = {"error", -1};
    return error;
}



int isOnlyDigits(char* string) {
    // Vrati 1 ak string su len cisla
    int i = 0;
    while (string[i] != '\0') {
        if (isdigit(string[i]) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}



int howManyCols(char* row, char* delim) {
    // Vrati pocet stlpcov v riadku
    int cols = 1;
    for (unsigned long i = 0; i < strlen(row); i++) {
        for (unsigned long j = 0; j < strlen(delim); j++) {
            if ( row[i] == delim[j] ) {
                cols++;
            }
        }
    }
    return cols;
}



void printRowWithNewDelim(char* row, char* delim) {
    // Vytlaci na stdout upraveny riadok s novym delimiterom
    for (unsigned long i = 0; i < strlen(row); i++) {
        if ( isDelim(delim, row[i]) == 1 ) {
            row[i] = delim[0];
        }
    }
    printf("%s\n", row);

}






// +---------------------------+
// | Funkcie na upravu tabulky |
// +---------------------------+
void irow(char delim, int columns) {
    // Vytlaci prazdny riadok na stdout

    for (int i = 0; i < columns; i++) {
        printf("%c", delim);
    }
    printf("\n");

}



void icol(char* delim, int param, char* row) {
    // Vytlaci riadok s novym prazdnym stlpcom na stdout

    char newRow[strlen(row)+1];
    int charInRow_id = 0;
    int col_id = 1;
    int posun = 0;
    unsigned long i = 0;

    for (; i < strlen(row); i++) {

        if ( col_id == param && charInRow_id == 0 ) {
            newRow[i] = delim[0];
            posun = 1;
            i++;
            col_id++;
            charInRow_id = 0;
        }

        for (unsigned long j = 0; j < strlen(delim); j++) {

            int old_i = i;

            if ( posun != 0 ) {
                old_i = i-1;
            }

            if (row[old_i] == delim[j]) {
                newRow[i] = delim[0];
                charInRow_id = 0;
                col_id++;
            } else {
                newRow[i] = row[old_i];
                charInRow_id++;
            }
        }
    }

    newRow[i] = '\0';
    printf("%s\n", newRow);

}



void acol(char* delim, char* row) {
    // Vytlaci upraveny riadok s novym prazdnym stlpcom na konci na stdout

    unsigned long i = 0;
    for (; i < strlen(row); i++) {
        if ( isDelim(delim, row[i]) == 1 ) {
            row[i] = delim[0];
        }
    }

    row[i] = delim[0];
    row[i+1] = '\0';
    printf("%s\n", row);
}



void delLastCol(char* delim, char* row) {
    // Zmaze posledny stlpec a vytlaci riadok na stdout

    char newRow[strlen(row)];
    int col_id = 1;
    int lastCol = howManyCols(delim, row);

    unsigned long i = 0;
    for (; i < strlen(row); i++) {

        if ( isDelim(delim, row[i]) == 1 ) {
            col_id++;
            if ( col_id == lastCol ) {
                break;
            }
            newRow[i] = delim[0];
        } else {
            newRow[i] = row[i];
        }
    }

    newRow[i] = '\0';
    printf("%s\n", newRow);

}



void dcol(char* delim, int param, char* row) {
    // Zmaze riadok param a vytlaci upraveny riadok na stdout

    if ( param == howManyCols(delim, row) ) {
        delLastCol(delim, row);
        return;
    }

    char newRow[strlen(row)];
    int charInRow_id = 0;
    int col_id = 1;
    int skip = 0;
    int posun = 0;

    unsigned long i = 0;
    for (; i < strlen(row); i++) {

        if ( col_id == param && charInRow_id == 0 ) {
            skip = 1;
        }

        if ( skip == 1 && isDelim(delim, row[i]) == 1 ) {
            skip = 0;
            posun++;
            i++;
        }

        if ( skip != 1 ) {
            if ( isDelim(delim, row[i]) == 1 ) {
                newRow[i-posun] = delim[0];
                col_id++;
                charInRow_id = 0;
            } else {
                newRow[i-posun] = row[i];
                charInRow_id++;
            }
        } else {
            posun++;
        }

    }

    newRow[i-posun] = '\0';
    printf("%s\n", newRow);

}



void dcols(char* delim, int param1, int param2, char* row) {
    // Vymaze riadky od param1 do param2 a vytlaci upraveny riadok na stdout

    char newRow[strlen(row)];
    int charInRow_id = 0;
    int col_id = 1;
    int skip = 0;
    int posun = 0;
    int tillEnd = 0;
    if ( param2 >= howManyCols(delim, row) ) {
        tillEnd = 1;
    }

    unsigned long i = 0;
    for (; i < strlen(row); i++) {

        if ( col_id == param1 && charInRow_id == 0 ) {
            skip = 1;
        }

        if ( skip == 1 && isDelim(delim, row[i]) == 1 && col_id == param2 ) {
            skip = 0;
            posun++;
            i++;
        }

        if ( skip != 1 ) {
            if ( isDelim(delim, row[i]) == 1 ) {
                col_id++;
                charInRow_id = 0;
                if ( tillEnd == 1 && col_id == param1 ) {
                    continue;
                } else {
                    newRow[i-posun] = delim[0];
                }
            } else {
                newRow[i-posun] = row[i];
                charInRow_id++;
            }
        } else {
            if ( isDelim(delim, row[i]) == 1 ) {
                col_id++;
            }
            posun++;
        }

    }

    newRow[i-posun] = '\0';
    printf("%s\n", newRow);

}






// +---------------------------------------------------+
// | Overenie argumentov zadanych do prikazovej riadky |
// +---------------------------------------------------+
int argvParser(int argc, char** argv) {
    int editTableArgs = 0;
    int editDataArgs = 0;
    int rowSelectionArgs = 0;
    int delim = 0;

    if (argc >= 100) {
        printf("Error: Too many arguments.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "-d") == 0) {

            if ( i == 1 && argc > 2 ) {

                if ( strlen(argv[i+1]) < 31 ) {

                    i = 2;
                    delim = 1;

                } else {
                    printf("Error: parameter for '-d' can be only 30 characters long\n");
                }
            } else {
                printf("Error: Argument '-d' must be on first position and must have a parameter if used.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "rows") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i + 2 ) {

                    if ( (isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1) || (strcmp(argv[i+1], "-") == 0 && isOnlyDigits(argv[i+2]) == 1) || (isOnlyDigits(argv[i+1]) == 1 && strcmp(argv[i+2], "-") == 0) ) {

                        if ( (atoi(argv[i+1]) > 0 && atoi(argv[i+2]) > 0) || (strcmp(argv[i+1], "-") == 0 && atoi(argv[i+2]) > 0) || (atoi(argv[i+1]) > 0 && strcmp(argv[i+2], "-") == 0) ) {

                            i += 2;
                            rowSelectionArgs++;

                        } else {
                            printf("Error: Both parameters for argument 'rows' must be numbers bigger than 0.\n");
                            return 1;
                        }

                    } else {
                        printf("Error: Both parameters for argument 'rows' must be numbers.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'rows'.\n");
                    return 1;
                }

            } else {
                printf("Error: wrong position of 'rows' argument. (Note: can't use more then one row selection argument.)\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "beginswith") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i + 2 ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 && atoi(argv[i+1]) > 0 ) {

                        i += 2;
                        rowSelectionArgs++;

                    } else {
                        printf("Error: First parameter for argument 'beginswith' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'beginswith'.\n");
                    return 1;
                }

            } else {
                printf("Error: wrong position of 'beginswith' argument. (Note: can't use more then one row selection argument.)\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "contains") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i + 2 ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 && atoi(argv[i+1]) > 0 ) {

                        i += 2;
                        rowSelectionArgs++;

                    } else {
                        printf("Error: First parameter for argument 'contains' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'contains'.\n");
                    return 1;
                }

            } else {
                printf("Error: wrong position of 'contains' argument. (Note: can't use more then one row selection argument.)\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "irow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Parameter for argument 'irow' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'irow' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'irow'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "arow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            i += paramCount;
            editTableArgs++;

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "drow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Parameter for argument 'drow' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'drow' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'drow'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "drows") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 && ((atoi(argv[i+1]) < atoi(argv[i+2])) || (atoi(argv[i+1]) == atoi(argv[i+2]))) ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Both parameters for argument 'drows' must be a number bigger than 0. The Second parameter must be bigger or equal to the first parameter.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Both parameters for argument 'drows' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'drows'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "icol") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Parameter for argument 'icol' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'icol' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'icol'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "acol") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            i += paramCount;
            editTableArgs++;
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "dcol") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Parameter for argument 'dcol' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'dcol' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'dcol'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "dcols") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 && ((atoi(argv[i+1]) < atoi(argv[i+2])) || (atoi(argv[i+1]) == atoi(argv[i+2]))) ) {

                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Both parameter for argument 'dcols' must be a number bigger than 0. The Second parameter must be bigger or equal to the first parameter.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Both parameter for argument 'dcols' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'dcols'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "cset") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

                if ( argc > i + paramCount ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 && atoi(argv[i+1]) > 0 ) {

                        i += 2;
                        editDataArgs++;

                    } else {
                        printf("Error: First parameter for argument 'cset' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'cset'.\n");
                    return 1;
                }
            }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "tolower") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Parameter for argument 'tolower' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'tolower' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'tolower'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "toupper") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Parameter for argument 'toupper' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'toupper' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'toupper'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "round") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Parameter for argument 'round' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'round' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'round'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "int") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Parameter for argument 'int' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Parameter for argument 'int' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'int'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "copy") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Both parameter for argument 'copy' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Both parameter for argument 'copy' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'copy'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "swap") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Both parameter for argument 'swap' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Both parameter for argument 'swap' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'swap'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "move") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        i += paramCount;
                        editDataArgs++;

                    } else {
                        printf("Error: Both parameter for argument 'move' must be a number bigger than 0.\n");
                        return 1;
                    }

                } else {
                    printf("Error: Both parameter for argument 'move' must be a number bigger than 0.\n");
                    return 1;
                }

            } else {
                printf("Error: Not enough parameters for argument 'move'.\n");
                return 1;
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else {
            printf("Error: Unknown argument used '%s'\n", argv[i]);
            return 1;
        }

    }



    if ( editDataArgs > 0 || editTableArgs > 0 || delim == 1 ) {

        if( !(editDataArgs > 0 && editTableArgs > 0) ) {

            if ( editTableArgs > 0 ) {

                if (editTableArgs < 2) {

                    if ( rowSelectionArgs == 0 ) {

                        // EDIT TABLE SUCCESSFULY PARSED

                    } else {
                        printf("Error: Can't use row selection with arguments that edit the table.\n");
                        return 1;
                    }
                } else {
                    printf("Error: Progam can't handle more then 1 edit table argument in one run.\n");
                    return 1;
                }
            }

            else if ( editDataArgs > 0 ) {

                if ( editDataArgs < 2 ) {

                    // EDIT DATA SUCCESSFULY PARSED

                } else {
                    printf("Error: Program can't run multiple arguments that edit table data.\n");
                    return 1;
                }
            }

        } else {
            printf("Error: Program can't edit table and data in one run.\n");
            return 1;
        }
    } else {
        printf("Error: Program needs at least one argument for editing table or data.\n");
        return 1;
    }


    return 0;

}






// +-------------------------------------------------+
// | Funkcia ktora prevedie vsetky upravy na tabulke |
// +-------------------------------------------------+
int argRunner(int argc, char** argv) {
    int rowSize = 10240;

    char* delim = getDelims(argv);
    if ( delim == NULL ) {
        delim = " ";
    }

    char character;
    char row[rowSize];
    int row_id = 1;
    int charsInRowCounter = 0;
    int expectedColumnCount = 0;
    int skip = 0;
    int arow = 0;


    while (scanf("%c", &character) != EOF) {

        if (character != '\n') {
            // Nacitavaju sa charakter po charakteri do pola row az kym sa nenarazi na \n
            if (charsInRowCounter < rowSize) {
                row[charsInRowCounter] = character;
                charsInRowCounter++;
            } else {
                printf("Row can't be bigger than 10KiB! Exiting...\n");
                return 1;
            }
        } else {
            // Ked sa narazi na \n, riadok sa ukonci \0 a nasledne prejde procesom spracovania kde sa upravi ako bude treba.
            row[charsInRowCounter] = '\0';

            if ( row_id == 1 ) {
                expectedColumnCount = howManyCols(row, delim);
            }


            if ( expectedColumnCount == howManyCols(row, delim) ) {
                int columnCount = expectedColumnCount;
                int startShift = 0;

                if (strcmp(argv[1], "-d") == 0) {
                    startShift += 2;
                }

                for (int i = 1+startShift; i < argc; i++) {

                    if (strcmp(argv[i], "irow") == 0) {
                        int param1 = atoi(argv[i+1]);

                        if (row_id == param1) {
                            irow(delim[0], columnCount);
                            i += 1;
                            row_id++;
                            i = 1+startShift;
                        }

                    }

                    if (strcmp(argv[i], "arow") == 0) {
                        arow = 1;
                    }

                    if (strcmp(argv[i], "drow") == 0) {
                        int param1 = atoi(argv[i+1]);

                        if ( row_id == param1 ) {
                            skip = 1;
                        }
                    }

                    if (strcmp(argv[i], "drows") == 0) {
                        int param1 = atoi(argv[i+1]);
                        int param2 = atoi(argv[i+2]);

                        if ( row_id == param1 ) {
                            skip = param2-param1+1;
                        }
                    }

                    if (strcmp(argv[i], "icol") == 0) {
                        int param1 = atoi(argv[i+1]);
                        icol(delim, param1, row);
                        skip = 1;
                    }


                    if (strcmp(argv[i], "acol") == 0) {
                        acol(delim, row);
                        skip = 1;
                    }

                    if (strcmp(argv[i], "dcol") == 0) {
                        int param1 = atoi(argv[i+1]);
                        dcol(delim, param1, row);
                        skip = 1;
                    }

                    if (strcmp(argv[i], "dcols") == 0) {
                        int param1 = atoi(argv[i+1]);
                        int param2 = atoi(argv[i+2]);
                        dcols(delim, param1, param2, row);
                        skip = 1;
                    }

                    if (strcmp(argv[i], "cset") == 0) {

                    }

                    if (strcmp(argv[i], "tolower") == 0) {

                    }

                    if (strcmp(argv[i], "toupper") == 0) {

                    }

                    if (strcmp(argv[i], "round") == 0) {

                    }

                    if (strcmp(argv[i], "int") == 0) {

                    }

                    if (strcmp(argv[i], "copy") == 0) {

                    }

                    if (strcmp(argv[i], "swap") == 0) {

                    }

                    if (strcmp(argv[i], "move") == 0) {

                    }


                }

            } else {
                printf("Error: wrong number of columns in row number %d\n", row_id);
                return 1;
            }


            if ( skip == 0 ) {
                // Ak sa s riadkom nerobila ziadna uprava, tak sa vytlaci na stdout s novym delimiterom
                printRowWithNewDelim(row, delim);
            } else {
                skip-- ;
            }

            row_id++;
            charsInRowCounter = 0;

        }
    }

    if ( arow == 1 ) {
        irow(delim[0], expectedColumnCount);
    }

    if ( row_id == 1 ) {
        printf("Error: input file can't be empty.\n");
        return 1;
    }

    return 0;

}





// +-------------------------------------------------------------------+
// | V maine len spustim dve velke funkcie ktore sa o vsetko postaraju |
// +-------------------------------------------------------------------+
int main(int argc, char* argv[]) {

    // VSTUPNA TABULKA NESMIE BYT PRAZDNA

    int checkParser = argvParser(argc, argv);
    if ( checkParser != 1 ) {
        int checkRunner = argRunner(argc, argv);
        if ( checkRunner == 1 ) {
            return 1;
        }
    } else {
        return 1;
    }




    return 0;
}
