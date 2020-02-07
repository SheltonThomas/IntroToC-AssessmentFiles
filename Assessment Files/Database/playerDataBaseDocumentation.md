|Shelton Thomas|
|----|
|s198053|
|Math For Games|
|Asteroid Survival Game|

## I. Requirements

1. Description of Problem
    - **Name**: Player Profile Database

    - **Problem Statement**: Create a program that loads, updates, and saves player profile information to a binary file.

    - **Problem Specifications**: For each player in the database you must store their name and high-score. When your program launches it will read previously saved profiles from a binary file, if such a file exists. If no file exists then one will be created. The user will be able to create new players or search for a profile and update the containing information.

2. Input Information:
    - Use numbers to navigate through menus and use the keyboard to type out names of players and their scores.

## II. Design

1. Program Flow:

    - The user is put into the main menu that allows them to chose to view the players in the database, search for a player in the database, add a player to the database, remove a player from the database, or to modify a player's information.

    - Main menu:

    |
    |:---
    |![Main Menu](https://i.imgur.com/bPzQh5A.png)
    |

    - Viewing players in database:

    ![Database view no players](https://i.imgur.com/COMcpkG.png)

    ![Database view](https://i.imgur.com/aUYz80Y.png)

    - Searching for a player:

        - Program asks the user what the name of the player they are searching for is.

    - Adding a player to the database:

        - Program asks the user the name of the player and the player's score they would like to add to the database.

    - Removing a player from the database:

        - Program asks the user the name of the player that they would like to remove from the database.

    - Modifying a player's information:

        - Program asks the user the name of the player that they want to modify, the user is then able to change the playuer's name and or score.

2. Object Information:

    **File**: Player.h

    Description: Used for the dealing with the player list.

    **Attributes**:

        Name: getName
            Description: Used to get the name of a player.
            Type: char*
            Visibility: public

        Name: setName
            Description: Used to set the name of a player.
            Type: void
            Visibility: public
            Parameters: const char* newName

        Name: getNameLength
            Description: Used to get the length of a player's name.
            Type: int
            Visibility: public

        Name: getScore
            Description: used to get the score of a player.
            Type: int
            Visibility: public

        Name: setScore
            Description: Used to set the score of a plyer.
            Type: void
            Visibility: public

        Name: playerName
            Description: Used to hold a player's name.
            Type: char[]
            Visibility: private

        Name: playerScore
            Description: Used to hold a pplayer's score.
            Type: int
            Visibility: private

    **File**: DataBase.cpp

    Description: Used foor the main body of code.

    **Attributes**:

        Name: sort
            Description: Used to sort player's in alphabetical order.
            Type: void
            Parameters: Player* playerList, int amountOfPlayers

        Name: save
            Description: Used to save player's to the file.
            Type: void
            Parameters: Player* playerList, int amountOfPlayers
