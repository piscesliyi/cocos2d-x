//
//  GamemodeScene.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-16.
//
//

#include "GamemodeScene.h"

#include "VisibleRect.h"
#include "Constant.h"
#include "Tools.h"
#include "MainmenuScene.h"

CCScene* GamemodeScene::createScene()
{
    CCScene *scene = CCScene::create();
    
    GamemodeScene *layer = GamemodeScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GamemodeScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    Tools::m_bSoundOn = CCUserDefault::sharedUserDefault()->getBoolForKey(DATA_NAME_SOUNDON, true);
    
    //background
    CCSprite* background = CCSprite::create("game_loadbg.png");
    background->setPosition(VisibleRect::center());
    this->addChild(background);
    
    //mode
    CCSprite* modeBg = CCSprite::create("mode_bg.png");
    modeBg->setAnchorPoint(ccp(0.5, 1));
    modeBg->setPosition(Tools::getFinalPosition(ccp(VisibleRect::center().x, POS_MODEBG_Y)));
    this->addChild(modeBg);
    
    //mode stars
    for (int i = 0; i < 3; i++)
    {
        char keyName[64];
        sprintf(keyName, "%s_%i", DATA_NAME_MODESCORE, i);
        Tools::m_iModeScores[i] = CCUserDefault::sharedUserDefault()->getIntegerForKey(keyName, 0);
        int num = Tools::m_iModeScores[i] / STAR_LEVEL;
        num = (num > STAR_MAX) ? STAR_MAX : num;
        for (int j = 0; j < num; j++)
        {
//            m_pGraphics.drawImage(m_imgModeStar, 111+41*j+268*i, 301);
        }
    }
    
    //back button
    CCSize imageSize = CCSprite::create("btn_return.png")->getContentSize();
    CCRect normalRect = CCRectMake(0, 0, imageSize.width/2, imageSize.height);
    CCRect selectedRect = CCRectMake(imageSize.width/2, 0, imageSize.width/2, imageSize.height);
    CCSprite* backBtnNormal = CCSprite::create("btn_return.png", normalRect);
    CCSprite* backBtnSelected = CCSprite::create("btn_return.png", selectedRect);
    CCMenuItemSprite* backBtn = CCMenuItemSprite::create(backBtnNormal, backBtnSelected, this, menu_selector(GamemodeScene::clickBackBtn));
    backBtn->setAnchorPoint(ccp(0, 1));
    backBtn->setPosition(Tools::getFinalPosition(ccp(POS_BACKBTN_X, POS_BACKBTN_Y)));
    
    //all button in menu
    CCMenu* Menu = CCMenu::create(backBtn, NULL);
    Menu->setPosition(VisibleRect::leftBottom());
    this->addChild(Menu);
    
    return true;
}

void GamemodeScene::clickBackBtn(CCObject* pSender)
{
    CCScene* mainmenuScene = MainmenuScene::createScene();
    CCTransitionScene *trans = CCTransitionFade::create(1, mainmenuScene);
    CCDirector::sharedDirector()->replaceScene(trans);
}