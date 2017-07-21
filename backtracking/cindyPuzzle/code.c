#include <stdio.h>
#include <malloc.h>

enum marble_colour { white, black, space };
enum game_operation { jump_over, space_exchange};


struct marble_type {

	enum marble_colour colour;
	int position;
};
	
struct board_content {
	//struct marble_type marble;
	enum marble_colour colour;
};

struct game {

	struct board_content marbles[7];
	int noOfWhites;
	int noOfBlacks;
	int boardSize;
};


char *getOperation(enum game_operation op) {
	
	if(op == jump_over)
		return "jump Over";
	else if(op == space_exchange)
		return "space Exchange";
	else
		return "ERROR";
}

char *getColourString(enum marble_colour marble) {
	if(marble == white)
		return "white";
	else if(marble == black)
		return "black";
	else if(marble == space)
		return "space";
	else
		return "ERROR";
}

void printBoard(struct game *game) {

	if(game) {
		int i =0;
		for(i=0 ; i<game->boardSize ; i++) {
			//printf("i = %d, colour = %s\n",i,getColourString((game->marbles[i]).colour));
			printf("%s ",getColourString(game->marbles[i].colour));
		}
		printf("\n\n");
	}

}

struct game createGame1(int whites, int blacks, int size) {

	int i = 0;		
	struct game temp;// = malloc(sizeof(struct game));
	temp.noOfWhites = whites;
	temp.noOfBlacks = blacks;
	temp.boardSize = size;
	//temp.marbles = malloc(sizeof(struct marble_type));
	//if(!temp.marbles) {
		//free(temp);
		//return 0;
	//}
	for(i = 0; i<whites ; i++)
		(temp.marbles[i]).colour = white;
	
	(temp.marbles[i++]).colour = space;

	for(;i<size; i++)
		(temp.marbles[i]).colour = black;

	return temp;
}

/*
struct game * createGame(int whites, int blacks, int size) {

	int i = 0;		
	struct game *temp = malloc(sizeof(struct game));
	if(temp) {
		temp->noOfWhites = whites;
		temp->noOfBlacks = blacks;
		temp->boardSize = size;
		temp->marbles = malloc(sizeof(struct marble_type)*size);
		if(!temp->marbles) {
			free(temp);
			return NULL;
		}

		for(i = 0; i<whites ; i++)
			(temp->marbles[i]).colour = white;
		
		(temp->marbles[i++]).colour = space;

		for(;i<size; i++)
			(temp->marbles[i]).colour = black;
	

	}

	return temp;
}
*/
//white marble can only go in right direction
//black marble can only go in left direction
//possible operation
//1. a marble can exchange itself with space in the right direction for that marble
//2. a marble can jump over other marble in the right direction only if there is a space after the jump.


int checkIsOperationPossible(struct game *game, int index, enum game_operation op) {

	int ret = 0;
	if(!game)
		return 0;
	
	if((game->marbles[index]).colour == space)
		return 0;

	if(op == space_exchange) {

		if((game->marbles[index]).colour == white) {
		
			if((index+1) <= game->boardSize)
				if(game->marbles[index+1].colour == space)
					ret = 1;
		} 
		else if ((game->marbles[index]).colour == black) {
			if((index-1) >= 0)
				if((game->marbles[index-1]).colour == space)
					ret = 1;
		}

		
	}
	else if(op == jump_over) {

		if((game->marbles[index]).colour == white) {
			if((index+2) <= game->boardSize)
				if(game->marbles[index+2].colour == space)
					ret = 1;
		} 
		else if ((game->marbles[index]).colour == black) {
			if((index-2) >= 0)
				if((game->marbles[index-2]).colour == space)
					ret = 1;
		}

		//if(ret)
		//	printf("jump over operation for index %d is possible\n",index);
	}
	//else
	//	return 0;
/*
	if(ret)
		printf("%s operation for index %d is possible\n",getOperation(op),index);
	else
		printf("%s operation for index %d is not possible\n",getOperation(op),index);
*/

	return ret;
}


void swap(struct game *game, int index1, int index2) {

	struct board_content temp = game->marbles[index1];
	game->marbles[index1] = game->marbles[index2];
	game->marbles[index2] = temp;

}

struct game performOperation(struct game board, int index, enum game_operation op) {

	struct game *game = &board;
	if(op == space_exchange) {

		//printf("performing space exchange\n");

                if((game->marbles[index]).colour == white) {

                        if(((index+1) <= game->boardSize) && (game->marbles[index+1].colour == space)) {
					swap(game,index,index+1);
			}
                }
                else if ((game->marbles[index]).colour == black) {

                        if(((index-1) >= 0) && ((game->marbles[index-1]).colour == space)) {
                                 	swap(game,index,index-1);
			}
                }

		
	}
	else if(op == jump_over) {

		//printf("performing jump over\n");

                if((game->marbles[index]).colour == white) {

                        if(((index+2) <= game->boardSize) && (game->marbles[index+2].colour == space)) {
					swap(game,index,index+2);
			}
                }
                else if ((game->marbles[index]).colour == black) {

                        if(((index-2) >= 0) && ((game->marbles[index-2]).colour == space)) {
                                 	swap(game,index,index-2);
			}
                }

	}

	//printBoard(game);
	return *game;
}

int isGameFinished(struct game *game) {

	int i = 0;
	for(i = 0; i < game->boardSize; i++) {

		if(i < game->noOfBlacks && (game->marbles[i]).colour != black) {
			//printf("%d is not  black\n",i);
			return 0;
		}
		else if( i == game->noOfBlacks && (game->marbles[i]).colour != space) {
			//printf("%d is not space\n",i);
			return 0;
		}
		else if(i > game->noOfBlacks+1 && (game->marbles[i]).colour != white) {
			//printf("%d id not white\n");
			return 0;
		}
	}

	return 1;

}


int playGame(struct game game) {

	int i =0;
	int j =0;
	int ret = 0;

	if(isGameFinished(&game)) {
		printBoard(&game);
		return 1;
	}


	for(i=0; i <game.boardSize; i++) {

		if(checkIsOperationPossible(&game,i,space_exchange)) {
			struct game newGame = performOperation(game,i,space_exchange);
			//printf("space_exchange @ %d : ",i);
			//printBoard(&newGame);
			ret = playGame(newGame);
		}
			
		if(!ret && checkIsOperationPossible(&game,i,jump_over)) {
			struct game newGame = performOperation(game,i,jump_over);	
			//printf("jump over @ %d : ",i);
			//printBoard(&newGame);
			ret = playGame(newGame);
		}
		if(ret) {
			//printf("SUCCESS : ");
			printBoard(&game);
			return ret;
		}
	}

	//printf("game : ");
	//printBoard(&game);
	return ret;
}


int main() {

	struct game Game = createGame1(3,3,7);
	printBoard(&Game);
	
	playGame(Game);
	
	printBoard(&Game);
	return 0;
}
