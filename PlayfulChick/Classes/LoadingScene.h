//
//  LoadingScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-24.
//
//

#ifndef __PlayfulChick__LoadingScene__
#define __PlayfulChick__LoadingScene__

#include "Define.h"

class LoadingScene : public CCLayer
{
private:
    void loadGame();
    
public:
    static CCScene* createScene();
    CREATE_FUNC(LoadingScene);
    
    virtual bool init();
};

#endif /* defined(__PlayfulChick__LoadingScene__) */
