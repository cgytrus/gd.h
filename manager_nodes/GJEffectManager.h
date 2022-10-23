#ifndef __GJEFFECTMANAGER_H__
#define __GJEFFECTMANAGER_H__

#include <gd.h>

namespace gd {
    class ColorAction;
    class GDH_DLL GJEffectManager : public cocos2d::CCNode {
    public:
        PAD(4);
        cocos2d::CCDictionary* m_colorActionDict; // 0xF0

        ColorAction* getColorAction(int num) {
            return reinterpret_cast<ColorAction*(__thiscall*)(
                GJEffectManager*, int
            )>(
                base + 0x11cde0
            )(
                this, num
            );
        }

        cocos2d::ccColor3B activeColorForIndex(int index) {
            return reinterpret_cast<cocos2d::ccColor3B(__thiscall*)(GJEffectManager*, int)>(base + 0x11c6e0)(this, index);
        }
        void calculateLightBGColor(cocos2d::ccColor3B color) {
            reinterpret_cast<void(__thiscall*)(GJEffectManager*, cocos2d::ccColor3B)>(base + 0x11f420)(this, color);
        }
        static cocos2d::ccColor3B& getMixedColor(cocos2d::ccColor3B& ret, cocos2d::ccColor3B top, cocos2d::ccColor3B bottom, float t) {
            __asm movss xmm3, t;
            return reinterpret_cast<cocos2d::ccColor3B&(__cdecl*)(cocos2d::ccColor3B&, cocos2d::ccColor3B, cocos2d::ccColor3B)>(base + 0x11f610)(ret, top, bottom);
        }

        void processColors() {
            reinterpret_cast<void(__thiscall*)(GJEffectManager*)>(base + 0x11c7c0)(this); // calculateBaseActiveColors
            reinterpret_cast<void(__thiscall*)(GJEffectManager*)>(base + 0x11ea50)(this); // processPulseActions
            reinterpret_cast<void(__thiscall*)(GJEffectManager*)>(base + 0x11c8a0)(this); // processInheritedActions
            reinterpret_cast<void(__thiscall*)(GJEffectManager*)>(base + 0x11ebc0)(this); // processCopyColorPulseActions
        }
    };
}

#endif