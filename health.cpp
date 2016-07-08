/**@file health.cpp
 * @brief This file contains the definitions for the health class.
 */

#include "health.h"
#include <QFont>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include "gameboard.h"
#include "mainscreen.h"
#include "gameover.h"

/**Default constructor for the health object
 * @param parent is the parent QGraphicsItem health is being added to
 */
health::health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //set starting health = 5
    hp = 5;
    //display the health onto the screen
    setPlainText(QString("Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20));
}

/**Decrease the health by one when function is called
 */
void health::decrease(){
    //decrease health by 1 and set the text to mirror this
    --hp;
    setPlainText(QString("Health: ") + QString::number(hp));

    //if health reaches 0, game over
    if(hp == 0) {
        game_over();
    }
}

/**Getter function to get the health of the player
 * @returns the int value of the player's health
 */
int health::get_health() {
    return hp;
}

/**Closes the game screen and creates a gameover screen
 */
void health::game_over() {
    //close the gameboard
    game->close();

    //make a gameover screen
    gameover_screen = new gameover;

}

