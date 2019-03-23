#pragma once

struct GLFWwindow;
#define 	KeyCode_UNKNOWN   -1
#define 	KeyCode_SPACE   32
#define 	KeyCode_APOSTROPHE   39 /* ' */
#define 	KeyCode_COMMA   44 /* , */
#define 	KeyCode_MINUS   45 /* - */
#define 	KeyCode_PERIOD   46 /* . */
#define 	KeyCode_SLASH   47 /* / */
#define 	KeyCode_0   48
#define 	KeyCode_1   49
#define 	KeyCode_2   50
#define 	KeyCode_3   51
#define 	KeyCode_4   52
#define 	KeyCode_5   53
#define 	KeyCode_6   54
#define 	KeyCode_7   55
#define 	KeyCode_8   56
#define 	KeyCode_9   57
#define 	KeyCode_SEMICOLON   59 /* ; */
#define 	KeyCode_EQUAL   61 /* = */
#define 	KeyCode_A   65
#define 	KeyCode_B   66
#define 	KeyCode_C   67
#define 	KeyCode_D   68
#define 	KeyCode_E   69
#define 	KeyCode_F   70
#define 	KeyCode_G   71
#define 	KeyCode_H   72
#define 	KeyCode_I   73
#define 	KeyCode_J   74
#define 	KeyCode_K   75
#define 	KeyCode_L   76
#define 	KeyCode_M   77
#define 	KeyCode_N   78
#define 	KeyCode_O   79
#define 	KeyCode_P   80
#define 	KeyCode_Q   81
#define 	KeyCode_R   82
#define 	KeyCode_S   83
#define 	KeyCode_T   84
#define 	KeyCode_U   85
#define 	KeyCode_V   86
#define 	KeyCode_W   87
#define 	KeyCode_X   88
#define 	KeyCode_Y   89
#define 	KeyCode_Z   90
#define 	KeyCode_LEFT_BRACKET   91 /* [ */
#define 	KeyCode_BACKSLASH   92 /* \ */
#define 	KeyCode_RIGHT_BRACKET   93 /* ] */
#define 	KeyCode_GRAVE_ACCENT   96 /* ` */
#define 	KeyCode_WORLD_1   161 /* non-US #1 */
#define 	KeyCode_WORLD_2   162 /* non-US #2 */
#define 	KeyCode_ESCAPE   256
#define 	KeyCode_ENTER   257
#define 	KeyCode_TAB   258
#define 	KeyCode_BACKSPACE   259
#define 	KeyCode_INSERT   260
#define 	KeyCode_DELETE   261
#define 	KeyCode_RIGHT   262
#define 	KeyCode_LEFT   263
#define 	KeyCode_DOWN   264
#define 	KeyCode_UP   265
#define 	KeyCode_PAGE_UP   266
#define 	KeyCode_PAGE_DOWN   267
#define 	KeyCode_HOME   268
#define 	KeyCode_END   269
#define 	KeyCode_CAPS_LOCK   280
#define 	KeyCode_SCROLL_LOCK   281
#define 	KeyCode_NUM_LOCK   282
#define 	KeyCode_PRINT_SCREEN   283
#define 	KeyCode_PAUSE   284
#define 	KeyCode_F1   290
#define 	KeyCode_F2   291
#define 	KeyCode_F3   292
#define 	KeyCode_F4   293
#define 	KeyCode_F5   294
#define 	KeyCode_F6   295
#define 	KeyCode_F7   296
#define 	KeyCode_F8   297
#define 	KeyCode_F9   298
#define 	KeyCode_F10   299
#define 	KeyCode_F11   300
#define 	KeyCode_F12   301
#define 	KeyCode_F13   302
#define 	KeyCode_F14   303
#define 	KeyCode_F15   304
#define 	KeyCode_F16   305
#define 	KeyCode_F17   306
#define 	KeyCode_F18   307
#define 	KeyCode_F19   308
#define 	KeyCode_F20   309
#define 	KeyCode_F21   310
#define 	KeyCode_F22   311
#define 	KeyCode_F23   312
#define 	KeyCode_F24   313
#define 	KeyCode_F25   314
#define 	KeyCode_KP_0   320
#define 	KeyCode_KP_1   321
#define 	KeyCode_KP_2   322
#define 	KeyCode_KP_3   323
#define 	KeyCode_KP_4   324
#define 	KeyCode_KP_5   325
#define 	KeyCode_KP_6   326
#define 	KeyCode_KP_7   327
#define 	KeyCode_KP_8   328
#define 	KeyCode_KP_9   329
#define 	KeyCode_KP_DECIMAL   330
#define 	KeyCode_KP_DIVIDE   331
#define 	KeyCode_KP_MULTIPLY   332
#define 	KeyCode_KP_SUBTRACT   333
#define 	KeyCode_KP_ADD   334
#define 	KeyCode_KP_ENTER   335
#define 	KeyCode_KP_EQUAL   336
#define 	KeyCode_LEFT_SHIFT   340
#define 	KeyCode_LEFT_CONTROL   341
#define 	KeyCode_LEFT_ALT   342
#define 	KeyCode_LEFT_SUPER   343
#define 	KeyCode_RIGHT_SHIFT   344
#define 	KeyCode_RIGHT_CONTROL   345
#define 	KeyCode_RIGHT_ALT   346
#define 	KeyCode_RIGHT_SUPER   347
#define 	KeyCode_MENU   348
#define 	KeyCode_LAST   GLFW_KEY_MENU

#include "Tobes/Core.h"

class TOBES_API Input
{
public:
	static Input* GetInstance();
	bool IsKeyDown(int key);
	bool WasKeyPressed(int key);
	double GetMouseDeltaX();
	double GetMouseDeltaY();
	void Clear();

private:
	Input();

private:
	static Input* m_instance;
	int* m_curKeys;
	int* m_prevKeys;

	bool m_mouseEntered;
	bool m_firstMouseMove;

	double m_mouseX;
	double m_prevMouseX;
	double m_mouseY;
	double m_prevMouseY;
};