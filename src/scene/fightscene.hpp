    #ifndef FIGHTSCENE_HPP
#define FIGHTSCENE_HPP

#include <QTimer>

#include "scene/wggraphicsscene.hpp"

class Perso;
class QGraphicsPixmapItem;
class QGraphicsTextItem;

class FightInputHandler;

class CursorActionItem;

enum FightActionEnum
{
    ATTACK = 0,
    MAGIC,
    RUN
};

class FightScene : public WGGraphicsScene
{
    Q_OBJECT

private:
    CursorActionItem *_cursor_icon;

    QGraphicsPixmapItem *_attacker_perso_icon;
    QGraphicsPixmapItem *_opponent_perso_icon;
    QGraphicsTextItem *_attack_label;
    QGraphicsTextItem *_magic_label;
    QGraphicsTextItem *_run_label;

    QGraphicsTextItem *_attacker_HP_label;
    QGraphicsTextItem *_opponent_HP_label;

    QGraphicsTextItem *_attacker_MP_label;
    QGraphicsTextItem *_opponent_MP_label;

    Perso *_attacker;
    Perso *_opponent;

    bool _occuring_action; // If we have already chosen an action, we disable the key event manager

    QTimer _end_action_timer; // Timer to emit signal_end_fight

    void update_HP_and_MP();

    void create_possible_actions();

public:
    explicit FightScene(QObject *parent = 0);
    
    void do_attack();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void signal_end_fight();

public slots:
    void begin_fight(Perso *yours, Perso *opponent);
};

#endif // FIGHTSCENE_HPP
