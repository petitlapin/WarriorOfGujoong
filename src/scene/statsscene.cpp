#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QGraphicsGridLayout>
#include <QKeyEvent>
/* -- */
#include "core/Perso.hpp"
#include "core/player.hpp"
/* -- */
#include "handler/statsinputhandler.hpp"
/* -- */
#include "statsscene.hpp"

StatsScene::StatsScene(StatsInputHandler *input_handler, QObject *parent) : WGGraphicsScene(parent)
{
    set_input_handler(input_handler);

    connect(input_handler, SIGNAL(signal_hide_stats()), this, SIGNAL(signal_hide_stats()));

    setBackgroundBrush(QBrush(Qt::white));
}

void StatsScene::set_players(QList<Player *> &players)
{
    _players = players;
}

void StatsScene::refresh_stats()
{
    clear();
    _layouts.clear();

    qDebug("Refresh stats");
    foreach(Player *player, _players) {
        _layouts.push_back(createPlayerLayout(player));
    }
    int i = 0;
    foreach(QGraphicsGridLayout *layout, _layouts) {
        QGraphicsWidget *form = new QGraphicsWidget;
        form->setLayout(layout);
        addItem(form);
        form->setPos(i, 0);
        i += 200;
    }
}

QGraphicsGridLayout *StatsScene::createPlayerLayout(Player *player)
{
    QGraphicsGridLayout *layout = new QGraphicsGridLayout();

    int counter = 0;

    // Display the id/name first
    QGraphicsProxyWidget *proxyLabel = new QGraphicsProxyWidget();
    QLabel *label = new QLabel();
    label->setText(QString("Player %1").arg(player->get_id()));

    proxyLabel->setWidget(label);
    layout->addItem(proxyLabel, counter ++, 0);

    // Display the money
    proxyLabel = new QGraphicsProxyWidget();
    label = new QLabel();
    label->setText(QString("$%1").arg(player->get_money()));

    proxyLabel->setWidget(label);
    layout->addItem(proxyLabel, counter ++, 0);

    foreach(Perso *perso, player->get_persos()) {
        proxyLabel = new QGraphicsProxyWidget();

        label = new QLabel();
        QString experience;
        experience.fill('*', perso->get_XP());
        label->setText(QString::fromStdString(perso->get_name()) + QString(" lvl %1 HP : %2 / %3 %4").arg(perso->get_level()).
                       arg(perso->get_HP()).arg(perso->get_max_HP()).arg(experience));

        proxyLabel->setWidget(label);
        layout->addItem(proxyLabel, counter ++, 0);
    }

    return layout;
}
