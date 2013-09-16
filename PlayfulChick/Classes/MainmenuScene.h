//
//  MainmenuScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-13.
//
//

#ifndef __PlayfulChick__MainmenuScene__
#define __PlayfulChick__MainmenuScene__

#include "cocos2d.h"
USING_NS_CC;

class MainmenuScene : public CCLayer
{
public:
    static CCScene* createScene();
    CREATE_FUNC(MainmenuScene);
    
    virtual bool init();
    
    void clickStartBtn(CCObject* pSender);
    void clickSoundBtn(CCObject* pSender);
    void clickExitBtn(CCObject* pSender);
};

#endif /* defined(__PlayfulChick__MainmenuScene__) */
