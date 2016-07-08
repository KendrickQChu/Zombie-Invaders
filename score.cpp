/**@file score.cpp
 * @brief This file contains the definitions of the score class.
 */

#include "Score.h"
#include <QFont>

/**Default constructor for score that has certain properties
 * @param parent is the graphicsitem that score is being passed to
 */
score::score(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    //initialize the score to be 0
    points = 0;

    //display the score in the scene
    setPlainText(QString("Score: ") + QString::number(points));
    setFont(QFont("times", 20));
}

/**Increase the score
 */
void score::increase(){
    //increase the score by 1
    points++;
    //display the new score to the screen
    setPlainText(QString("Score: ") + QString::number(points));
}

/**Getter to retrieve the score
 * @returns int value of the score
 */
int score::get_score(){
    return points;
}
