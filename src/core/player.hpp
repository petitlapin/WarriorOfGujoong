#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QVariant>
#include <QList>

class Perso;
class PersoEquipment;
class Equipment;

class Player : public QObject, public QVariant
{
    Q_OBJECT
public:
    explicit Player(int id);
    ~Player();

    void add_persos(const QList<Perso *> &persos);

    QList<Perso *> &get_persos();

    int get_id();

    int get_money() const;
    void add_money(int get_money);
    void remove_money(int get_money);

    bool can_buy_item(int price);

protected:
    int _id;
    QList <Perso *> _persos;

    // Contains the money, the weapons, armors unused by persos...
    Equipment *_equipment;


public slots:
    void perso_dead(Perso *perso);

    /**
     * @brief slot_equipment_won
     * @param equipment
     * Slot called by the perso who killed an enemy. Slot dispatch the equipment (gold, xp for the perso, weapons...)
     */
    void slot_equipment_won(PersoEquipment *equipment);

signals:
    void signal_player_has_lost(Player *p);
};

#endif // PLAYER_HPP
