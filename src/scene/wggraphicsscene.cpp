#include "handler/inputhandler.hpp"
/* -- */
#include "wggraphicsscene.hpp"

WGGraphicsScene::WGGraphicsScene(QObject *parent) : QGraphicsScene(parent), _input_handler(NULL)
{
}

WGGraphicsScene::~WGGraphicsScene()
{
    set_input_handler(NULL);
}

void WGGraphicsScene::set_input_handler(InputHandler *handler)
{
    delete _input_handler;
    _input_handler = handler;
}

void WGGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(_input_handler)
        _input_handler->mouseMoveEvent(event);
}

void WGGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(_input_handler)
        _input_handler->mousePressEvent(event);
}

void WGGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if(_input_handler)
        _input_handler->keyPressEvent(event);
}
