#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class Equipment
{
public:
    Equipment();

    int get_money() const;
    void add_money(int get_money);
    void remove_money(int get_money);

protected:
    int _money;
    //QMap <Item *, int> _items; //!< Items followed by its quantity
};

#endif // EQUIPMENT_H
