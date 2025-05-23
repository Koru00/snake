#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include "snake.h"
#include "food.h"

#define WIDTH 55
#define HEIGHT 25


using namespace std;

/*papo non sa fare loop infiniti ovunque*/

int x=10, y=10;


Snake snake({WIDTH/2, HEIGHT/2}, 1);
food food;

void board(){
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    for (int i = 0; i< HEIGHT; i++){
        std::cout << "\t\t#";
        for (int j = 0; j < WIDTH-2; j++){
            if(i == 0 || i == HEIGHT-1) cout << '#';
            else if(i== snake_pos.Y && j ==snake_pos.X) cout << '0';
            else if(i == food_pos.Y && j == food_pos.X) cout << '*';
            else cout << ' ';
        }
        cout << "#\n";
    }
}


int main(){
    

    srand(time(NULL));

    HANDLE evento = CreateEvent(NULL, FALSE, FALSE, NULL);

    bool game_over = false;
    while(!game_over){
    board();

    WaitForSingleObject(evento, 500);

    

    if(kbhit()){
        switch (getch())
        {
        case 'w': snake.change_dir('u'); break;
        case 'a': snake.change_dir('l'); break;
        case 's': snake.change_dir('d'); break;
        case 'd': snake.change_dir('r'); break;
        }
    }
    snake.move_snake();

    if(snake.eaten(food.get_pos())){
        food.gen_food();
        snake.grow();
    }
    if(snake.collided()) game_over = true;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    

}