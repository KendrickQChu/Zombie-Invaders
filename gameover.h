/**@file gameover.h
 * @brief This file contains the declaractions for the gameover class.
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H


#include <QWidget>

/**@class gameover
 * @brief This class is the display screen after the game is finished, basically
 * when the game is over.  From this screen, different options can be clicked,
 * such as quit.
 */
class gameover;
//Global gameover variable
extern gameover* gameover_screen;

class gameover: public QWidget {
    Q_OBJECT
public:
    //Constructor
    gameover(QWidget* parent = 0);
public slots:
    void play_again();
    void quit();
};

#endif // GAMEOVER_H
