#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <QObject>

class QKeyEvent;
class QGraphicsSceneMouseEvent;

/**
 * @brief The InputHandler class
 * Class which handle the mouse and keyboard for a depending scene.
 */
class InputHandler : public QObject
{
    Q_OBJECT
public:
    InputHandler();

    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
};

/**
 * @brief The InputHandlerAdapter class
 * Adapter for InputHandler interface
 */
class InputHandlerAdapter : public InputHandler {
    virtual void keyPressEvent(QKeyEvent *) {}
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *) {}
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *) {}
};

#endif // INPUTHANDLER_HPP
