//
//  JumpScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-24.
//
//

#ifndef __PlayfulChick__JumpScene__
#define __PlayfulChick__JumpScene__

#include "Define.h"

class JumpScene : public CCScene
{
public:
    static CCScene* createScene();
    CREATE_FUNC(JumpScene);
    
    virtual bool init();
};

#endif /* defined(__PlayfulChick__JumpScene__) */
