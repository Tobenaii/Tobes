#include "ContentManager.h"


int main()
{
	ContentManager* contentManager = new ContentManager();
	contentManager->LoadFile("C:\\Users\\Tobenai\\Downloads\\soulspear\\soulspear\\soulspear.obj");
	contentManager->SaveFile();
}