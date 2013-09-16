//
//  Tools.h
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#ifndef __PlayfulChick__Tools__
#define __PlayfulChick__Tools__

#include "cocos2d.h"
USING_NS_CC;

class Tools
{
public:
    static bool m_bSoundOn;
    
public:
    static CCPoint getFinalPosition(CCPoint point);
};

#endif /* defined(__PlayfulChick__Tools__) */
