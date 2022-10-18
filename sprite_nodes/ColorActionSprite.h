#ifndef __COLORACTIONSPRITE_H__
#define __COLORACTIONSPRITE_H__

#include <gd.h>

namespace gd {
    class GDH_DLL ColorActionSprite : public cocos2d::CCNode {
    public:
        float m_opacity;
        cocos2d::ccColor3B m_f0124;
        cocos2d::ccColor3B m_activeColor;
    };
}

#endif