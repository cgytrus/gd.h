#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#include <gd.h>

namespace gd {
	class GDH_DLL LoadingLayer : public cocos2d::CCLayer {
	public:
		bool unk11C;
		bool unk11D;
		int m_nLoadStep;
		cocos2d::CCLabelBMFont* m_pCaption;
		TextArea* m_pTextArea;
		cocos2d::CCSprite* m_pSliderBar;
		float m_fSliderGrooveXPos;
		float m_fSliderGrooveHeight;
		bool m_bFromRefresh;

		static LoadingLayer* create(bool fromReload) {
			return reinterpret_cast<LoadingLayer* (__fastcall*)(bool)>(
				base + 0x18BFE0
				)(fromReload);
		}
		void setFromRefresh(bool value) {
			m_bFromRefresh = value;
		}
		// idk if the name is right but idc
		void openMenuLayer() {
			return reinterpret_cast<void (__thiscall*)(LoadingLayer*)>(base + 0x18c790)(this);
		}
	};
}

#endif