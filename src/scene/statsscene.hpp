#ifndef STATSSCENE_HPP
#define STATSSCENE_HPP

#include <QList>
#include "scene/wggraphicsscene.hpp"

class QKeyEvent;
class QGraphicsGridLayout;
class Player;
class StatsInputHandler;

class StatsScene : public WGGraphicsScene
{
    Q_OBJECT
private:
    QList<Player *> _players;
    QList <QGraphicsGridLayout *> _layouts;

    QGraphicsGridLayout *createPlayerLayout(Player *player);

public:
    StatsScene(StatsInputHandler *input_handler, QObject *parent = 0);
    void set_players(QList<Player *> &players);

public slots:
    void refresh_stats();

signals:
    void signal_hide_stats();
};

#endif // STATSSCENE_HPP
