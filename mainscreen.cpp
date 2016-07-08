/**@file mainscreen.cpp
 * @brief This file contains the definitions of the mainscreen class.
 */

#include "mainscreen.h"
#include "gameboard.h"

#include<QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

/**Default constructor that creates a mainscreen with instructions and play button
 * @param parent is the parent widget the mainscreen is being passed to
 */
mainscreen::mainscreen(QWidget *parent) {
    //Make widgets that will be on the main window
    QLabel* title = new QLabel("<h1>Zombie Invaders</h1>");
    QPushButton* play = new QPushButton("Play");
    QLabel* how_to = new QLabel;
    QString instructions(QString("-Move the character using the left and right arrow keys<br>") +
                         QString("-Press the spacebar to fire a projectile at the enemies<br>") +
                         QString("-If the enemies get past you (bottom of the screen), you lose health points<br>") +
                         QString("-If your health points hit 0, you lose<br>"));

    //style the widgets on the main window
    title->setAlignment(Qt::AlignCenter);
    play->setStyleSheet("text-align: center");
    play->setFixedHeight(100);

    how_to->setText(instructions);
    how_to->setAlignment(Qt::AlignHCenter);

    //make vertical layout
    QVBoxLayout* layout = new QVBoxLayout;

    //add widgets to layout
    layout->addWidget(title);
    layout->addWidget(how_to);
    layout->addWidget(play);

    //set the vertical layout to the central widget's layout
    setLayout(layout);

    //connect pushbuttons to either game start or instructions screen
    connect(play, SIGNAL(clicked()), this, SLOT(game_play()));

}

/**Creates a gameboard and closes the main screen
 */
void mainscreen::game_play() {
    //makes a new gameboard
   game = new gameboard;

    //closes the main screen
    close();


}



