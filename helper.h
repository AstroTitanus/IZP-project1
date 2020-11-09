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


int getArgumentCount(char* arg) {
    if (atoi(arg) != 0) {
        printf("Argument can't contain a number!\n");
        return -1;
    } else {
        for (int i = 0; i < 32; i=i+2) {
            if ( strcmp(arg, commands[i].name) == 0 ) {
                printf("%s\n", commands[i+1].name);
                return atoi(commands[i+1].name);
            }
        }
    }
    return -1;
}


int isOnlyDigits(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        if (isdigit(string[i]) == 0) {
            // printf("OBSAHUJE PISMENO\n");
            return 0;
        }
        i++;
    }
    return 1;
}
