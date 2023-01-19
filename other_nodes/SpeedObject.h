#ifndef __SPEEDOBJECT_H__
#define __SPEEDOBJECT_H__

#include <gd.h>

namespace gd {
    enum Speed;
    class GameObject;

    class GDH_DLL SpeedObject : public cocos2d::CCNode {
    public:
        Speed m_speed; // 0xec
        float m_xPos; // 0xf0
        GameObject* m_object; // 0xf4

        static SpeedObject* create(GameObject* object, Speed speed, float x) {
            __asm movss xmm2, x;
            return reinterpret_cast<SpeedObject*(__fastcall*)(GameObject* object, Speed speed)>(base + 0x20de70)(object, speed);
        }
    };
}

#endif