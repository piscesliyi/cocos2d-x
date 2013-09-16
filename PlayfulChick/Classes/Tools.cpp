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
int  Tools::m_iModeScores[3] = {0};

CCPoint Tools::getFinalPosition(CCPoint point)
{
    return ccp(point.x, VisibleRect::top().y - point.y);
}