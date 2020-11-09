char** argvParser(int argc, char** argv) {
    int editTableArgs = 0;
    // int editDataArgs = 0;
    int rowSelectionArgs = 0;
    int delim = 0;

    if (argc >= 100) {
        printf("Too many arguments!");
        return NULL;
    }

    // int checkArguments = 0;
    for (int i = 1; i < argc; i++) {
        printf("parsing argument %i, with value '%s'\n", i, argv[i]); //DEBUG

        if (strcmp(argv[i], "-d") == 0) {

            if ( i == 1 && argc > 2 ) {

                // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                printf("SUCCESSFULY PARSED '-d'\n"); //DEBUG
                i = 2;
                delim = 1;

            } else {
                printf("Error: Argument '-d' must be on first position and must have a parameter if used.\n");
                return NULL;
            }

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "rows") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i+2 ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 && isOnlyDigits(argv[i+2]) == 1 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
                        i += 2;
                        rowSelectionArgs++;

                    } else {
                        printf("Error: Both parameters for argument 'rows' must be numbers.\n");
                        return NULL;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'rows'.\n");
                    return NULL;
                }

            } else {
                printf("Error: wrong position of 'rows' argument\n");
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "beginswith") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i+2 ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
                        i += 2;
                        rowSelectionArgs++;

                    } else {
                        printf("Error: First parameter for argument 'beginswith' must be a number.\n");
                        return NULL;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'beginswith'.\n");
                    return NULL;
                }

            } else {
                printf("Error: wrong position of 'beginswith' argument\n");
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "contains") == 0) {

            if ((i == 1 && delim == 0) || (i == 3 && delim == 1)) {

                if ( argc > i+2 ) {

                    if ( isOnlyDigits(argv[i+1]) == 1 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
                        i += 2;
                        rowSelectionArgs++;

                    } else {
                        printf("Error: First parameter for argument 'contains' must be a number.\n");
                        return NULL;
                    }

                } else {
                    printf("Error: Not enough parameters for argument 'contains'.\n");
                    return NULL;
                }

            } else {
                printf("Error: wrong position of 'contains' argument\n");
            }
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "irow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
                        i += paramCount;
                        editTableArgs++;

                    } else {
                        printf("Error: Parameter for argument 'irow' must be a number bigger than 0.\n");
                        return NULL;
                    }

                } else {
                    printf("Error: Parameter for argument 'irow' must be a number bigger than 0.\n");
                    return NULL;
                }

            } else {
                printf("Error: Not enough parameters for argument 'irow'.\n");
                return NULL;
            }

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "arow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
            printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
            i += paramCount;
            editTableArgs++;

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "drow") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "drows") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "icol") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "acol") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "dcol") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "dcols") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "tolower") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "toupper") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "round") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "int") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "copy") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "swap") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "move") == 0) {

        }

    // -------------------------------------------------------------------------------------------------------------

        else {
            printf("Error: Wrong argument used '%s'\n", argv[i]);
            return NULL;
        }

    }

    return NULL;

}
