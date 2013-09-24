//
//  PaintScene.h
//  PlayfulChick
//
//  Created by liyi on 13-9-24.
//
//

#ifndef __PlayfulChick__PaintScene__
#define __PlayfulChick__PaintScene__

#include "Define.h"

class PaintScene : public CCScene
{
public:
    static CCScene* createScene();
    CREATE_FUNC(PaintScene);
    
    virtual bool init();
};

#endif /* defined(__PlayfulChick__PaintScene__) */
