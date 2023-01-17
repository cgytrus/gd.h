#pragma once

#include <gd.h>

namespace gd {

class FLAlertLayer;
class EffectGameObject;
class CCMenuItemToggler;

class GDH_DLL EditTriggersPopup : public FLAlertLayer {
public:
    EffectGameObject* m_object; // 0x1cc
    cocos2d::CCArray* m_objects; // 0x1d0
    CCMenuItemToggler* m_touchTriggeredToggle; // 0x1d4
    CCMenuItemToggler* m_spawnTriggeredToggle; // 0x1d8
    bool m_touchTriggered; // 0x1dc
    bool m_spawnTriggered; // 0x1dd
    cocos2d::CCArray* m_multiTriggerToggleNodes; // 0x1e0
    bool m_multiTrigger; // 0x1e4

    static EditTriggersPopup* create(EffectGameObject* object, cocos2d::CCArray* objects) {
        return reinterpret_cast<EditTriggersPopup*(__fastcall*)(EffectGameObject*, cocos2d::CCArray*)>(base + 0x137b90)(object, objects);
    }

    bool init(EffectGameObject* object, cocos2d::CCArray* objects) {
        return reinterpret_cast<bool(__thiscall*)(EditTriggersPopup*, EffectGameObject*, cocos2d::CCArray*)>(base + 0x137c40)(this, object, objects);
    }

    void onTouchTriggered(cocos2d::CCObject* o) {
        reinterpret_cast<void(__thiscall*)(EditTriggersPopup*, cocos2d::CCObject*)>(base + 0x138470)(this, o);
    }
    void onSpawnedByTrigger(cocos2d::CCObject* o) {
        reinterpret_cast<void(__thiscall*)(EditTriggersPopup*, cocos2d::CCObject*)>(base + 0x138540)(this, o);
    }
    void onMultiTrigger(cocos2d::CCObject* o) {
        reinterpret_cast<void(__thiscall*)(EditTriggersPopup*, cocos2d::CCObject*)>(base + 0x1386a0)(this, o);
    }

    void updateMultiTriggerBtn() {
        reinterpret_cast<void(__thiscall*)(EditTriggersPopup*)>(base + 0x138650)(this);
    }
};
}
