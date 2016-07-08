/**@file gameboard.cpp
 * @brief This file contains the definitions of the gameboard class
 */

#include "gameboard.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QBrush>
#include <QImage>

/**Default constructor for the gameboard with certain dimensions and properties
 * @param parent is the parent Widget where the gameboard will be added to
 */
gameboard::gameboard(QWidget *parent) {
    //create a new scene and specify dimensions/image
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    //set the scene to the created scene
    setScene(scene);
    //set properties of the screen (scroll bars off, fixed size)
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,650);

    //create a player object
    main_player = new player();
    //set the starting position and focus on the player
    main_player->setPos(400,550);
    main_player->setFlag(QGraphicsItem::ItemIsFocusable);
    main_player->setFocus();

    //add player to the scene
    scene->addItem(main_player);

    //create a score object and add to the scene
    points = new score();
    scene->addItem(points);

    //create a health object and add to scene
    hp = new health();
    scene->addItem(hp);
    //set the position of the health display and add to scene
    hp->setPos(hp->x(), hp->y()+40);
    scene->addItem(hp);

    //create a new timer to call the spawn() function
    QTimer* timer = new QTimer;
    //after every 1000s, call spawn function
    QObject::connect(timer, SIGNAL(timeout()), main_player, SLOT(spawn()));
    timer->start(1500);


    //show the scene
    show();
}
