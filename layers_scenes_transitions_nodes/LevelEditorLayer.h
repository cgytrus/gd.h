#ifndef __LEVELEDITORLAYER_H__
#define __LEVELEDITORLAYER_H__

#include <gd.h>

namespace gd {

    class GJBaseGameLayer;
    class EditorUI;
    class GameObject;

    class LevelEditorLayer : public GJBaseGameLayer {
    public:
<<<<<<< HEAD
        PAD(0x88)
        int m_nCurrentLayer;
        PAD(0x28)
        EditorUI* m_pEditorUI;

    public:
        EditorUI* getEditorUI() { return this->m_pEditorUI; }
=======
        PAD(0x84)
        int m_currentLayer;
        PAD(0x2c)
        EditorUI* m_editorUI;
>>>>>>> 8008deeeba5a62da9e307c4ced3819849035104f

        void removeObject(GameObject * obj, bool idk) {
            reinterpret_cast<void(__thiscall*)(
                LevelEditorLayer *,GameObject *,bool
            )>(
                base + 0x161cb0
            )(
                this, obj, idk
            );
        }

        int getNextFreeGroupID(cocos2d::CCArray* objs) {
            return reinterpret_cast<int(__thiscall*)(
                LevelEditorLayer*, cocos2d::CCArray*
            )>(
                base + 0x164ae0
            )(
                this, objs
            );
        }

        GameObject* addObjectFromString(std::string const& str) {
            return reinterpret_cast<GameObject*(__thiscall*)(LevelEditorLayer*, std::string)>(base + 0x160c80)(this, str);
        }
    };

}

#endif
