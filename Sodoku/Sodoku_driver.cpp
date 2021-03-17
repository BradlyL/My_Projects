#include <stdio.h>
#include <iostream>
#include "Sodoku.h"

int main () {
    Sodoku s;

    s.create_board();
    s.add_value(3, 1, 0);

    return 0;
}