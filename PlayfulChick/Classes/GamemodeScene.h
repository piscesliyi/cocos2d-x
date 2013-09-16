//
//  GamemodeScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#ifndef __PlayfulChick__GamemodeScene__
#define __PlayfulChick__GamemodeScene__

#include "cocos2d.h"
USING_NS_CC;

class GamemodeScene : public CCLayer
{
public:
    static CCScene* createScene();
    CREATE_FUNC(GamemodeScene);
    
    virtual bool init();
    
    void clickBackBtn(CCObject* pSender);
};

#endif /* defined(__PlayfulChick__GamemodeScene__) */
