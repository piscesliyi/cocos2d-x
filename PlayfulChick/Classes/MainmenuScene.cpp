//
//  MainmenuScene.cpp
//  PlayfulChick
//
//  Created by liyi on 13-9-13.
//
//

#include "MainmenuScene.h"

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
    
    Tools::m_bSoundOn = CCUserDefault::sharedUserDefault()->getBoolForKey("soundon", true);
    
    //background
    CCSprite* menuBg = CCSprite::create("menu_bg.png");
    menuBg->setPosition(VisibleRect::center());
    this->addChild(menuBg);
    
    //start button
    CCSprite* startBtnImage = CCSprite::create("menu_start.png");
    CCRect normalRect = CCRectMake(0, 0, startBtnImage->getContentSize().width/2, startBtnImage->getContentSize().height);
    CCRect selectedRect = CCRectMake(startBtnImage->getContentSize().width/2, 0, startBtnImage->getContentSize().width/2, startBtnImage->getContentSize().height);
    CCSprite* startBtnNormal = CCSprite::create("menu_start.png", normalRect);
    CCSprite* startBtnSelected = CCSprite::create("menu_start.png", selectedRect);
    CCMenuItemSprite* startBtn = CCMenuItemSprite::create(startBtnNormal, startBtnSelected, this, menu_selector(MainmenuScene::clickStartBtn));
    startBtn->setAnchorPoint(ccp(0, 1));
    startBtn->setPosition(Tools::getFinalPosition(ccp(117, 312)));
    
    //sound button
    CCSprite* soundBtnImage = CCSprite::create("menu_sound.png");
    normalRect = CCRectMake(0, 0, soundBtnImage->getContentSize().width/2, soundBtnImage->getContentSize().height);
    selectedRect = CCRectMake(soundBtnImage->getContentSize().width/2, 0, soundBtnImage->getContentSize().width/2, soundBtnImage->getContentSize().height);
    CCSprite* soundBtnNormal = CCSprite::create("menu_sound.png", normalRect);
    CCSprite* soundBtnSelected = CCSprite::create("menu_sound.png", selectedRect);
    CCMenuItemSprite* itemSoundon = CCMenuItemSprite::create(soundBtnNormal, NULL, this, NULL);
    CCMenuItemSprite* itemSoundoff = CCMenuItemSprite::create(soundBtnSelected, NULL, this, NULL);
    CCMenuItemToggle* soundBtn = CCMenuItemToggle::createWithTarget(this, menu_selector(MainmenuScene::clickSoundBtn), itemSoundon, itemSoundoff, NULL);
    soundBtn->setAnchorPoint(ccp(0, 1));
    soundBtn->setPosition(Tools::getFinalPosition(ccp(790, 110)));
    if (Tools::m_bSoundOn)
    {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
    }
    else
    {
        soundBtn->setSelectedIndex(1);
    }
    
    //exit button
    CCSprite* exitBtnImage = CCSprite::create("menu_exit.png");
    normalRect = CCRectMake(0, 0, exitBtnImage->getContentSize().width/2, exitBtnImage->getContentSize().height);
    selectedRect = CCRectMake(exitBtnImage->getContentSize().width/2, 0, exitBtnImage->getContentSize().width/2, exitBtnImage->getContentSize().height);
    CCSprite* exitBtnNormal = CCSprite::create("menu_exit.png", normalRect);
    CCSprite* exitBtnSelected = CCSprite::create("menu_exit.png", selectedRect);
    CCMenuItemSprite* exitBtn = CCMenuItemSprite::create(exitBtnNormal, exitBtnSelected, this, menu_selector(MainmenuScene::clickExitBtn));
    exitBtn->setAnchorPoint(ccp(0, 1));
    exitBtn->setPosition(Tools::getFinalPosition(ccp(870, 110)));
    
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
    CCUserDefault::sharedUserDefault()->setBoolForKey("soundon", Tools::m_bSoundOn);
    CCUserDefault::sharedUserDefault()->flush();
}

void MainmenuScene::clickExitBtn(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}