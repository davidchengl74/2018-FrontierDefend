LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := PineEngine
LOCAL_SRC_FILES := $(LOCAL_PATH)/../../game/Lib/PineEngine/_android/libPineEngine.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := FreeType
LOCAL_SRC_FILES := $(LOCAL_PATH)/../../game/Lib/FreeType/_android/libFreeType.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := pine_framework

LOCAL_C_INCLUDES += $(LOCAL_PATH) \
					$(STLPORT_BASE)/stlport \
					$(LOCAL_PATH)/../../game/Lib/PineEngine/includes \
					$(LOCAL_PATH)/../../game/Lib/FreeType/header \
					$(LOCAL_PATH)/../../game/GameCore

LOCAL_CFLAGS := -DANDROID_NDK \
				-DANDROID_OS \
				-std=c++11 \
				-w \
				-DOPENSSL_STATIC\
				-D_DEBUG \
				-DNDK_DEBUG=1
				
LOCAL_CPPFLAGS  += -std=c++11 -DANDROID_NDK -DANDROID_OS -D_DEBUG

LOCAL_CPP_FEATURES += exceptions

LOCAL_SRC_FILES := \
	core/jni_OsFunction.cpp \
	core/jni_game.cpp \
	core/jni_environment.cpp \
	core/jni_log.cpp \
	core/jni_service_manager.cpp \
	../../game/Lib/DataInputStream/DataInputStream.cpp \
	../../game/Lib/DataType/BufferStream.cpp \
	../../game/Lib/DataType/ServiceStream.cpp \
	../../game/Lib/Sprite/CSprite.cpp \
	../../game/Lib/OpenGLES/Graphic.cpp \
	../../game/Lib/OpenGLES/GLESLib1.cpp \
	../../game/Lib/png/png.cpp \
	../../game/Lib/png/lodepng.cpp \
	../../game/Lib/String/StringUtils.cpp \
	../../game/Lib/PineImage.cpp \
	../../game/Lib/Sound/OpenSLES/Sound.cpp \
	../../game/Lib/Sound/OpenSLES/Music.cpp \
	../../game/Lib/Sound/OpenSLES/SoundOpenSLES.cpp \
	../../game/Lib/Sound/OpenSLES/WaveFormat.cpp \
	../../game/Lib/PineFacebookController.cpp \
	../../game/Lib/PineGameCenterController.cpp \
	../../game/Lib/PineTwitterController.cpp \
	../../game/Lib/PineSocial.cpp \
	../../game/Lib/PineSocialAsync.cpp \
	../../game/Lib/PineUnityAdsAsync.cpp \
	../../game/Lib/PineTapdaqAsync.cpp \
	../../game/Lib/PineAdsVungleAsync.cpp \
	../../game/Lib/PineStore.cpp \
	../../game/Lib/PineAdBox.cpp \
	../../game/GameCore/CAnimObject.cpp \
	../../game/GameCore/CGame_Core.cpp \
	../../game/GameCore/CTouch.cpp \
	../../game/GameCore/Device.cpp \
	../../game/GameCore/GameContext.cpp \
	../../game/GameCore/PineGame.cpp \
	../../game/Lib/Math/CMath.cpp \
	../../game/Lib/Math/SMatrix4x4.cpp \
	../../game/Lib/Math/PineMatrix4.cpp \
	../../game/Lib/Math/PineVector3.cpp \
	../../game/Lib/Math/PinePolygon.cpp \
	../../game/GamePlay/Android_Connector.cpp \
	../../game/GamePlay/Game_ExternFunctions.cpp \
	../../game/GamePlay/CGame_State.cpp \
	../../game/GamePlay/GameObject/CScrollBar.cpp \
	../../game/GamePlay/GameObject/MenuSystem.cpp \
	../../game/GamePlay/GameObject/SpriteList.cpp \
	../../game/GamePlay/GameObject/CMaxtrix4x4Util.cpp \
	../../game/GamePlay/GameObject/CUser.cpp \
	../../game/GamePlay/GameObject/Pine_Date_Time.cpp \
	../../game/GamePlay/GameObject/CBird.cpp \
	../../game/GamePlay/GameObject/CBulletAttack.cpp \
	../../game/GamePlay/GameObject/CCastle.cpp \
	../../game/GamePlay/GameObject/CCharacter.cpp \
	../../game/GamePlay/GameObject/CDialog.cpp \
	../../game/GamePlay/GameObject/CDialogManager.cpp \
	../../game/GamePlay/GameObject/CDrawableManager.cpp \
	../../game/GamePlay/GameObject/CEffectFire.cpp \
	../../game/GamePlay/GameObject/CEffectFireUp.cpp \
	../../game/GamePlay/GameObject/CEffectNotify.cpp \
	../../game/GamePlay/GameObject/CEffectShadow.cpp \
	../../game/GamePlay/GameObject/CGiftBox.cpp \
	../../game/GamePlay/GameObject/CHero.cpp \
	../../game/GamePlay/GameObject/CItemRelic.cpp \
	../../game/GamePlay/GameObject/CPartical.cpp \
	../../game/GamePlay/GameObject/CPushNotification.cpp \
	../../game/GamePlay/GameObject/CQuest.cpp \
	../../game/GamePlay/GameObject/CSkill.cpp \
	../../game/GamePlay/GameObject/CSkillAcid.cpp \
	../../game/GamePlay/GameObject/CSkillBeastMaster.cpp \
	../../game/GamePlay/GameObject/CSkillRainShower.cpp \
	../../game/GamePlay/GameObject/CSkillRobo.cpp \
	../../game/GamePlay/GameObject/CSkillSanta.cpp \
	../../game/GamePlay/GameObject/CSkillWordFlash.cpp \
	../../game/GamePlay/GameObject/CThrowObject.cpp \
	../../game/GamePlay/GameObject/CWeapon.cpp \
	../../game/GamePlay/GameObject/EffectItemFly.cpp \
	../../game/GamePlay/GameObject/EffectScrollNumber.cpp \
	../../game/GamePlay/GameObject/GameDesign.cpp \
	../../game/GamePlay/GameObject/ItemBox.cpp \
	../../game/GamePlay/GameObject/CAsyncTasks.cpp \
	../../game/GamePlay/GameState/CGame_State_Design_Function.cpp \
	../../game/GamePlay/GameState/CGame_State_ExFuntion.cpp \
	../../game/GamePlay/GameState/CGame_State_GameOver.cpp \
	../../game/GamePlay/GameState/CGame_State_GamePlay.cpp \
	../../game/GamePlay/GameState/CGame_State_Logo.cpp \
	../../game/GamePlay/GameState/CGame_State_MainMenu.cpp \
	../../game/GamePlay/GameState/CGame_State_Menu.cpp \
	../../game/GamePlay/GameState/CGame_State_menu_Ingame.cpp \
	../../game/GamePlay/GameState/CGame_State_OpenBox.cpp \
	../../game/GamePlay/GameState/CGame_State_Quest.cpp \
	../../game/GamePlay/GameState/CGame_State_Wheel.cpp \
	../../game/GamePlay/GameState/CSkillNinjaStatue.cpp \
	../../game/GamePlay/GameObject/Topebox_PromoGame.cpp \
	../../game/GamePlay/MainGame/TapDefense.cpp 

	
LOCAL_SHARED_LIBRARIES := PineEngine FreeType
	
LOCAL_LDLIBS := -latomic -ldl -llog -lstdc++ -lc -lGLESv1_CM -lm -lOpenSLES -pthread -landroid
#-lGLESv1_CM  -lGLESv2
include $(BUILD_SHARED_LIBRARY)
