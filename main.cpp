/** Name: Kendrick Chu
 UCLA ID: 004136504
 Date: 6/06/16
 @File: This application is a simple 2d shooter game that is very similar to space
 invaders.  A main menu is first launched, which shows the player instructions on
 how to play the game and has a button to start playing.  In the game, enemies travel
 down the screen.  The player controls a character at the bottom of the screen and
 tries to destroy all the enemies before they reach the bottom of the screen.  When the
 game is over, the player is shown a game over screen.
 */

#include <QApplication>
#include "gameboard.h"
#include "gameover.h"
#include "mainscreen.h"

//Global variables for the game board and game over screen
gameboard* game;
gameover* gameover_screen;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create the main screen
    mainscreen main;
    //set its size and show the screen
    main.setMinimumSize(800,600);
    main.show();

    return a.exec();
}
