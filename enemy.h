/**@file enemy.h
 * @brief This file contains the declarations for the enemy class.
 */

#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

/**@class enemy
 * @brief The enemy class is in charge of creating the enemies that spawn at the
 * top of the screen.  It also has a public slot in charge of moving the enemies
 * down the screen.
 */

class enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Constructor
    enemy(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY_H
