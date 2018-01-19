
#include <events/MoveEvent.h>
#include "events/GameEvent.h"
#include "FieldInputController.h"

using namespace cocos2d;

FieldMouseInputController::FieldMouseInputController() {
    CCLOG("FieldMouseInputController :: INIT");
    _dispatcher = Director::getInstance()->getEventDispatcher();

    _listener = EventListenerMouse::create();

    _listener->onMouseMove = CC_CALLBACK_1(FieldMouseInputController::onMouseMove, this);
    _listener->onMouseDown = CC_CALLBACK_1(FieldMouseInputController::onMouseDown, this);
    _listener->onMouseUp = CC_CALLBACK_1(FieldMouseInputController::onMouseUp, this);

    _dispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
    CCLOG("FieldMouseInputController :: END_INIT");
}

FieldMouseInputController::~FieldMouseInputController() {
    _dispatcher->removeEventListener(_listener);
}

void FieldMouseInputController::onMouseDown(Event *event) {
    EventMouse* e = (EventMouse*)event;
    _startPoint = e->getLocation();
    //CCLog("onMouseDown :: %f, %f", _startPoint.x, _startPoint.y);
}

void FieldMouseInputController::onMouseMove(Event *event) {
    EventMouse* e = (EventMouse*)event;
    _finishPoint = e->getLocation();
}

void FieldMouseInputController::onMouseUp(Event *event) {
    float distance = _startPoint.getDistance(_finishPoint);

    if(distance < 20)
        return;

    Vec2 zeroAsix = Vec2(_startPoint.x + 100, _startPoint.y);

    Vec2 a = Vec2(zeroAsix.x - _startPoint.x, zeroAsix.y - _startPoint.y);
    Vec2 b = Vec2(_finishPoint.x - _startPoint.x, _finishPoint.y - _startPoint.y);

    float skalar = a.x * b.x + a.y * b.y;
    float length = sqrtf(powf(a.x, 2) + powf(a.y, 2)) * sqrtf(powf(b.x, 2) + powf(b.y, 2));

    float angle = skalar / length;
    float degree = acos(angle) * 180 / 3.14;

    short direction;

    if(degree >= 135) {
        direction = FieldInputController::DIRECTION_LEFT;
    } else if(degree <= 45) {
        direction = FieldInputController::DIRECTION_RIGHT;
    } else {
        if(_finishPoint.y > _startPoint.y) {
            direction = FieldInputController::DIRECTION_DOWN;
        } else {
            direction = FieldInputController::DIRECTION_UP;
        }
    }

    MoveEvent* moveEvent = new MoveEvent(GameEvent::MOVE);
    moveEvent->setDirection(direction);

    _dispatcher->dispatchEvent(moveEvent);

    //CCLog("onMouseUp :: %f, %f; a = %f, dir = %d", _finishPoint.x, _finishPoint.y, degree, direction);
}
