#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <string>
using namespace std;

bool gameOver;
int x, y, fruitX, fruitY, score;
int snakeX[1000], snakeY[1000];
int length = 1;
int height = 30, width = 50;
enum Direction{STOP=0, LEFT, RIGHT, UP, DOWN};
Direction dir;


void Setup(){
	srand(time(NULL));
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
    score = 0;

    snakeX[0] = x;
	snakeY[0] = y;
}

void Logic(){

    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x >= width - 1)
    	x = x % (width - 1) + 1;
    else if(x == 0)
    	x = width - 2;

    if(y >= height - 1)
    	y = y % (height - 1) + 1;
   	else if(y == 0)
   		y = height - 2; 

   	if(x == fruitX && y == fruitY){
   		score += 10 * (1 + (int)( 0.1 * length));
   		fruitX = rand() % (width - 2) + 1;
    	fruitY = rand() % (height - 2) + 1;
    	length++;
    }

    for(int i = 1; i < length; i++){
    	if(snakeX[i] == x && snakeY[i] == y)
    		gameOver = TRUE;
    }
    int prevX = snakeX[0];
	int prevY = snakeY[0];
	int prev2X, prev2Y;
	snakeX[0] = x;
	snakeY[0] = y;

	for(int i = 1; i < length; i++){
		prev2X = snakeX[i];
		prev2Y = snakeY[i];
		snakeX[i] = prevX;
		snakeY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Input(){
	int ch;
	ch = getch();
	switch(ch){
        case KEY_LEFT:
        	if(dir == RIGHT)
        		break;
            else
            	dir = LEFT;
            	break;
        case KEY_RIGHT:
        	if(dir == LEFT)
        		break;
        	else
            	dir = RIGHT;
            	break;
        case KEY_UP:
        	if(dir == DOWN)
        		break;
        	else
            	dir = UP;
            	break;
        case KEY_DOWN:
        	if(dir == UP)
        		break;
        	else
            	dir = DOWN;
            	break;

        case 'a':
        	if(dir == RIGHT)
        		break;
            else
            	dir = LEFT;
            	break;
        case 'd':
        	if(dir == LEFT)
        		break;
        	else
            	dir = RIGHT;
            	break;
        case 'w':
        	if(dir == DOWN)
        		break;
        	else
            	dir = UP;
            	break;
        case 's':
        	if(dir == UP)
        		break;
        	else
            	dir = DOWN;
            	break;
        case 'x':
            gameOver = true;
            break;
        case ERR:
            break;
    }

}

void Draw(){
	WINDOW * win = newwin(height, width, 0, 0);
	refresh();
	int l = 0, r = 0, t = 0, b = 0, tlc, trc, blc, brc;
	tlc = trc = blc = brc = 0;
 	wborder(win, l, r, t, b, tlc, trc, blc, brc);
	wrefresh(win);

	mvwprintw(win, y, x, "O");
	wrefresh(win);

	mvwprintw(win, fruitY, fruitX, "$");
	wrefresh(win);

	for(int i = 1; i < length; i++){
		mvwprintw(win, snakeY[i], snakeX[i], "$");
		wrefresh(win);
	}

	string s = "Score: " + to_string(score);
	const char *arr = s.c_str();
	mvwprintw(stdscr, height - 2, width + 2, arr);
	wrefresh(win);

	wmove(win, 0, 0);
	wrefresh(win);
}

void run(){
	initscr();
	nodelay(stdscr, TRUE);
	noecho();
	cbreak();
	Setup();
	keypad(stdscr, TRUE);

	while(TRUE){
		if(!gameOver){
			Logic();
			Input();
			Draw();	
		}
		else{
			endwin();
			break;
		}
		usleep(100000 * pow(0.85, sqrt(length)));
	}

	initscr();
	nodelay(stdscr, false);
	WINDOW * win = newwin(height, width, 0, 0);
	refresh();

	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(win);

	mvwprintw(win, height / 2, width / 2 - 12, "You scuk, loser!");
	wrefresh(win);
	getch();
	endwin();
}

int main(){
	cout << "Enter grid size(default is 30X50): " << endl;
	int w, h;
	cin >> h >> w;
	width = w;
	height = h;
	run();
	return 0;
}