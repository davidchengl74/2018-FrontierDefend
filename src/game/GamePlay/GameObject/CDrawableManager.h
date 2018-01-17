#if !_DRAWABLE_MANAGER_H
#define _DRAWABLE_MANAGER_H (1)
#define DRAWABLE_POOL_MAX (600)
#define DRAWABLE_TYPE_NORMAL			0
#define DRAWABLE_TYPE_BEHIT				1
#define DRAWABLE_TYPE_BESKILL_ICE		2
#define DRAWABLE_TYPE_BESKILL_BURN		3


class CAnimObject;
class CDrawableManager
{
	CAnimObject* _anim_list_static[DRAWABLE_POOL_MAX];
	float _posX[DRAWABLE_POOL_MAX];
	float _posY[DRAWABLE_POOL_MAX];
	int _ids[DRAWABLE_POOL_MAX];
	int _type[DRAWABLE_POOL_MAX];
	int _rotate[DRAWABLE_POOL_MAX];
    float _scale[DRAWABLE_POOL_MAX];
	int _num;
public: 
	
	void Add(CAnimObject* object, float posX, float posY, int type, int rotate,float size=1.0);
	void Update();
	void Render(float x,float y,int type);
	void Init();
};


#endif
