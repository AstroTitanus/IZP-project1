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
        // printf("parsing argument %i, with value '%s'\n", i, argv[i]); //DEBUG

        if (strcmp(argv[i], "-d") == 0) {

            if ( i == 1 && argc > 2 ) {

                if ( strlen(argv[i+1]) < 31 ) {

                    // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                    // printf("SUCCESSFULY PARSED '-d'\n"); //DEBUG
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

                            // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                            // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

            // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
            // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
            i += paramCount;
            editTableArgs++;

        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "drow") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

            // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
            printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
            i += paramCount;
            editTableArgs++;
        }

    // -------------------------------------------------------------------------------------------------------------

        else if (strcmp(argv[i], "dcol") == 0) {
            int paramCount = getCommandInfo(argv[i]).paramCount;

            if ( argc > i + paramCount ) {

                if ( isOnlyDigits(argv[i+1]) == 1 ) {

                    if ( atoi(argv[i+1]) > 0 ) {

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // SUCCESS - ARGUMENT JE OVERENY, SEM PRIDE KOD CO SA STANE POTOM
                        // printf("SUCCESSFULY PARSED '%s'\n", argv[i]); //DEBUG
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

                        // printf("EDIT TABLE SUCCESS\n");


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

                    // printf("EDIT TABLE DATA SUCCESS\n");
                    // int result[] = {1, delim, rowSelectionArgs};
                    // return result;

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


    return 0; // IDEA - daj do commands pola aj -d, rows, ... , a vratis pole struct commandov ktrore sa maju vykonat aj s argumentami

}
