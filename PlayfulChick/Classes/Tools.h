//
//  Tools.h
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#ifndef __PlayfulChick__Tools__
#define __PlayfulChick__Tools__

#include "Define.h"

class Tools
{
public:
    static bool m_bSoundOn;
    static int m_iModeScores[3];
    static int m_iNowMode;
    
public:
    static CCPoint getFinalPosition(CCPoint point);
};

#endif /* defined(__PlayfulChick__Tools__) */
