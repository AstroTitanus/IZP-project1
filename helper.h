char* getDelims(char** argv) {

    if ( strcmp(argv[1], "-d") == 0 ) {
        return argv[2];
    } else {
        return NULL;
    }

}



int isDelim(char* delim, char x) {

    for (unsigned long i = 0; i < strlen(delim); i++) {
        if ( delim[i] == x ) {
            return 1;
        }
    }

    return 0;

}



command getCommandInfo(char* arg) {
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

    for (unsigned long i = 0; i < strlen(row); i++) {
        if ( isDelim(delim, row[i]) == 1 ) {
            row[i] = delim[0];
        }
    }
    printf("%s\n", row);

}



void irow(char delim, int columns) {

    for (int i = 0; i < columns; i++) {
        printf("%c", delim);
    }
    printf("\n");

}



void icol(char* delim, int param, char* row) {

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

    if ( param == howManyCols(delim, row) ) {
        delLastCol(delim, row);
        return;
    }
    // printf("cols: %d\n", howManyCols(delim, row));

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
                // printf("%d ", charInRow_id);
            }
        } else {
            posun++;
        }

    }

    newRow[i-posun] = '\0';
    printf("%s\n", newRow);

}



void dcols(char* delim, int param1, int param2, char* row) {

    char newRow[strlen(row)];
    int charInRow_id = 0;
    int col_id = 1;
    int skip = 0;
    int posun = 0;
    int tillEnd = 0;
    if ( param2 >= howManyCols(delim, row) ) {
        tillEnd = 1;
        // printf("Tillend\n");
    }

    unsigned long i = 0;
    for (; i < strlen(row); i++) {

        if ( col_id == param1 && charInRow_id == 0 ) {
            skip = 1;
        }

        // printf("col_id = %d\n", col_id);

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
                // printf("%d ", charInRow_id);
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
