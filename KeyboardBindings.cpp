#include "KeyboardBindings.h"

KeyboardBindings::KeyboardBindings()
{
	initKeyBoard();
}

int KeyboardBindings::GetKey(std::string keyTitle)
{
	return KeyBoardMap[keyTitle];
}

void KeyboardBindings::UpdateKeys()
{
	BindReader binds;
	binds.UpdateCfg(KeyBoardMap, BindTitle);
}

void KeyboardBindings::initKeyBoard()
{
	BindReader binds;
	binds.ReadCfg(&KeyBoardMap, BindTitle);
}
