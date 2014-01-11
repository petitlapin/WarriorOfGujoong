
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
/*-- */
#include "scene/statsscene.hpp"
#include "statsinputhandler.hpp"

StatsInputHandler::StatsInputHandler()
{
}

void StatsInputHandler::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Escape:
    case Qt::Key_S:
         emit signal_hide_stats();
    }
}
