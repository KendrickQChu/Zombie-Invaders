/**@file enemy.cpp
 * @brief This file contains the definitions for the enemy class.
 */

#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard.h"

/**Default constructor for the enemy that sets the position of the enemy and image
 * @param parent is the parent graphicsitem where the enemy will be displayed
 */
enemy::enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    //get a random x position for the enemy to spawn at, and set its to that location
    int random_position = rand() % 720;
    setPos(random_position, 0);

    //set the image of the enemy
    QPixmap enemy_model(":/images/enemy.gif");
    QPixmap scaled_enemy = enemy_model.scaled(QSize(80,80), Qt::KeepAspectRatio);
    setPixmap(scaled_enemy);

    //create a timer and set it to move the enemy on timeout
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //slot move() called every 50ms
    timer->start(50);

    //if the player's hp is 0, stop the timer
    if(game->hp == 0) {
        timer->stop();
    }
}

/**Public slot function that moves the enemy's position set on a time interval
 * using the timer.
 */
void enemy::move() {
    //Set the new position of the enemy to 5 pixels down, set on a timer to call the move function
    setPos(x(), y()+5);

    //If the position is greater that 600, which is the bottom of the screen, then should lose a life
    if(pos().y() > 600) {
        //decrease the health
        game->hp->decrease();

        //remove the enemy from the scene and delete it
        scene()->removeItem(this);
        delete this;
    }
}
