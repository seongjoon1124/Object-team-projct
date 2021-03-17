#include "stdafx.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

// using namsepace cocod2d
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {

    //!< Auto�� c++ 11���� �����ϴ� ������� �����Ϸ��� �� Ÿ���� ���� �����ϰ� �����ϴ� �޼ҵ�
    //!< ���⼭�� auto director = Director::getInstance(); �̹Ƿ� �����Ϸ��� Director * director = Director::getInstance()�� �ν��ϰ� ��
    auto director = Director::getInstance();	//!< cocos2d-x ��ü�� �����ϴ� Director Ŭ���� ����
    auto glview = director->getOpenGLView();	//!< openGL �׷��� ���̺귯�� ����
    if (!glview) {

        //glview = GLView::create("My Game");											//!< �⺻������ �̷��� �Ǿ� ���� (�����ʴ� ���� ����)
                                                                                        //!< �⺻ �ػ� ũ��� 960 x 640
                                                                                        //!< ȭ�� �ػ� ��� ũ��� 1���
                                                                                        //!< ����Ʈ ���� 1
                                                                                        //!< 960 , 640�� �⺻���� ����


        glview = GLViewImpl::createWithRect(D_GAME_NAME, cocos2d::Rect(0, 0, D_DESIGN_WIDTH, D_DESIGN_HEIGHT), D_WINDOWS_SHOW);	//!< �츮�� ����ؾ� �� �Լ�
                                                                                        //!< ȭ�� ���� �ϸ鼭 ũ��� �ػ� ��� ũ�� ����
                                                                                        //!< ����° ���ڴ� ȭ�� �ػ� ��� ũ��
                                                                                        //!< ���� ����° ���ڰ� 2 �̸� ȭ�� �ػ󵵴� 800 , 480 ���̴� ȭ���� ũ��� 2���� 1600 , 960�� ��

        director->setOpenGLView(glview);												//!< openGLView�� ���� (�׷��� ���� ����)
    }

    //!< �ػ� �ȵ���̵� , ������ , ������ ���� �ҽ�
    //!< �ظ��ϸ� ����ġ (D_DESIGN_WIDTH , HEIGHT �� USER_DEFINE�� ��ġ)
    glview->setDesignResolutionSize(D_DESIGN_WIDTH, D_DESIGN_HEIGHT, kResolutionShowAll);

    //!< ȭ��� ���� ���� �����ӵ� ������ ǥ�� = true
    //!< ǥ�� ���� = false
    director->setDisplayStats(false);

    //!< ������ ����
    //!< 1�ʿ� 60�� ����
    director->setAnimationInterval(1.0 / 60);

    //!< �ʱ� ���� ����
    //!< auto �޼ҵ�� ���� �ڵ����� ���� �ϰ� ��.
    auto scene = StartScene::createScene();

    //!< runWithScene�� ���ؼ� �������� ������ �Բ� ���ø����̼� ����
    director->runWithScene(scene);

    return true;
}

//!< ���ø����̼��� ���� ���� ȨŰ�� Ȧ��ȭ���� ������ �� ������ ����� �ϴ� ��쿡 ����ϴ� �Լ�
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();	//!< �������� ����

    // ���� ���⼭ ����� ���õ� ȿ���� ����ҽ� �ؿ� ������ ���ָ� ��
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

//!< ���ø����̼ǿ� �ٽ� ���� ��
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();	//!< �������� �� ����

    // ���� ���⼭ ����� ���õ� ȿ���� ����ҽ� �ؿ� ������ ���ָ� ��
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
