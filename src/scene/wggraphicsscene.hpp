#ifndef WGGRAPHICSSCENE_HPP
#define WGGRAPHICSSCENE_HPP

#include <QGraphicsScene>

class InputHandler;

class WGGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    WGGraphicsScene(QObject *parent = 0);
    virtual ~WGGraphicsScene();

    void set_input_handler(InputHandler *handler);

protected:
    // Methods inherited from the scene
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    InputHandler *_input_handler;
};

#endif // WGGRAPHICSSCENE_HPP
