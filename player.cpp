/**@file player.cpp
 * @brief This file contains the defiinitions of the player class.
 */

#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fireball.h"
#include "enemy.h"

/**Default constructor for the player object
 * @param parent is the grahicsitem the player is being passed to
 */
player::player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    //set the player's image using a pixmap
    QPixmap player_model(":/images/player.png");
    QPixmap scaled_player = player_model.scaled(QSize(70,70),Qt::KeepAspectRatio);
    setPixmap(scaled_player);
}

/**Specifies certain keypresses that trigger different actions from the player
 * @param event is the event the keypressevent is being passed to
 */
void player::keyPressEvent(QKeyEvent *event) {
    //if the player pressed the left arrow key
    if(event->key() ==  Qt::Key_Left) {
        //if player's x position is greater than 0 (not at the far left)
        if(pos().x() > 0)
            //move the player 20 pixels to the left
            setPos(x()-20,y());
    }
    //else if player pressed the right arrow key
    else if(event->key() == Qt::Key_Right) {
        //if player's x position is less than 800 (not at the far right)
        if(pos().x()+80 < 800)
            //move the player 20 pixels to the right
            setPos(x()+20, y());
    }
    //else if player pressed the space bar
    else if(event->key() == Qt::Key_Space) {
        //create a new fireball
        fireball* fire = new fireball();
        //set its position relative to the player
        fire->setPos(x()+40,y());
        //add fireball to the scene
        scene()->addItem(fire);
    }
}

/**Create/spawn more enemies
 */
void player::spawn() {
    //create new enemy
    enemy* enemies = new enemy;
    //add the enemy to the scene
    scene()->addItem(enemies);
}
