typedef struct command_s {
    char* name;
    int paramCount;
} command;

command commands[] = {{"irow", 1}, {"arow", 0}, {"drow", 1}, {"drows", 2}, {"icol", 1}, {"acol", 0}, {"dcol", 1}, {"dcols", 2}, {"cset", 2}, {"tolower", 1}, {"toupper", 1}, {"round", 1}, {"int", 1}, {"copy", 2}, {"swap", 2}, {"move", 2}};
int knownCommandsCount = 16;
