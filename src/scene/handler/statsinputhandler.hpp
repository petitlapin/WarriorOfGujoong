#ifndef STATSINPUTHANDLER_HPP
#define STATSINPUTHANDLER_HPP

#include "inputhandler.hpp"

class StatsScene;

class StatsInputHandler : public InputHandlerAdapter
{
    Q_OBJECT

public:
    StatsInputHandler();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    StatsScene *_scene;

signals:
    void signal_hide_stats();
};

#endif // STATSINPUTHANDLER_HPP
