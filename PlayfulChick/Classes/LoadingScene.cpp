//
//  LoadingScene.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-24.
//
//

#include "LoadingScene.h"

CCScene* LoadingScene::createScene()
{
    CCScene *scene = CCScene::create();
    
    LoadingScene *layer = LoadingScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool LoadingScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSprite* bg = CCSprite::create("game_loadbg.png");
    bg->setPosition(VisibleRect::center());
    this->addChild(bg);
    
    CCSprite* tip = CCSprite::create("game_loading.png");
    tip->setPosition(VisibleRect::center());
    this->addChild(tip);
    
    CCFiniteTimeAction* action = CCSequence::create(CCDelayTime::create(LOADING_BEGIN_TIME), CCCallFunc::create(this, callfunc_selector(LoadingScene::loadGame)), NULL);
    this->runAction(action);
    
    return true;
}

void LoadingScene::loadGame()
{
    CCScene* gameScene = NULL;
    switch (Tools::m_iNowMode)
    {
        case 0:
            gameScene = JumpScene::createScene();
            break;
        case 1:
            gameScene = PaintScene::createScene();
            break;
        case 2:
            gameScene = FlyScene::createScene();
            break;
        default:
            break;
    }
    CCDirector::sharedDirector()->replaceScene(gameScene);
}