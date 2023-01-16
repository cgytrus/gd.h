#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <gd.h>
#include <array>

namespace gd {

	class CCSpritePlus;

	// jesus fucking christ (painfully written by @hjfod)
	enum GameObjectType {
		kGameObjectTypeSolid = 0,
		kGameObjectTypeHazard = 2,
		kGameObjectTypeInverseGravityPortal = 3,
		kGameObjectTypeNormalGravityPortal = 4,
		kGameObjectTypeShipPortal = 5,
		kGameObjectTypeCubePortal = 6,
		kGameObjectTypeDecoration = 7,
		kGameObjectTypeYellowJumpPad = 8,
		kGameObjectTypePinkJumpPad = 9,
		kGameObjectTypeGravityPad = 10,
		kGameObjectTypeYellowJumpRing = 11,
		kGameObjectTypePinkJumpRing = 12,
		kGameObjectTypeGravityRing = 13,
		kGameObjectTypeInverseMirrorPortal = 14,
		kGameObjectTypeNormalMirrorPortal = 15,
		kGameObjectTypeBallPortal = 16,
		kGameObjectTypeRegularSizePortal = 17,
		kGameObjectTypeMiniSizePortal = 18,
		kGameObjectTypeUfoPortal = 19,
		kGameObjectTypeModifier = 20,
		kGameObjectTypeSecretCoin = 22,
		kGameObjectTypeDualPortal = 23,
		kGameObjectTypeSoloPortal = 24,
		kGameObjectTypeSlope = 25,
		kGameObjectTypeWavePortal = 26,
		kGameObjectTypeRobotPortal = 27,
		kGameObjectTypeTeleportPortal = 28,
		kGameObjectTypeGreenRing = 29,
		kGameObjectTypeCollectible = 30,
		kGameObjectTypeUserCoin = 31,
		kGameObjectTypeDropRing = 32,
		kGameObjectTypeSpiderPortal = 33,
		kGameObjectTypeRedJumpPad = 34,
		kGameObjectTypeRedJumpRing = 35,
		kGameObjectTypeCustomRing = 36,
		kGameObjectTypeDashRing = 37,
		kGameObjectTypeGravityDashRing = 38,
		kGameObjectTypeCollisionObject = 39,
		kGameObjectTypeSpecial = 40,
	};

	class GJSpriteColor;
	class ColorActionSprite;
	class GJEffectManager;

	class GJSpriteColor;
	class ColorActionSprite;
	class GJEffectManager;

	#pragma runtime_checks("s", off)
	class GDH_DLL GameObject : public CCSpritePlus /* 0x1f0 */ {
	public:
		bool m_bUnk3;				// 0x1f0
		bool m_bIsBlueMaybe;		// 0x1f1
		float m_fUnk2;				// 0x1f4
		float m_fUnk;				// 0x1f8
		float m_fUnk3;				// 0x1fc
		float m_fUnk4;				// 0x200
		bool m_bUnk;				// 0x204
		float m_fAnimSpeed2;		// 0x208
		bool m_bIsEffectObject;		// 0x20c
		bool m_bRandomisedAnimStart;// 0x20d
		float m_fAnimSpeed;			// 0x210
		bool m_bBlackChild;			// 0x214
		bool m_bUnkOutlineMaybe;	// 0x215
		float m_fBlackChildOpacity;	// 0x218
		bool field_21C;	// 0x21c
		bool m_bEditor;	// 0x21d
		bool m_bGroupDisabled;	// 0x21e
		bool m_bColourOnTop;	// 0x21f
		int m_baseColorID;		// 0x220
		int m_detailColorID;	// 0x224
		bool m_baseColorHSVModified;	// 0x228
		bool m_detailColorHSVModified;	// 0x229
		cocos2d::CCPoint m_obStartPosOffset; //0x22C
		float m_fUnkRotationField;	// 0x234
		bool m_bTintTrigger;	// 0x238
		bool m_bIsFlippedX; 	//0x239
		bool m_bIsFlippedY; 	//0x23A
		cocos2d::CCPoint m_obBoxOffset; //0x23C
		bool m_bIsOriented; //0x244
		cocos2d::CCPoint m_obBoxOffset2; // 0x248
		OBB2D* m_pObjectOBB2D;	// 0x250
		bool m_bOriented;	// 0x254
		cocos2d::CCSprite* m_pGlowSprite;	// 0x258
		bool m_bNotEditor;	// 0x25c
		cocos2d::CCAction* m_pMyAction; //0x260
		bool m_bUnk1;	//0x264
		bool m_bRunActionWithTag;	//0x265
		bool m_bObjectPoweredOn;	//0x266
		cocos2d::CCSize m_obObjectSize; //0x268
		bool m_bTrigger;	// 0x270
		bool m_bActive; 	// 0x271
		bool m_bAnimationFinished;	// 0x272
		cocos2d::CCParticleSystemQuad* m_pParticleSystem;	// 0x274
		std::string m_sEffectPlistName; // 0x278
		bool m_bParticleAdded;	// 0x290
		bool m_bHasParticles;	// 0x291
		bool m_bUnkCustomRing;	// 0x292
		cocos2d::CCPoint m_obPortalPosition;	// 0x294
		bool m_bUnkParticleSystem;	// 0x29c
		cocos2d::CCRect m_obObjectTextureRect;	// 0x2a0
		bool m_bTextureRectDirty;	// 0x2b0
		float m_fRectXCenterMaybe;	// 0x2b4
		cocos2d::CCRect m_obObjectRect2; //0x2B8
		bool m_bIsObjectRectDirty; //0x2C8
		bool m_bIsOrientedRectDirty; //0x2C9
		bool m_bHasBeenActivated; //0x2CA
		bool m_bHasBeenActivatedP2; //0x2CB
		PAD(16);
		bool m_bSawIsDisabled; // 0x2dc
		PAD(5);
		bool m_unk2e2;
		PAD(1);
		cocos2d::CCSprite* m_pDetailSprite; //0x2E4
		bool m_unk2e8;
		PAD(7);
		bool m_bIsRotatedSide; //0x2F0 for 90 and 270 degrees rotations
		PAD(3);
		float m_unk2F4;
		float m_unk2F8;
		int m_nUniqueID; //0x2FC
		GameObjectType m_nObjectType; //0x300
		int m_nSection; //0x304
		bool m_bTouchTriggered; //0x308
		bool m_bSpawnTriggered; //0x309
		PAD(2)
		cocos2d::CCPoint m_obStartPosition; //0x30C
		std::string m_sTextureName; //0x314
		bool m_useAudioScale; // 0x32c
		bool m_sleeping; // 0x32d
		float m_rotation; // 0x330
		cocos2d::CCSize m_obStartScale; // 0x334
		bool m_startFlipX; // 0x33c
		bool m_startFlipY; // 0x33d
		bool m_shouldHide; // 0x33e
		float m_spawnXPosition; // 0x340
		bool m_invisible; // 0x344
		float m_enterAngle; // 0x348
		int m_activeEnterEffect; // 0x34c
		int m_parentMode; // 0x350
		bool m_bIsGlowDisabled; //0x354
		PAD(3);
		int m_nTargetColorID;	// 0x358 (for color triggers)
		float m_fScale; //0x35C
		int m_nObjectID; //0x360
		bool m_unk364;
		bool m_unk365;
		bool m_unk366;
		bool m_ignoreFade; // 0x367
		bool m_unk368;
		bool m_unk369;
		bool m_unk36A;
		bool m_bIsDontEnter; //0x36B
		bool m_bIsDontFade; //0x36C
		int m_nDefaultZOrder; // 0x370
		bool m_unk374;
		bool m_unk375;
		bool m_customAudioScale; // 0x376
		PAD(1);
		float m_minAudioScale; // 0x378
		float m_maxAudioScale; // 0x37c
		bool m_unkParticleSystem2;
		int m_secretCoinID;
		int m_unkUnusedSaveStringKey53;
		bool m_invisibleMode; // 0x38c
		bool m_glowUserBackgroundColour; // 0x38d
		bool m_useSpecialLight; // 0x38e
		bool m_orbOrPad; // 0x38f
		float m_glowOpacityMod; // 0x390
		PAD(20);
		GJSpriteColor* m_pBaseColor; //0x3A8
		GJSpriteColor* m_pDetailColor; //0x3AC
		bool m_unk3b0;
		ZLayer m_nDefaultZLayer; // 0x3B4
		ZLayer m_nZLayer; //0x3B8
		int m_nGameZOrder; //0x3BC
		std::string m_unk3C0;
		bool m_bShowGamemodeBorders;
		bool m_unk3D9;
		bool m_bIsSelected; //0x3DA
		PAD(1);
		int m_nGlobalClickCounter; //0x3DC i have no idea what this is for
		PAD(8)
		bool m_bUnknownLayerRelated;	// 0x3e8
		float m_fMultiScaleMultiplier;	// 0x3ec
		bool m_bIsGroupParent; //0x3F0
		PAD(3);
		std::array<short, 10>* m_pGroups; //0x3F4
		short m_nGroupCount; //0x3F8
		std::array<short, 10>* m_pulseGroups; // 0x3fc
		short m_pulseGroupCount; // 0x400
		std::array<short, 10>* m_alphaGroups; // 0x404
		short m_alphaGroupCount; // 0x408
		int m_nEditorLayer; //0x40C
		int m_nEditorLayer2; //0x410
		int m_unk414;
		PAD(12);
		cocos2d::CCPoint m_obFirstPosition; //0x424 first position from when its placed in the editor
		bool m_unk42C;
		bool m_unk42D;
		PAD(6);
		bool m_isAnimated; // 0x434
		PAD(7);
		bool m_isEffect; // 0x43c
		bool m_specialUnk43d;
		PAD(1);
		bool m_specialUnk43f;
		bool m_isTriggerable; // 0x440
		bool m_specialUnk441;
		PAD(6);
		bool m_bHighDetail; //0x448
		PAD(3);
		ColorActionSprite* m_pColorActionSprite1; //0x44C
		ColorActionSprite* m_pColorActionSprite2; //0x450
		GJEffectManager* m_pEffectManager; //0x454
		PAD(16);

		//CCNode vtable
		virtual void setScaleX(float scale) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, float)>(
				base + 0xE5050
				)(this, scale);
		}
		virtual void setScaleY(float scale) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, float)>(
				base + 0xE50E0
				)(this, scale);
		}
		virtual void setScale(float scale) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, float)>(
				base + 0xE5170
				)(this, scale);
		}
		virtual void setPosition(const cocos2d::CCPoint& pos) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, const cocos2d::CCPoint&)>(
				base + 0xE4DE0
				)(this, pos);
		}
		virtual void setVisible(bool visible) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, bool)>(
				base + 0xE57C0
				)(this, visible);
		}
		virtual void setRotation(float rotation) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, float)>(
				base + 0xE4ED0
				)(this, rotation);
		}
		virtual bool initWithTexture(cocos2d::CCTexture2D* texture) {
			return reinterpret_cast<bool(__thiscall*)(GameObject*, cocos2d::CCTexture2D*)>(
				base + 0xCFA80
				)(this, texture);
		}
		virtual void setChildColor(const cocos2d::ccColor3B& color) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, const cocos2d::ccColor3B&)>(
				base + 0xEE900
				)(this, color);
		}

		//CCRGBAProtocol vtable
		virtual void setOpacity(GLubyte opacity) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, GLubyte)>(
				base + 0xE53C0
				)(this, opacity);
		}

		static GameObject* createWithKey(int key) {
			return reinterpret_cast<GameObject* (__fastcall*)(int)>(
				base + 0xcf4f0
				)(key);
		}
		static GameObject* createWithFrame(const char* frame) {
			return reinterpret_cast<GameObject* (__fastcall*)(const char*)>(
				base + 0xCF8F0
				)(frame);
		}
		static GameObject* objectFromString(std::string str, bool unknown) {
			auto pRet = reinterpret_cast<GameObject* (__fastcall*)(std::string, bool)>(
				base + 0xEBE50
				)(str, unknown);
			__asm add esp, 0x18
			return pRet;
		}

		void deselectObject() {
			this->m_bIsSelected = false;

			return reinterpret_cast<void(__fastcall*)(GameObject*)>(
				base + 0xeee50
			)(this);
		}

		std::string getSaveString() {
			std::string ret;

			reinterpret_cast<void(__thiscall*)(GameObject*, std::string*)>(
				base + 0xed0c0
			)(
				this, &ret
			);

			return ret;
		}

		void addToGroup(int id) {
			reinterpret_cast<void(__thiscall*)(
				GameObject*, int
			)>(
				base + 0xeb8d0
			)(
				this, id
			);
		}

		void removeFromGroup(int id) {
			reinterpret_cast<void(__thiscall*)(
				GameObject*, int
			)>(
				base + 0xeb930
			)(
				this, id
			);
		}

		cocos2d::CCPoint getBoxOffset() {
			return *reinterpret_cast<cocos2d::CCPoint*(__thiscall*)(
				GameObject*
			)>(base + 0xef350)(this);
		}

		cocos2d::CCPoint getStartPosition() { return m_obStartPosition; }
		void setStartPosition(cocos2d::CCPoint const& p) { m_obStartPosition = p; }
		
		unsigned int getUniqueID() { return m_nUniqueID; }
		short getGroupID(int ix) { return m_pGroups->at(ix); }
		short getGroupIDCount() { return m_nGroupCount; }
		std::vector<short> getGroupIDs() {
			std::vector<short> res;

			if (m_pGroups != nullptr && m_pGroups->at(0) > 0)
				for (auto i = 0; i < m_nGroupCount; i++)
					res.push_back(m_pGroups->at(i));
		
			return res;
		}
		int getGameZOrder() { return m_nGameZOrder; }
		void setGameZOrder(int z) { m_nGameZOrder = z; }
		void setGameObjType(GameObjectType t) { m_nObjectType = t; }

		GJSpriteColor* getBaseColor() { return m_pBaseColor; }
		GJSpriteColor* getDetailColor() { return m_pDetailColor; }
		
		void updateCustomScale(float scale) {
			__asm movss xmm1, scale;
			reinterpret_cast<void(__thiscall*)(GameObject*)>(base + 0xe5340)(this);
		}
		void setRScale(float scale) {
			(*reinterpret_cast<void(__thiscall**)(GameObject*, float)>(*reinterpret_cast<uintptr_t*>(this) + 0x264))(this, scale);
		}
		void setObjectColor(const cocos2d::ccColor3B& color) {
			(*reinterpret_cast<void(__thiscall**)(gd::GameObject*, const cocos2d::ccColor3B&)>(*reinterpret_cast<uintptr_t*>(this) + 0x280))(this, color);
		}
		void setGlowColor(const cocos2d::ccColor3B& color) {
			(*reinterpret_cast<void(__thiscall**)(gd::GameObject*, const cocos2d::ccColor3B&)>(*reinterpret_cast<uintptr_t*>(this) + 0x284))(this, color);
		}
		void setGlowOpacity(GLubyte opacity) {
			if(m_pGlowSprite == nullptr)
				return;
			m_pGlowSprite->setOpacity(opacity);
			m_pGlowSprite->setChildOpacity(opacity);
		}
		void updateMainColor(const cocos2d::ccColor3B& color) {
			setObjectColor(color);
		}
		void updateSecondaryColor(const cocos2d::ccColor3B& color) {
			setChildColor(color);
		}
		void selectObject(const cocos2d::ccColor3B& color = { 0, 255, 0 }) {
			reinterpret_cast<void(__thiscall*)(GameObject*, const cocos2d::ccColor3B)>(base + 0xee960)(this, color);
		}
		cocos2d::CCRect* getObjectTextureRect() {
			return (*reinterpret_cast<cocos2d::CCRect*(__thiscall**)(GameObject*)>(*reinterpret_cast<uintptr_t*>(this) + 0x23c))(this);
		}
		void deactivateObject(bool idk) {
			(*reinterpret_cast<void(__thiscall**)(GameObject*, bool)>(*reinterpret_cast<uintptr_t*>(this) + 0x22c))(this, idk);
		}
		void activateObject() {
			(*reinterpret_cast<void(__thiscall**)(GameObject*)>(*reinterpret_cast<uintptr_t*>(this) + 0x228))(this);
		}
		void updateSyncedAnimation(float totalTime) {
			__asm movss xmm1, totalTime;
			reinterpret_cast<void(__thiscall*)(GameObject*)>(base + 0xe7320)(this);
		}
		void updateChildSpriteColor(cocos2d::ccColor3B color) {
			reinterpret_cast<void(__thiscall*)(GameObject*, cocos2d::ccColor3B)>(base + 0x2531f0)(this, color);
		}
		void addMainSpriteToParent(bool idk) {
			(*reinterpret_cast<void(__thiscall**)(gd::GameObject*, bool)>(*reinterpret_cast<uintptr_t*>(this) + 0x21c))(this, idk);
		}
		void addColorSpriteToParent(bool idk) {
			reinterpret_cast<void(__thiscall*)(GameObject*, bool)>(base + 0xeb3f0)(this, idk);
		}
		cocos2d::CCPoint& getRealPosition(cocos2d::CCPoint& ret) {
			return (*reinterpret_cast<cocos2d::CCPoint&(__thiscall**)(GameObject*, cocos2d::CCPoint&)>(*reinterpret_cast<uintptr_t*>(this) + 0x240))(this, ret);
		}
		float groupOpacityMod() {
			reinterpret_cast<void(__thiscall*)(GameObject*)>(base + 0xebda0)(this);
			float x;
			__asm movss x, xmm0;
			return x;
		}
		cocos2d::ccColor3B& colorForMode(int mode, bool isMain) {
			return reinterpret_cast<cocos2d::ccColor3B&(__thiscall*)(GameObject*, int, bool)>(base + 0xef8d0)(this, mode, isMain);
		}

		cocos2d::CCRepeatForever* createRotateAction(float f, int n) {
			__asm movss xmm1, f

			auto pRet = reinterpret_cast<cocos2d::CCRepeatForever*(__thiscall*)(GameObject*, int)>(
				base + 0xe49b0
			)(this, n);

			return pRet;
		}

		void setMyAction(cocos2d::CCAction* pAction) {
			return reinterpret_cast<void(__thiscall*)(GameObject*, cocos2d::CCAction*)>(
				base + 0xd1b90
			)(this, pAction);
		}
	};

	#pragma runtime_checks("s", restore)
}

#endif