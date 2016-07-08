/**@file player.h
 * @brief This file contains the declarations for the player class.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

/**@class player
 * @brief The player class contains the implementations for the player character,
 * such as movement.  The spawn() function, which creates new enemies at the top
 * of the screen, is also in the player class.
 */
class player: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Constructor
    player(QGraphicsItem* parent = 0);

    void keyPressEvent (QKeyEvent* event);
public slots:
    void spawn();
};

#endif // PLAYER_H
