/**@file fireball.cpp
 * @brief This file contains the definitions of the fireball class.
 */

#include "fireball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "gameboard.h"

/**Default constructor that sets the image of the fireball and the timer to move the
 * fireball
 * @param parent is the parent graphicsitem where the fireball will be displayed
 */
fireball::fireball(QGraphicsItem* parent) {
    //set the image of the fireball
    QPixmap projectile(":/images/fireball.png");
    QPixmap scaled_projectile = projectile.scaled(QSize(30,30), Qt::KeepAspectRatio);
    setPixmap(scaled_projectile);

    //create a timer to move the fireball
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //slot move() called every 30ms
    timer->start(30);
}

/**Moves the fireball up the screen and checks for collisions
 */
void fireball::move() {
    //create a collidingItems object that contains a list of objects that have collided with this item (fireball)
    QList<QGraphicsItem*> colliding_items = collidingItems();

    //Cycle through each thing in the list of colliding items
    for(size_t i=0, n=colliding_items.size(); i<n; ++i) {
        //if the type of the colliding item is an enemy
        if (typeid(*(colliding_items[i])) == typeid(enemy)) {
            //increase the score
            game->points->increase();

            //remove and delete both the fireball and enemy that have collided
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
    }

    //set new position of fireball to be 10px greater in y-direction
    setPos(x(), y()-10);
    //if position of fireball is off the screen
    if (pos().y() < 0) {
        //remove and delete the fireball
        scene()->removeItem(this);
        delete this;
    }
}
