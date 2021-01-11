// ENSC 251, LAB02
// Romina Rahmani
// 301325094
// This program prints 100 different boards
//with placed ships.

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// Length, sign and the number of ships:

//Battleship
const char b_sign= 'B';
const int b_num= 1;

//Cruiser
const char c_sign= 'C';
const int c_num= 2;

 //Cargo ship
const char s_sign= 'S';
const int s_num= 5;

 //Submarine
const char sub_sign= '_';
const int sub_num= 10;

char board [8][8];

int reset_board(){
   
	for (int i=0; i<8; i++){
       for (int j=0; j<8; j++){
          board[i][j] = ' ';
   }
  }
 
return 0;
}

int print_board(){ 
 
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
       cout<< board[i][j]<< " ";
   }
  cout<< endl; 
  }
 
return 0;
}

void generate_battleship(){ // Place battleship
   
   int i = 0;
   while(i < b_num) {
     int x = rand() % 8;
  	 int y = rand() % 8;
	   if (y<5){
		  board[y][x]= b_sign;
		  board[y+1][x]= b_sign;
		  board[y+2][x]= b_sign;
		  board[y+3][x]= b_sign;
		 i++;
	}
   }
  }

void generate_cruiser(){ // Place cruiser
    
	int i = 0;
    while(i < c_num) {
    int x = rand() % 8;
  	int y = rand() % 8;
    if (y<6){
		 if (board[y][x]==' ' && board[y+1][x]==' ' && board[y+2][x]==' '){
			board[y][x]= c_sign;
			board[y+1][x]= c_sign;
			board[y+2][x]= c_sign;
			i++;
		}
	 }
   }
}

void generate_cargo(){// Place cargo ship
    
	int j = 0;
	while (j < s_num){
      int x = rand() % 8;
  	  int y = rand() % 8;
		if (y<7){
			if (board[y][x]==' ' && board[y+1][x]==' '){
             board[y][x]= s_sign;
			 board[y+1][x]= s_sign;
			 j++;
		}
	  }
   }
}

void generate_submarine(){ // Place submarine
    
	int i = 0;
    while(i < sub_num) {
    int x = rand() % 8;
  	int y = rand() % 8;
    	if (board[y][x]==' '){
		     board[y][x]= sub_sign;
			 i++;
	}
  }
}

// Print in the main function
int main(){
  srand (time(NULL)); // Uses computer's internal clock
  int rep= 0;         //to generate random number each time
  while (rep < 100){
     cout<< endl << "Board Number: " << rep+1 << endl;
     reset_board();
     generate_battleship();
     generate_cruiser();
     generate_cargo();
     generate_submarine();
     print_board();
     rep++;
  }
 return 0;
}