//
//  Tools.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#include "Tools.h"

#include "VisibleRect.h"

bool Tools::m_bSoundOn = true;

CCPoint Tools::getFinalPosition(CCPoint point)
{
    return ccp(point.x, VisibleRect::top().y - point.y);
}