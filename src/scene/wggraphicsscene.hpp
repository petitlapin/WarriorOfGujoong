#ifndef WGGRAPHICSSCENE_HPP
#define WGGRAPHICSSCENE_HPP

#include <QGraphicsScene>

class WGGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    WGGraphicsScene(QObject *parent = 0);
};

#endif // WGGRAPHICSSCENE_HPP
