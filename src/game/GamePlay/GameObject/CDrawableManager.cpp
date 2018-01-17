#include "pch.h"
#include "../../GameCore/CGame.h"

void CDrawableManager::Add(CAnimObject* object, float posX, float posY,int type,int rotate,float size)
{
	_anim_list_static[_num] = object;
	_type[_num] = type;
	_rotate[_num] = rotate;
	_posX[_num] = posX;
	_posY[_num] = posY;
    _scale[_num] = size;
	int index = _num;
	for(int i = 0; i < _num; i++)
	{
		int node = _ids[i];
		if(posY < _posY[node])
		{
            index = i;
			if(!(_posY[node] == posY && _posX[node] < posX))
			{
				index = i;
				break;
			}
		}
	}
	//printf("\n type[%d] = %d",_num, type);
	for(int i = _num-1; i >= index; i--)
	{
		_ids[i+1] = _ids[i];
		
	}
	_ids[index] = _num;
	_num++;
	
}
void CDrawableManager::Update()
{
}
void CDrawableManager::Render(float x, float y, int type)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	float posX = 0;
	float posY = 0;
	int index = 0;
	//printf("\n_num  = %d",_num);
	for(int i = 0; i < _num; i++)
	{
		 index = _ids[i];
		 posX = _posX[index] + x;
		 posY = _posY[index] + y;
		 _anim_list_static[index]->SetPos(posX, posY);
		 int mposx = 0;
		 int mposy = -144;
		 int frame_index = _anim_list_static[index]->_anim_sprite->_aframe_id[_anim_list_static[index]->_current_aframes];
		 mposx = _anim_list_static[index]->_anim_sprite->GetFModuleCenterX(frame_index, 0);
		 mposy = _anim_list_static[index]->_anim_sprite->GetFModuleCenterY(frame_index, 0);
		 int spriteid = _anim_list_static[index]->_intdexSprite;
        G()->SetScale(_scale[index], _scale[index], posX, posY);
		 for (int i = 0; i < NUM_MAX_HERO; i++)
		 {
			 switch (game->_effect_hero_skill_id[i])
			 {
			 case HERO_SKILL_GREATCLASH:
				 /*if (spriteid == SPRITEID_EFFECT_SKILL_SWORDMAN_01 || spriteid == SPRITEID_HERO_SWORDSMAN_01)
				 {
					 G()->SetScale(game->_effect_hero_skill_scale[i], game->_effect_hero_skill_scale[i], posX, posY);
				 }*/
				 break;
			 case HERO_SKILL_WOLF_RANGER:
				 if (spriteid == SPRITEID_EFFECT_SKILL_WOLFGIRL_01 || spriteid == SPRITEID_HERO_WOLFGIRL_01)
				 {
					 G()->SetScale(game->_effect_hero_skill_scale[i]*_scale[index], game->_effect_hero_skill_scale[i]*_scale[index], posX, posY);
				 }
				 break;
			 default:
				 break;
			 }
		 }
		 G()->SetRotate(_rotate[index], posX, posY);
        //G()->SetScale(_scale[index], _scale[index], posX, posY);
		 _anim_list_static[index]->DrawAnimObject(G());
        G()->ClearScale();
		 G()->ClearRotate();
		G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
		 switch (_type[index])
		 {
		 case DRAWABLE_TYPE_BEHIT:
		 {
				/*CAnimObject *_anim_effect;
				_anim_effect = _anim_list_static[index];
				G()->SetColorMask(0x90ff0000);
				_anim_effect->SetPos(posX, posY);
				_anim_effect->DrawAnimObject(G());
				G()->ClearColorMask();*/
		 }
			 break;
		 case DRAWABLE_TYPE_BESKILL_ICE:
		 {
				CAnimObject *_anim_effect;
				_anim_effect = _anim_list_static[index];
				//G()->SetScale(_scale[index], _scale[index], posX, posY);
				G()->SetColorMask(0xff009966);
				_anim_effect->SetPos(posX, posY);
				_anim_effect->DrawAnimObject(G());
				G()->ClearColorMask();
				//G()->ClearScale();
		 }
			 break;
		 default:
			 break;
		 }
		 G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
		 G()->ClearScale();

	}
}
void CDrawableManager::Init()
{
	_num = 0;
}
