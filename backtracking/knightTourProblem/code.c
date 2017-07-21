#include <stdio.h>
#include <stdlib.h>


enum knightJump  {
	first,	// left left up posistion
	second,	// left up up
	third,	// right up up
	fourth,	// right right up
	fifth,	// right right down
	sixth,	// right down down
	seventh,// left down down
	eighth,	// left left down
};


struct chessCell {
	int val;
};

struct chessBoard {

	struct chessCell cell[8][8];
	int knightJumpCount;
	int currRow;
	int currCol;
};

void initGame(struct chessBoard *game) {

	int i=0;
	int j =0;
	for(i = 0; i < 8; i++) {
		for(j=0; j<8; j++) {
	
			if((i == 0) && (j == 0))
				(game->cell[i][j]).val == 0;
			else
				(game->cell[i][j]).val = -1;
		}
	}

	game->currRow = 0;
	game->currCol = 0;
}

void printBoard(struct chessBoard *game) {

	int i,j;
	for(i =0; i<8 ; i++) {
		for(j = 0; j<8 ; j++)
			printf(" %2d |",(game->cell[i][j]).val);

		printf("\n");
	}
}

int checkIsOperationPossible(struct chessBoard *game, enum knightJump op) {

	int ret = 0;

	int row = game->currRow;
	int col = game->currCol;

	switch(op) {

		case first : {
				    if(((row - 1) >=0) && ((col - 2) >=0)) {
					    if(game->cell[row-1][col-2].val == -1) {
						    printf("Knight can perform first operation\n");
						    ret = 1;
					    }

				    }
				    break;
		}
		case second : {
				    if(((row - 2) >=0) && ((col - 1) >=0)) {
					    if(game->cell[row-2][col-1].val == -1) {
						    printf("Knight can perform second operation\n");
						    ret = 1;
					    }
				    }
				    break;
		}
		case third : {
				    if(((row - 2) >=0) && ((col + 1) <8)) {
					    if(game->cell[row-2][col+1].val == -1) {
						    printf("Knight can perform third operation\n");
						    ret = 1;
					    }
				    }
				    break;
		}
		case fourth : {
				   //*destRow = row - 1;
				   // *destCol = col + 2;
				    if(((row - 1) >=0) && ((col + 2) <8)) {
					    if(game->cell[row-1][col+2].val == -1) {
						    printf("Knight can perform fourth operation\n");
						    ret = 1;
					    }
				    }
				    break;
		}
		case fifth : {
				    //*destRow = row + 1;
				    //*destCol = col + 2;
				    if(((row + 1) <8) && ((col + 2) <8)) {
					    if(game->cell[row+1][col+2].val == -1) {
						    printf("Knight can perform fifth operation\n");
						    ret = 1;
					    }
				    }
				    break;
		}
		case sixth: {
				    //*destRow = row + 2;
				    //*destCol = col + 1;
				    if(((row + 2) <8) && ((col + 1) <8)) {
					    if(game->cell[row+2][col+1].val == -1) {
						    printf("Knight can perform sixth operation\n");
						    ret = 1;
					    }
				    }
				    break;
		}
		case seventh: {
				    //*destRow = row + 2;
				    //*destCol = col - 1;
				    if(((row + 2) <8) && ((col - 1) >=0)) {
					    if(game->cell[row+2][col-1].val == -1) {
						    printf("Knight can perform seventh operation\n");
						    ret = 1;
					    }
				    }
						    
				    break;
		}
		case eighth: {
				    //*destRow = row + 1;
				    //*destCol = col - 2;
				    if(((row + 1) < 8) && ((col - 2) >=0)) {
					    if(game->cell[row+1][col-2].val == -1) {
						    printf("Knight can perform eighth operation\n");
						    ret = 1;
					    }
				    }

				    break;

			break;
		}
		default: {

			printf("ERROR : in operation value. exiting!!!\n");
			exit(-1);
		}
	}

	return ret;
}

struct chessBoard performOperation(struct chessBoard *Game, enum knightJump op) {

	struct chessBoard game = *Game;

	switch(op) {

		case first : {
				     
				     game.cell[game.currRow - 1][game.currCol-2].val = ++(game.knightJumpCount);
				     game.currRow -= 1;
				     game.currCol -= 2;

				     printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
				    break;
		}
		case second : {

				     game.cell[game.currRow - 2][game.currCol-1].val = ++(game.knightJumpCount);
				     game.currRow -= 2;
				     game.currCol -= 1;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
				    break;
		}
		case third : {
				     game.cell[game.currRow - 2][game.currCol+1].val = ++(game.knightJumpCount);
				     game.currRow -= 2;
				     game.currCol += 1;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
				    break;
		}
		case fourth : {
				   //*destRow = row - 1;
				   // *destCol = col + 2;
				     game.cell[game.currRow - 1][game.currCol+2].val = ++(game.knightJumpCount);
				     game.currRow -= 1;
				     game.currCol += 2;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
				    break;
		}
		case fifth : {
				    //*destRow = row + 1;
				    //*destCol = col + 2;
				     game.cell[game.currRow + 1][game.currCol+2].val = ++(game.knightJumpCount);
				     game.currRow += 1;
				     game.currCol += 2;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
				    break;
		}
		case sixth: {
				    //*destRow = row + 2;
				    //*destCol = col + 1;
				     game.cell[game.currRow + 2][game.currCol+1].val = ++(game.knightJumpCount);
				     game.currRow += 2;
				     game.currCol += 1;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);

				    break;
		}
		case seventh: {
				    //*destRow = row + 2;
				    //*destCol = col - 1;
				     game.cell[game.currRow + 2][game.currCol - 1].val = ++(game.knightJumpCount);
				     game.currRow += 2;
				     game.currCol -= 1;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);
						    
				    break;
		}
		case eighth: {
				    //*destRow = row + 1;
				    //*destCol = col - 2;
				     game.cell[game.currRow + 1][game.currCol-2].val = ++(game.knightJumpCount);
				     game.currRow += 1;
				     game.currCol -= 2;

				    printf("new row = %d new col = %d, new jump count = %d\n",game.currRow,game.currCol,game.knightJumpCount);

				    break;

			break;
		}
		default: {

			printf("ERROR : in operation value. exiting!!!\n");
			exit(-1);
		}
	}

	return game;
}

int isGameFinished(struct chessBoard *game) {

	if(game) {

		if(game->knightJumpCount == 63)
			return 1;
	}

/*
		int i , j;
		for(i = 0; i<8; i++) {
			for(j =0; j<8; j++) {
				if(game->cell[i][j].val == -1)
					return 0;
			}
		}
*/

	return 0;
}


int playGame(struct chessBoard game) {

	
	int i =0;
	int ret = 0;
	if(isGameFinished(&game)) {
		printf("Game over\n");
		printBoard(&game);
		return 1;
	}

	for(i = first; !ret && (i <= eighth); i++) {
		if(checkIsOperationPossible(&game,i)) {
			struct chessBoard temp = performOperation(&game,i);
			//printBoard(&temp);
			ret = playGame(temp);

		}
	}

	if(!ret) {
		//printf("returning from current recursion\n");
		//printBoard(&game);
	}
	
	return ret;
}



int main() {
	
	struct chessBoard game;
	game.knightJumpCount = 0;

	initGame(&game);

	playGame(game);

	printBoard(&game);


	return 0;
}
