/**@file health.h
 * @brief This file contains the declarations for the health class.
 */

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

/**@class health
 * @brief The health class controls how the player's health decreases and will call
 * game over when the health reaches 0.
 */
class health: public QGraphicsTextItem {
public:
    //Constructor
    health(QGraphicsItem* parent = 0);

    void decrease();
    int get_health();
    void game_over();
private:
    int hp;
};

#endif // HEALTH_H
