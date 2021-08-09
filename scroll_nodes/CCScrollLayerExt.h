#ifndef __CCSCROLLLAYEREXT_H__
#define __CCSCROLLLAYEREXT_H__

#include <gd.h>

namespace gd {

	class CCContentLayer;
	class TableView;

	class TableViewCell : public cocos2d::CCLayer {
		public:
			bool m_bUnknown;	// 0x11c
			PAD(3)
			TableView* m_pTableView; 	// 0x120
			CCIndexPath m_iIndexPath;	// 0x124
			PAD(4)
			std::string m_sUnknown;	// 0x12c
			PAD(44)
			cocos2d::CCLayerColor* m_pBGLayer;	// 0x170
			cocos2d::CCLayer* m_pLayer;	// 0x174
			PAD(4)

			TableViewCell(const char* name, float width, float height) {
				__asm {
					movss xmm2, height
					movss xmm3, width
				}
				reinterpret_cast<void(__thiscall*)(TableViewCell*, const char*)>(
					base + 0x32E70
				)(this, name);
			}

			static TableViewCell* create(const char* name, float width, float height) {
				auto pRet = new TableViewCell(name, width, height);

				if (pRet) {
					pRet->autorelease();
					return pRet;
				}

				CC_SAFE_DELETE(pRet);
				return nullptr;
			}
	};

	class CCScrollLayerExt : public cocos2d::CCLayer {
		public:
			cocos2d::CCTouch* m_pTouch;	// 0x11c
			cocos2d::CCPoint m_obTouchPosition;		 // 0x120
			cocos2d::CCPoint m_obTouchStartPosition; // 0x128
			PAD(8)
			bool m_bTouchDown;	// 0x138
			bool m_bNotAtEndOfScroll;	// 0x139
			PAD(2)
			cocos2d::CCLayerColor* m_pVerticalScrollbar;	// 0x13c
			cocos2d::CCLayerColor* m_pHorizontalScrollbar;	// 0x140
			PAD(4)
			CCContentLayer* m_pContentLayer;	// 0x148
			bool m_bCutContent; // 0x14c
			bool m_bVScrollbarVisible;	// 0x14d
			bool m_bHScrollbarVisible;	// 0x14e
			bool m_bDisableHorizontal; // 0x14f
			bool m_bDisableVertical; // 0x150
			bool m_bDisableMovement; // 0x151
			PAD(2)
			float m_fScrollLimitTop; // 0x154
			float m_fScrollLimitBottom; // 0x158
			float m_fPeekLimitTop; // 0x15c
			float m_fPeekLimitBottom; // 0x160

			CCScrollLayerExt(cocos2d::CCRect rect) {
				reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, cocos2d::CCRect)>(
					base + 0x1B020
				)(this, rect);
			}

			//own vtable
			virtual void preVisitWithClippingRect(cocos2d::CCRect rect) {
				return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, cocos2d::CCRect)>(
					base + 0x1C000
				)(this, rect);
			}
			virtual void postVisit() {
				return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
					base + 0x1C090
				)(this);
			}

			static CCScrollLayerExt* create(cocos2d::CCRect rect, bool vertical = true) {
				auto pRet = new CCScrollLayerExt(rect);

				if (pRet) {
					pRet->autorelease();
					pRet->m_bDisableVertical = !vertical;
					pRet->m_bDisableHorizontal = vertical;
					pRet->m_bCutContent = true;
					return pRet;
				}

				CC_SAFE_DELETE(pRet);
				return nullptr;
			}

			void scrollLayer(float scroll) {
				__asm movss xmm1, scroll

				reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
					base + 0x1be20
				)(this);
			}

			void moveToTop() {
				reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
					base + 0x1b4a0
				)(this);
			}

			void moveToTopWithOffset(float fOffset) {
				__asm { movss xmm1, fOffset }

				reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
					base + 0x1b420
				)(this);
			}

			void addItem(CCNode* cell, bool addToTop = false) {
				float height = 0.0f;
				CCObject* obj;
				CCARRAY_FOREACH(this->m_pContentLayer->getChildren(), obj) {
					auto node = reinterpret_cast<CCNode*>(obj);

					height += node->getScaledContentSize().height;

					if (!addToTop)
					node->setPositionY(node->getPositionY() + cell->getScaledContentSize().height);
				}

				cell->setPosition(
					this->getScaledContentSize().width / 2,
					addToTop ? 
					height + cell->getScaledContentSize().height / 2 :
					cell->getScaledContentSize().height / 2
				);

				height += cell->getScaledContentSize().height;

				this->m_pContentLayer->addChild(cell);

				this->m_pContentLayer->setContentSize({
					cell->getScaledContentSize().width, height
				});
			}
	};

	class CCScrollLayerExtDelegate {
		public:
			//lol nice typo rob
			virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt*) {}
			virtual void scrollViewDidEndDecelerating(CCScrollLayerExt*) {}
			virtual void scrollViewTouchMoving(CCScrollLayerExt*) {}
			virtual void scrollViewDidEndMoving(CCScrollLayerExt*) {}
			virtual void scrollViewTouchBegin(CCScrollLayerExt*) {}
			virtual void scrollViewTouchEnd(CCScrollLayerExt*) {}
	};
}

#endif