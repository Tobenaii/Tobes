#include "ContentManager.h"


int main()
{
	ContentManager* contentManager = new ContentManager();
	contentManager->LoadFile("H:\\Dev\\Projects\\Tobes\\Tobes\\ContentPipeline\\Content\\advancedCharacter.fbx");
	contentManager->SaveFile();
}