#ifndef FOOD_H
#define FOOD_H

#include <Windows.h>
#include <cstdlib>

#define WIDTH 55
#define HEIGHT 25

class food
{
private:
    COORD pos;

public:
    food();
    void gen_food();
    COORD get_pos();
};


#endif