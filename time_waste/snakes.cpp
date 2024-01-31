#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<conio.h>
// define game variables
#define WIDTH 30
using namespace std;

//handling inputs
void Input(){}

//move functions
void move_left(int game[WIDTH][WIDTH]){
	int snake_x,snake_y;
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<WIDTH;j++){
			//snake vars
			if(game[i][j]==1){
				snake_x = j;
				snake_y = i;
			}
		}
	}

	// new game state
	//set new state
	game[snake_y][snake_x]=0;
	game[snake_y][(snake_x-1)%WIDTH]=1;	
}

void move_right(int game[WIDTH][WIDTH]){
	int snake_x,snake_y;
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<WIDTH;j++){
			//snake vars
			if(game[i][j]==1){
				snake_x = j;
				snake_y = i;
			}
		}
	}

	// new game state
	//set new state
	game[snake_y][snake_x]=0;
	game[snake_y][(snake_x+1)%WIDTH]=1;	
}

// function to print the board
int print(int sprite){
	if(sprite==0){
		cout<<" ";
	}
	else if (sprite==1){
		cout<<"0";
	}
	else if(sprite==2){
		cout<<"$";
	}
	else{
		cout<<"";
	}
}

int main(){


	// snake game
	
	//state of game
	int game[WIDTH][WIDTH];
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<WIDTH;j++){
			game[i][j]=0;
		}
	}

	// starting position of snake
	int snake_x = rand()%WIDTH;
	int snake_y = rand()%WIDTH;
	
	//score of player
	int score = 0;
	int dir = 2;

	//starting food position 
	int food_x = rand()%WIDTH;
	int food_y = rand()%WIDTH;

	//game state variable
	bool is_game_over = false;
	
	// set player and food
	game[snake_y][snake_x]=1;
	game[food_y][food_x]=2;

	// game loop
	while(!is_game_over){
		//clear screen
		system("cls");

		// print score
		cout<<"Your Score : "<<score<<endl;
		for(int i=0;i<WIDTH;i++){
			for(int j=0;j<WIDTH;j++){
				print(game[i][j]);
			}
			cout<<endl;
		}

		//Input();
		if(_kbhit()){
			switch(_getch()){
				case 'a':
					//direction left
					move_left(game);
					break;
				case 'd':
					//direction right
					move_right(game);
					break;
				case 'w':
					//direction up
					score+=3;
					break;
				case 's':
					//directipn down
					score+=4;
					break;
				case 'x':
					//quit game
					is_game_over = true;
					break;
			}
		}					
	}





	return 0;
}
