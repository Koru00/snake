#include "food.h"

food::food(){
    gen_food();
}

void food::gen_food(){
    pos.X = rand() % WIDTH + 1;
    pos.Y = rand() % HEIGHT +1;
}

COORD food::get_pos() {return pos; }