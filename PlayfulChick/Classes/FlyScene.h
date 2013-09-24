//
//  FlyScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-24.
//
//

#ifndef __PlayfulChick__FlyScene__
#define __PlayfulChick__FlyScene__

#include "Define.h"

class FlyScene : public CCScene
{
public:
    static CCScene* createScene();
    CREATE_FUNC(FlyScene);
    
    virtual bool init();
};

#endif /* defined(__PlayfulChick__FlyScene__) */
