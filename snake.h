#ifndef SNAKE_H
#define SNAKE_H

#include <Windows.h>

#define WIDTH 55
#define HEIGHT 25

class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;

    public:
        Snake(COORD pos, int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();

        bool eaten(COORD food_pos);

        void grow();
        bool collided();
};

#endif