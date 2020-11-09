char** argvParser(int argc, char** argv) {

    if (argc >= 100) {
        printf("Too many arguments!");
        return NULL;
    }

    // int checkArguments = 0;
    for (int i = 1; i < argc; i++) {
        printf("parsing argument: %i, with value: %s\n", i, argv[i]); //DEBUG

        if (strcmp(argv[i], "-d") == 0) {

            if ( i == 1 && argc > 2 ) {

                for (int j = 0; j < knownCommandsCount; j++) {
                    if (strcmp(argv[2], commands[j].name) == 0) {
                        printf("Parameter for -d can't be a name of another argument.\n");
                        return NULL;
                    }
                }

                // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM

                i = 2;

            } else {
                printf("argument -d must be on first position and must have a parameter if used.\n");
                return NULL;
            }
        }

        else if (strcmp(argv[i], "rows") == 0) {



        }

        else if (strcmp(argv[i], "beginswith") == 0) {

        }

        else if (strcmp(argv[i], "contains") == 0) {

        }

        else if (strcmp(argv[i], "irow") == 0) {

        }

        else if (strcmp(argv[i], "arow") == 0) {

        }

        else if (strcmp(argv[i], "drow") == 0) {

        }

        else if (strcmp(argv[i], "drows") == 0) {

        }

        else if (strcmp(argv[i], "icol") == 0) {

        }

        else if (strcmp(argv[i], "acol") == 0) {

        }

        else if (strcmp(argv[i], "dcol") == 0) {

        }

        else if (strcmp(argv[i], "dcols") == 0) {

        }

        else if (strcmp(argv[i], "tolower") == 0) {

        }

        else if (strcmp(argv[i], "toupper") == 0) {

        }

        else if (strcmp(argv[i], "round") == 0) {

        }

        else if (strcmp(argv[i], "int") == 0) {

        }

        else if (strcmp(argv[i], "copy") == 0) {

        }

        else if (strcmp(argv[i], "swap") == 0) {

        }

        else if (strcmp(argv[i], "move") == 0) {

        }

        else {
            printf("Wrong argument used \"%s\"\n", argv[i]);
            return NULL;
        }

    }

    return NULL;

}
