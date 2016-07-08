/**@file fireball.h
 * @brief This file contains the declarations for the fireball class.
 */

#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**@class fireball
 * @brief The fireball class contains the functionality of the projectiles that
 * are released from the player.  There is a public slot that controls the fireball's
 * movement up the screen.
 */

class fireball: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Constructor
    fireball(QGraphicsItem* parent = 0);
public slots:
    void move();

};

#endif // FIREBALL_H
