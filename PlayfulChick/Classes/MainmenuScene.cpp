//
//  MainmenuScene.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-13.
//
//

#include "MainmenuScene.h"

#include "Constant.h"
#include "Tools.h"
#include "VisibleRect.h"
#include "SimpleAudioEngine.h"

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
    
    Tools::m_bSoundOn = CCUserDefault::sharedUserDefault()->getBoolForKey(DATA_NAME_SOUNDON, true);
    
    //background
    CCSprite* menuBg = CCSprite::create("menu_bg.png");
    menuBg->setPosition(VisibleRect::center());
    this->addChild(menuBg);
    
    //start button
    CCSize imageSize = CCSprite::create("menu_start.png")->getContentSize();
    CCRect normalRect = CCRectMake(0, 0, imageSize.width/2, imageSize.height);
    CCRect selectedRect = CCRectMake(imageSize.width/2, 0, imageSize.width/2, imageSize.height);
    CCSprite* startBtnNormal = CCSprite::create("menu_start.png", normalRect);
    CCSprite* startBtnSelected = CCSprite::create("menu_start.png", selectedRect);
    CCMenuItemSprite* startBtn = CCMenuItemSprite::create(startBtnNormal, startBtnSelected, this, menu_selector(MainmenuScene::clickStartBtn));
    startBtn->setAnchorPoint(ccp(0, 1));
    startBtn->setPosition(Tools::getFinalPosition(ccp(POS_STARTBTN_X, POS_STARTBTN_Y)));
    
    //sound button
    imageSize = CCSprite::create("menu_sound.png")->getContentSize();
    normalRect = CCRectMake(0, 0, imageSize.width/2, imageSize.height);
    selectedRect = CCRectMake(imageSize.width/2, 0, imageSize.width/2, imageSize.height);
    CCSprite* soundBtnNormal = CCSprite::create("menu_sound.png", normalRect);
    CCSprite* soundBtnSelected = CCSprite::create("menu_sound.png", selectedRect);
    CCMenuItemSprite* itemSoundon = CCMenuItemSprite::create(soundBtnNormal, NULL);
    CCMenuItemSprite* itemSoundoff = CCMenuItemSprite::create(soundBtnSelected, NULL);
    CCMenuItemToggle* soundBtn = CCMenuItemToggle::createWithTarget(this, menu_selector(MainmenuScene::clickSoundBtn), itemSoundon, itemSoundoff, NULL);
    soundBtn->setAnchorPoint(ccp(0, 1));
    soundBtn->setPosition(Tools::getFinalPosition(ccp(POS_SOUNDBTN_X, POS_SOUNDBTN_Y)));
    if (Tools::m_bSoundOn)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
    }
    else
    {
        soundBtn->setSelectedIndex(1);
    }
    
    //exit button
    imageSize = CCSprite::create("menu_exit.png")->getContentSize();
    normalRect = CCRectMake(0, 0, imageSize.width/2, imageSize.height);
    selectedRect = CCRectMake(imageSize.width/2, 0, imageSize.width/2, imageSize.height);
    CCSprite* exitBtnNormal = CCSprite::create("menu_exit.png", normalRect);
    CCSprite* exitBtnSelected = CCSprite::create("menu_exit.png", selectedRect);
    CCMenuItemSprite* exitBtn = CCMenuItemSprite::create(exitBtnNormal, exitBtnSelected, this, menu_selector(MainmenuScene::clickExitBtn));
    exitBtn->setAnchorPoint(ccp(0, 1));
    exitBtn->setPosition(Tools::getFinalPosition(ccp(POS_EXITBTN_X, POS_EXITBTN_Y)));
    
    //all button in menu
    CCMenu* Menu = CCMenu::create(startBtn, soundBtn, exitBtn, NULL);
    Menu->setPosition(VisibleRect::leftBottom());
    this->addChild(Menu);
    
    return true;
}

void MainmenuScene::clickStartBtn(CCObject* pSender)
{
    
}

void MainmenuScene::clickSoundBtn(CCObject* pSender)
{
    CCMenuItemToggle* soundBtn = (CCMenuItemToggle*)pSender;
    if (soundBtn->getSelectedIndex() == 0)
    {
        //play
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
        Tools::m_bSoundOn = true;
    }
    else
    {
        //stop
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        Tools::m_bSoundOn = false;
    }
    CCUserDefault::sharedUserDefault()->setBoolForKey(DATA_NAME_SOUNDON, Tools::m_bSoundOn);
    CCUserDefault::sharedUserDefault()->flush();
}

void MainmenuScene::clickExitBtn(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}