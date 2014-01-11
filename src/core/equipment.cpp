#include "equipment.hpp"

Equipment::Equipment() : _money(0)
{
}
int Equipment::get_money() const
{
    return _money;
}

void Equipment::add_money(int money)
{
    _money += money;
}

void Equipment::remove_money(int money)
{
    _money += money;
}

