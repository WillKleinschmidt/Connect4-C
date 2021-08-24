#include <stdio.h>
#include <stdlib.h>

/* Method skeleton to avoid declaration error */
void computerMove(char game[7][8], char moves[41], char cType, char hType, int round);
/* 
* Prints the current state of the board. 
* @param gameboard arr.
*/
void printBoard(char game[7][8]){
  printf("Connect 4 game\n");
  printf("---------------\n");
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 8; j++){
      printf("%c ", game[i][j]);
    }
  printf("\n");
  }
printf("---------------\n");
}
/*
* Prints the order of moves when game ends.
* @param moves arr, round#.
*/
void printMoves(char moves[41], int round){
  printf("Moves [");
  for(int i = 0; i <= round; i++){
    if(i < round){
      printf("%c, ", moves[i]);
    }
    else{
      printf("%c]\n", moves[round]);
    }
  }
}
/*
* Converts a char input to an int value.
* ex. 'B' to 2, 'C' to 3...
* @param char version of move.
* @return int version of move.
*/
int charToInt(char move){
  char converter[8] = {" ABCDEFG"};
  for(int i = 1; i < 8; i++){
    if(converter[i] == move){
      return i;
    }
  }
  return -1;
}
/*
* Converts int input to a char.
* ex. 4 to 'D', 5 to 'E'...
* @param int version of move.
* @return char version of move.
*/
char intToChar(int move){
  char converter[8] = {" ABCDEFG"};
  return converter[move];
}
/*
* Adds a move to the move arr.
* @param moves arr, char move, round#
*/
void addToMoves(char moves[41], char move, int round){
  moves[round] = move;
}
/*
* Checks current column to see if a play can
* be made in that column.
* @param gameboard arr, move.
* @return -1 if move is out of bounds.
*         -1 if move is in a full column.
*          0 if move is valid.
*/
int isValidMove(char game[7][8], int m){
  if((m < 1) || (m > 7)){
    return -1;
  }
  else if(game[1][m] == 'X' || game[1][m] == 'O'){
    return -1;
  }
  else{
    return 0;
  }
}
/* Updates the gameboard by adding an 'X' or 'O'
* in the input column and returns where that piece
* was added.
* @param gameboard arr, xpos of move, 'X' or 'O'.
* @return ypos of piece that was played.
*/
int updateGame(char game[7][8], int x, char type){
  int i;
  for(i = 1; i < 6; i++){
    if((game[i + 1][x] == 'X' 
    || game[i + 1][x] == 'O')){
      break;
    }
  }
  game[i][x] = type;
  return i;
}
/* Checks for a horioztal win at given location.
* ex.  | . . X X X X O  | is a win.
* @param gameboard arr, xpos, ypos, 'X' or 'O'.
* @return 1 if win, 0 else.
*/
int checkHor(char game[7][8], int x, int y, char type){
  int count = 0;
  for(int i = 1; i < 8; i++){
    if((game[y][i] == type) && count != 4){
      count++;
    }
    else if(count == 4){
      break;
    } else{
      count = 0;
    }
  }
  if(count == 4){
    return 1;
  } else{
    return 0;
  }
}
/* Checks for a vertical win at given location.
* ex.  .   is a win.
*      X
*      X
*      X
*      X
*      O 
* @param gameboard arr, xpos, ypos, 'X' or 'O'.
* @return 1 if win, 0 else.
*/
int checkVert(char game[7][8], int x, int y, char type){
  int count = 0;
  for(int i = 1; i < 7; i++){
    if((game[i][x] == type) && count != 4){
      count++;
    }
    else if(count == 4){
      break;
    } else{
      count = 0;
    }
  }
  if(count == 4){
    return 1;
  } else{
    return 0;
  }
}
/* Checks for a right diagonal win at given 
* location.
* ex.       .   is a win.
*          X
*         X
*        X
*       X
*      O 
* @param gameboard arr, xpos, ypos, 'X' or 'O'.
* @return 1 if win, 0 else.
*/
int checkDiagR(char game[7][8], int x, int y, char type){
  int count = 0;
  int diag = x + y;
  int startX, startY; 
  int endX;
  if(diag == 5){
    startX = 1;
    startY = 4;
    endX = 4;
  }
  else if(diag == 6){
    startX = 1;
    startY = 5;
    endX = 5;
  }
  else if(diag == 7){
    startX = 1;
    startY = 6;
    endX = 6;
  }
  else if(diag == 8){
    startX = 2;
    startY = 6;
    endX = 7;
  }
  else if(diag == 9){
    startX = 3;
    startY = 6;
    endX = 7;
  }
  else if(diag == 10){
    startX = 4;
    startY = 6;
    endX = 7;
  } else{
    // printf("diagR ERROR\n");
  }
  for(int i = startX; i <= endX; i++){
    if((game[startY][i] == type) && count != 4){
      count++;
      startY--;
    }
    else if(count == 4){
      break;
    } else{
      count = 0;
      startY--;
    }
  }
  if(count == 4){
    return 1;
  } else{
    return 0;
  }
}
/* Checks for a left diagonal win at given 
* location.
* ex. .   is a win.
*      X
*       X
*        X
*         X
*          O 
* @param gameboard arr, xpos, ypos, 'X' or 'O'.
* @return 1 if win, 0 else.
*/
int checkDiagL(char game[7][8], int x, int y, char type){
  int count = 0;
  int diag = x - y;
  int startX, startY; 
  int endX;
  if(diag == -2){
    startX = 1;
    startY = 3;
    endX = 4;
  }
  else if(diag == -1){
    startX = 1;
    startY = 2;
    endX = 5;
  }
  else if(diag == 0){
    startX = 1;
    startY = 1;
    endX = 6;
  }
  else if(diag == 1){
    startX = 2;
    startY = 1;
    endX = 7;
  }
  else if(diag == 2){
    startX = 3;
    startY = 1;
    endX = 7;
  }
  else if(diag == 3){
    startX = 4;
    startY = 1;
    endX = 7;
  } else{
    // printf("diagL ERROR\n");
  }
  for(int i = startX; i <= endX; i++){
    if((game[startY][i] == type) && count != 4){
      count++;
      startY++;
    }
    else if(count == 4){
      break;
    } else{
      count = 0;
      startY++;
    }
  }
  if(count == 4){
    return 1;
  } else{
    return 0;
  }
}
/* Checks hor, vert, diagr, diagl at position
* for a win.
* @param gameboard arr, xpos, ypos, 'X' or 'O'.
* @return >1 if win, 0 else.
*/
int isWin(char game[7][8], int x, int y, char type){
  int win3 = 0; int win4 = 0;
  int win1 = checkHor(game, x, y, type);
  int win2 = checkVert(game, x, y, type);
  if((x + y) > 4 || (x + y) < 11){
    win3 = checkDiagR(game, x, y, type);
  }
  if((x - y) > -3 || (x - y) < 4){
    win4 = checkDiagL(game, x, y, type);
  }
  return(win1 + win2 + win3 + win4);
}
/* Prints who won or if there was a draw, calls
* method to print moves list, then exits program.
* @param type (human, computer, or draw), moves 
* list, round#.
*/
void endGame(char type, char moves[41], int round){
  if(type == 'h'){
    printf("Human Wins!\n");
  }
  else if(type == 'c'){
    printf("Computer Wins!\n");
  }
  else{
    printf("Draw\n");
  }
  printMoves(moves, round);
  exit(0);
}
/* This method first checks for a draw, then 
* prompts user to enter a move. Method checks if 
* this move is valid then updates the game. Method 
* checks for a win, then calls the computer move 
* method. If user enters unexpected input, returns 
* to top of method.
* @param gameboard arr, moves arr, player piece 
* type, computer piece type, round#.
*/
void humanMove(char game[7][8], char moves[41], char cType, char hType, int round){
    if(round == 41){
    endGame('d', moves, round);
  }
  round++;
  printf("Human Move | Round # %i\n", round);
  char move;
  printf("Choose 'A', 'B', 'C', 'D', 'E', 'F', or 'G' to make a move\n");
  scanf("%s", &move);
  int pos = charToInt(move);
  if(isValidMove(game, pos) == -1){
    printf("Invalid move, please try again\n");
    round--;
    humanMove(game, moves, cType, hType, round);
  }
  printf("Nice move!\n");
  addToMoves(moves, move, round);
  int yPosition = updateGame(game, pos, hType);
  printBoard(game);
  if(isWin(game, pos, yPosition, hType) > 0){
    endGame('h', moves, round);
  } else {
    computerMove(game, moves, cType, hType, round);
  }
}
/* Removes peice from pos on gameboard.
* @param gameboard arr, xpos, ypos.
*/
void remover(char game[7][8], int x, int y){
  game[y][x] = '.';
}
/* Reverese piece type from pos on gamebaord.
* ex. 'X' becomes 'O' at pos.
* @param gameboard arr, xpos, ypos, computer piece 
* type, player peice type.
*/
void reverse(char game[7][8], int x, int y, char cType, char hType){
  game[y][x] = cType;
  printBoard(game);
  printf("Nice try\n");
}
/* Counts number of pieces in column.
* @param gameboard arr, xpos of column.
* @return # of pieces in column
*/
int countCol(char game[7][8], int x){
  int count = 0;
  for(int i = 1; i < 7; i++){
    if(game[i][x] != '.'){
      count++;
    }
  }
  if(count == 6){
    return 0;
  }
  return count;
}
/* Returns xpos of column with most pieces.
* If a column has 6, return 0.
* @param gameboard arr.
* @return xpos of column with most pieces.
*/
int maxCount(char game[7][8]){
  int x = 1;
  int curr = 0;
  int max = countCol(game, 1);
  for(int i = 1; i < 8; i++){
    curr = countCol(game, i);
    if(curr > max){
      max = curr;
      x = i;
    }
  }
  return x;
}
/* Dumb version of A.I. that could be swapped out
* with a smarter version in the future. A.I. first
* attempts to win, then to block. If it can't do
* either, it playes in comlun D (the best start 
* move). If column D is full, it plays in the 
* column with the most pieces.
@param gameboard arr, moves arr, player piece 
* type, computer piece type, round#.
*/
void modularAI_Dumb(char game[7][8], char moves[41], char cType, char hType, int round){
  int i = 1;
  while((i < 8)){
    if(isValidMove(game, i) == 0){
      int y = updateGame(game, i, cType);
      if(isWin(game, i, y, cType) > 0){
        printBoard(game);
        char move = intToChar(i);
        addToMoves(moves, move, round);
        endGame('c', moves, round);
      } else{
        remover(game, i, y);
        i++;
      }
    } else{
      i++;
    }
  }
  int j = 1;
  while((j < 8)){
    if((isValidMove(game, j) == 0)){
      int y = updateGame(game, j, hType);
      if(isWin(game, j, y, hType) > 0){
        reverse(game, j, y, cType, hType);
        char move = intToChar(j);
        addToMoves(moves, move, round);
        humanMove(game, moves, cType, hType, round);
      } else{
        remover(game, j, y);
        j++;
      }
    } else{
      j++;
    }
  }
  if(isValidMove(game, 4) == 0){
    updateGame(game, 4, cType);
    addToMoves(moves, 'D', round);
    printBoard(game);
  }
  else{
    int max = maxCount(game);
    updateGame(game, max, cType);
    char move = intToChar(max);
    addToMoves(moves, move, round);
    printBoard(game);
  }
}
/* First checks for a draw, then increments round.
* After, calls modular A.I. and then calls player 
* move.
* @param gameboard arr, moves arr, player piece 
* type, computer piece type, round#.
*/
void computerMove(char game[7][8], char moves[41], char cType, char hType, int round){
  if(round == 41){
    endGame('d', moves, round);
  }
  round++;
  printf("Computer Move | Round # %i\n", round);
  modularAI_Dumb(game, moves, cType, hType, round);
  humanMove(game, moves, cType, hType, round);
}
/* Main method. Instantiates gameboard, moves arr,
* and prints start position of the board. Next, 
* promts player to go first or second and returns 
* to the top if player inputs wrong data.
*/
int main(void) {
  char game[7][8] =  {
    " ABCDEFG",
    "6.......",
    "5.......",
    "4.......",
    "3.......",
    "2.......",
    "1.......",
  };
  char moves[41];
  char firstSecond = ' ';
  printf("\nWelcome to Connect Four\n\n");
  printBoard(game);
  printf("Type '1' to go first or '2' to go second\n\n");
  scanf("%c", &firstSecond);
  if(firstSecond == '1'){
    printf("Human goes first\n");
    humanMove(game, moves, 'O', 'X', -1);
  }
  else if(firstSecond == '2'){
    printf("Computer goes first\n");
    computerMove(game, moves, 'X', 'O', -1);
  }else{
    printf("Invalid Input\n");
    main();
  }
  return 0;
}