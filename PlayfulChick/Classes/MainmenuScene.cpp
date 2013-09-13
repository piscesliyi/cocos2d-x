//
//  MainmenuScene.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-13.
//
//

#include "MainmenuScene.h"
#include "VisibleRect.h"

USING_NS_CC;

CCScene* MainmenuScene::createScene()
{
    CCScene *scene = CCScene::create();
    
    MainmenuScene *layer = MainmenuScene::create();
    
    scene->addChild(layer);

    return scene;
}

bool MainmenuScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSprite* menuBg = CCSprite::create("menu_bg.png");
    menuBg->setPosition(VisibleRect::center());
    this->addChild(menuBg);
    
    return true;
}