/**@file score.h
 * @brief This file contains the declarations for the score class.
 */

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/**@class score
 * @brief The score class contains implementation for the player's score and how
 * the score is modified.
 */
class score: public QGraphicsTextItem {
public:
    //Constructor
    score(QGraphicsItem* parent = 0);

    void increase();
    int get_score();
private:
    int points;
};

#endif // SCORE_H
