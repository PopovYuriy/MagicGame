
#ifndef MYGAME_FIELDINPUTCONTROLLER_H
#define MYGAME_FIELDINPUTCONTROLLER_H

#include "cocos2d.h"


class FieldInputController {
public:
    static const short DIRECTION_RIGHT = 0;
    static const short DIRECTION_LEFT = 1;
    static const short DIRECTION_UP = 2;
    static const short DIRECTION_DOWN = 3;

};

class FieldMouseInputController : public cocos2d::Node
{
public:
    FieldMouseInputController();
    ~FieldMouseInputController();
    void onMouseDown(cocos2d::Event *event);
    void onMouseMove(cocos2d::Event *event);
    void onMouseUp(cocos2d::Event *event);

private:
    cocos2d::EventListenerMouse* _listener;
    cocos2d::EventDispatcher* _dispatcher;
    cocos2d::Vec2 _startPoint;
    cocos2d::Vec2 _finishPoint;
};


#endif //MYGAME_FIELDINPUTCONTROLLER_H
