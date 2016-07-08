/**@file mainscreen.h
 * @brief This file contains the declaractions for the mainscreen class.
 */

#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>

/**@class mainscreen
 * @brief The mainscreen class contains the screen that the player first sees when
 * the application is run.  The screen also contains information about the game and
 * a way to start the game.
 */
class mainscreen: public QWidget {
    Q_OBJECT
public:
    //Constructor
    mainscreen(QWidget* parent=0);
public slots:
   void game_play();
};

#endif // MAINSCREEN_H
