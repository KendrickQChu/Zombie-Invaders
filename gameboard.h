/**@file gameboard.h
 * @brief This file contains the declarations of the gameboard class.
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"

/**@class gameboard
 * @brief This class is the gameboard itself, and holds its properties, such as
 * the scene, the player, the score, and the player's health.
 */
class gameboard;
//Global gameboard variable
extern gameboard* game;


class gameboard: public QGraphicsView {
public:
    //Constructor
   gameboard(QWidget* parent=0);

   //public attrbutes
   QGraphicsScene* scene;
   player* main_player;
   score* points;
   health* hp;
};

#endif // GAMEBOARD_H
