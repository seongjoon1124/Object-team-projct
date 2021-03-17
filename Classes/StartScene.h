#ifndef _START_SCENE_H__
#define _START_SCENE_H__

#include "stdafx.h"

class StartScene : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();

    // ��ġ �Ǿ����� ( ���콺 ��������)
    virtual bool onTouchBegan(Touch* touch, Event* unused_event);

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif //_START_SCENE_H__
