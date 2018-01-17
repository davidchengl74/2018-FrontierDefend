/**
*	will be included in CGame.h
*	for include specific *.h
*/
//#include "some_classes.h"

#include "../GamePlay/GameObject/MenuSystem.h"
#include "../GamePlay/GameObject/SpriteList.h"
#include "../GamePlay/GameObject/WorldGame.h"
#include "../GamePlay/GameObject/Jumper.h"

#include "../Lib/PineHighScore.h"
#include "../Lib/DataType/BufferStream.h"

#include "../Lib/PineAdBox.h"
#include "../Lib/PineStore.h"

//include game object
#include "../GamePlay/MainGame/CGame_TD_Define_Const.h"
#include "../GamePlay/MainGame/CGame_Support_Config.h"
#include "../GamePlay/GameObject/GameDesign.h"
#include "../GamePlay/GameObject/CMaxtrix4x4Util.h"
#include "../GamePlay/GameObject/CEffectShadow.h"
#include "../GamePlay/GameObject/CEffectFire.h"
#include "../GamePlay/GameObject/CEffectFireUp.h"
#include "../GamePlay/GameObject/CThrowObject.h"
#include "../GamePlay/GameObject/CPartical.h"
#include "../GamePlay/GameObject/Pine_Date_Time.h"
#include "../GamePlay/GameObject/Topebox_PromoGame.h"
#if !defined (ANDROID_OS)
#include "../GamePlay/GameObject/CServerThread.h"
#endif

#include "../GamePlay/GameObject/CDialog.h"
#include "../GamePlay/GameObject/CDialogManager.h"

#include "../GamePlay/GameObject/CWeapon.h"
#include "../GamePlay/GameObject/CCastle.h"
#include "../GamePlay/GameObject/CCharacter.h"
#include "../GamePlay/GameObject/CBulletAttack.h"
#include "../GamePlay/GameObject/CSkillRainShower.h"
#include "../GamePlay/GameState/CSkillNinjaStatue.h"
#include "../GamePlay/GameObject/CSkillBeastMaster.h"
#include "../GamePlay/GameObject/CSkillWordFlash.h"
#include "../GamePlay/GameObject/CSkillSanta.h"
#include "../GamePlay/GameObject/CSkillAcid.h"
#include "../GamePlay/GameObject/CSkillRobo.h"
#include "../GamePlay/GameObject/CBird.h"
#include "../GamePlay/GameObject/CSkill.h"


#include "../GamePlay/GameObject/CHero.h"
#include "../GamePlay/GameObject/CDrawableManager.h"
#include "../GamePlay/GameObject/CScrollBar.h"
#include "../GamePlay/GameObject/CUser.h"
#include "../GamePlay/GameObject/EffectScrollNumber.h"
#include "../GamePlay/GameObject/CEffectNotify.h"
#include "GameObject/EffectItemFly.h"
#include "GameObject/CQuest.h"
#include "../GamePlay/GameObject/CItemRelic.h"
#include "../GamePlay/GameObject/ItemBox.h"
#include "../GamePlay/GameObject/CGiftBox.h"
#include "../GamePlay/GameObject/CPushNotification.h"

#include "../GamePlay/MainGame/TapDefense.h"

//include main game
#if defined (ANDROID_OS)
#include "../GamePlay/GameObject/CAsyncTasks.h"
#include "../Lib/PineTapdaqAsync.h"
#include "../Lib/PineUnityAdsAsync.h"
#endif
