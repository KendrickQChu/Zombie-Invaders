/**@file gameover.cpp
 * @brief This file contains the definitions for the gameover class.
 */

#include "gameover.h"
#include "gameboard.h"

#include<QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

/**Default constructor for the gameover screen which contains messages and buttons
 * @param parent is the parent widget that the gameover object is being added to
 */
gameover::gameover(QWidget *parent) {
    //set a fixed size for the gameover screen
    setFixedSize(800,600);

    //create widgets: gameover message, play again button, and quit button
    QLabel* gameover_message = new QLabel("<h1>Game Over!</h1>");
    QPushButton* playagain = new QPushButton("Play Again");
    QPushButton* quit = new QPushButton("Quit");

    //widget styling
    gameover_message->setAlignment(Qt::AlignCenter);

    playagain->setStyleSheet("text-align: center");
    playagain->setFixedHeight(100);

    quit->setStyleSheet("text-align: center");
    quit->setFixedHeight(100);

    //make layouts for the widgets and add them in
    QVBoxLayout* gameover_layout = new QVBoxLayout;
    QHBoxLayout* button_layout = new QHBoxLayout;
    gameover_layout->addWidget(gameover_message);
    gameover_layout->addLayout(button_layout);
    button_layout->addWidget(playagain);
    button_layout->addWidget(quit);

    //set the layout as central layout
    setLayout(gameover_layout);

    //connect the pushbuttons to slots, play again button should let you play again
    //quit should exit the program
    connect(playagain,SIGNAL(clicked()),this,SLOT(play_again()));
    connect(quit,SIGNAL(clicked()),this,SLOT(quit()));

    //show the gameover window
    show();
}

/**Lets the player play the game again
 */
void gameover::play_again() {
    //makes a new game
    game = new gameboard;

    //close the window
    close();
}

/**Quit the program
 */
void gameover::quit() {
    //close the window
    close();
}
