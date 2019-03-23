#include "ContentManager.h"


int main()
{
	ContentManager* contentManager = new ContentManager();
	contentManager->LoadFile("C:\\Users\\Tobenai\\Downloads\\A380\\a380.obj");
	contentManager->SaveFile();
	//contentManager->LoadFile("D:\\Dev\\Projects\\Tobes\\Tobes\\TestGame\\content\\art\\soulspear_diffuse.tga");
	//contentManager->SaveFile();
}