char* doStuff(int argc, char** argv) {
    //RETURNS ALTERED ROW
    int rowSize = 10240;

    // TREBA POZRIET VSETKY IFy KDE JE DELIMITER A ZMENIT ICH LEBO DELIMITER JE POLE MOZNYCH DELIMITEROV
    char* delim = NULL;
    delim = getDelims(argv); // DEFINUJ DELIM NA TOMTO RIADKU
    if ( delim == NULL ) {
        delim = " ";
    }
    printf("DELIM = '%s'\n", delim);
    char character;
    char row[rowSize];
    int row_id = 1;
    int charsInRowCounter = 0;
    int expectedColumnCount = 0;
    int skip = 0;


    while (scanf("%c", &character) != EOF) {

        if (character != '\n') {
            if (charsInRowCounter < rowSize) {
                row[charsInRowCounter] = character;
                charsInRowCounter++;
            } else {
                printf("Row can't be bigger than 10KiB! Exiting...\n");
                return NULL;
            }
        } else {
            // printf("cols: %d\n", howManyCols(delim, row));
            // TU SA BUDE PRACOVAT S RIADKOM TABULKY
            row[charsInRowCounter] = '\0';

            if ( row_id == 1 ) {
                expectedColumnCount = howManyCols(row, delim);
            }


            if ( expectedColumnCount == howManyCols(row, delim) ) {
                  // OVERENIE CI MA RIADOK ROVNAKY POCET STLPCOV AKO PRVY RIADOK
                int columnCount = expectedColumnCount;
                int startShift = 0;

                if (strcmp(argv[1], "-d") == 0) {       // TREBA DOROBIT AJ PODMIENKU PRE POSUNUTIE STARTU KVOLI VYBERU RIADKOV
                    // printf("Delim exists, jumping on agument 3\n");
                    startShift += 2;
                }

                for (int i = 1+startShift; i < argc; i++) {
                    // printf("%s\n", argv[i]);
                    // printf("argv i: %s\n", argv[i]);

                    // printf("%d\n", i);
                    if (strcmp(argv[i], "irow") == 0) {
                        int param1 = atoi(argv[i+1]);
                        // printf("i: %d, param1: %d, row_id: %d\n", i, param1, row_id);

                        if (row_id == param1) {
                            // printf("Doing irow\n");
                            irow(delim[0], columnCount);
                            i += 1;
                            row_id++;
                            i = 1+startShift;
                        }

                    }

                    if (strcmp(argv[i], "arow") == 0) {

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
                        // printf("rowLen = %lu\n", strlen(row));
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
                return NULL;
            }


            if ( skip == 0 ) {
                // printf("AAA\n");
                printRowWithNewDelim(row, delim);
            } else {
                skip-- ;
            }


            // printf("Row %d: %s\n", row_id, row);

            row_id++;
            charsInRowCounter = 0;

        }
    }

    return NULL;

}
