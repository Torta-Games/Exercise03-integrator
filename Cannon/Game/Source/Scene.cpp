#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Player.h"

#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	//L03: TODO 3b: Instantiate the player using the entity manager
	app->entityManager->CreateEntity(EntityType::PLAYER);

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	// NOTE: We have to avoid the use of paths in the code, we will move it later to a config file
	platform = app->tex->Load("Assets/Textures/wood.png");
	enemy = app->tex->Load("Assets/Textures/dwarfAlive.png");
	enemyDead = app->tex->Load("Assets/Textures/dwarfDead.png");
	cannon = app->tex->Load("Assets/Textures/canon.png");
	
	//Music is commented so that you can add your own music
	//app->audio->PlayMusic("Assets/Audio/Music/music_spy.ogg");

	//Get the size of the window
	app->win->GetWindowSize(windowW, windowH);

	//Get the size of the texture
	/*app->tex->GetSize(img, texW, texH);*/

	textPosX = (float)windowW / 2 - (float)texW / 2;
	textPosY = (float)windowH / 2 - (float)texH / 2;

	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	Player player;
	//L02 DONE 3: Make the camera movement independent of framerate
	float camSpeed = 1; 

	//if(app->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	//	app->render->camera.y -= (int)ceil(camSpeed * dt);

	//if(app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	//	app->render->camera.y += (int)ceil(camSpeed * dt);

	//if(app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	//	app->render->camera.x -= (int)ceil(camSpeed * dt);

	//if(app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	//	app->render->camera.x += (int)ceil(camSpeed * dt);

	// Renders the image in the center of the screen 
	app->render->DrawTexture(platform, -140, 330 + 100);
	app->render->DrawTexture(platform, 260, 400 + 100);
	app->render->DrawTexture(platform, 560, 400 + 100);
	app->render->DrawTexture(platform, 860, 400 + 100);
	app->render->DrawTexture(platform, 1160, 400 + 100);

	app->render->DrawTexture(platform, 460, 70 + 100);

	if (!hit)app->render->DrawTexture(enemy, 600, 275 + 100);
	else app->render->DrawTexture(enemyDead, 530, 275 + 100);

	app->render->DrawTexture(cannon, 0, 300 + 100, NULL, 1.0f, angle, 30,30);

	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
