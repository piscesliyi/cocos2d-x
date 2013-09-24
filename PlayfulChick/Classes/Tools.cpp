//
//  Tools.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#include "Tools.h"

bool Tools::m_bSoundOn = true;
int Tools::m_iModeScores[3] = {0};
int Tools::m_iNowMode = 0;

CCPoint Tools::getFinalPosition(CCPoint point)
{
    return ccp(VisibleRect::left().x + point.x, VisibleRect::top().y - point.y);
}