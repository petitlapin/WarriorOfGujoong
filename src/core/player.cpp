#include <QObject>
/* -- */
#include "equipment.hpp"
/* -- */
#include "Perso.hpp"
/* -- */
#include "player.hpp"

Player::Player(int id) : QObject(), _id(id), _persos(QList<Perso *>()), _equipment(new Equipment)
{
}

Player::~Player() {

    delete _equipment;
    foreach(Perso *p, _persos) {
        delete p;
    }
    _persos.clear();
}

void Player::add_persos(const QList<Perso *> &persos)
{
    _persos += persos;
    foreach(Perso *p, persos) {
        connect(p, SIGNAL(signal_perso_is_dead(Perso *)), this, SLOT(perso_dead(Perso *)));
        connect(p, SIGNAL(signal_equipment_won(PersoEquipment*)), this, SLOT(slot_equipment_won(PersoEquipment *)));
    }
}

QList<Perso *> &Player::get_persos()
{
    return _persos;
}

int Player::get_id()
{
    return _id;
}

int Player::get_money() const
{
    return _equipment->get_money();
}

void Player::add_money(int money)
{
    _equipment->add_money(money);
}

void Player::remove_money(int money)
{
   _equipment->remove_money(money);
}

bool Player::can_buy_item(int price) {
    return (_equipment->get_money() - price) >= 0;
}

void Player::perso_dead(Perso *perso)
{
    _persos.removeAll(perso);
    if(_persos.isEmpty()) {
        emit signal_player_has_lost(this);
    }
}

void Player::slot_equipment_won(PersoEquipment *equipment)
{
    Perso *perso = dynamic_cast<Perso *>(sender());
    perso->add_XP(equipment->get_xp());
    add_money(equipment->get_money());
    // TODO Items if there are...
}
