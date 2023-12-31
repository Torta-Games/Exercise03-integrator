#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool hit = false;
	double angle = -45.0f;

private:
	SDL_Texture* platform;
	SDL_Texture* enemy;
	SDL_Texture* enemyDead;
	SDL_Texture* cannon;
	float textPosX, textPosY = 0;
	uint texW, texH;
	uint windowW, windowH;

	//L03: TODO 3b: Declare a Player attribute

};

#endif // __SCENE_H__