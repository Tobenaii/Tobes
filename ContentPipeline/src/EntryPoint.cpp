#include "ContentManager.h"


int main()
{
	ContentManager* contentManager = new ContentManager();
	contentManager->LoadFile("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\art\\lambo.fbx");
	contentManager->SaveFile();
	//contentManager->LoadFile("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\art\\soulspear_diffuse.tga");
	//contentManager->SaveFile();
}