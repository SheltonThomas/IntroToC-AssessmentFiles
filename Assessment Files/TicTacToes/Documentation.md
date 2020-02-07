|Shelton Thomas|
|----|
|s198053|
|Math For Games|
|Asteroid Survival Game|

## I. Requirements

1. Description of Problem
    - **Name**: TicTacToe

    - **Problem Statement**: Make a console-based tic-tac-toe game.

    - **Problem Specifications**: Make a two player game on a 3x3 board where one player uses 'x'  tokens and one player uses 'o' tokens.

2. Input Information:
    - Use the numberpad as the board(so 7 would be the top left of the board).

## II. Design

1. Program Flow:

    - The two users take turns placing 'x' and 'o' tokens until one of them get a tic-tac-toe.

2. Object Information:

    **File**: TicTacToe.cpp

    Description: Used for the tic-tac-toe game.

    **Attributes**:

        Name: TTTBoard
            Description: Used for the tic-tac-toe board.
            Type: char[][]

        Name: playerTurn
            Description: Used to keep track of which players turn it is.
            Type: int

        Name: gameOver
            Description Used to say if the game is over.
            Type: bool

        Name: failedMove
            Description: Used to say if the player successfully placed one fo their tokens.
            Type: bool

        Name: fullBoard
            Description: Used to say if the board is full of tokens.
            Type: bool

        Name: ticTacToe
            Description:Used to say if a player has a tic-tac-toe.
            Type: bool
