#ifndef GUI_h
#define GUI_h
#include "ButtonSystem.h"
#include <Arduino.h>

class GUI
{
private:
    void ToMainMenu();

public:
    static int currentMenuIndex; // for selection of categories trough Behaviours.cpp
    static int currentRowIndex;
    static int currentLevelInMenu; // this is the maximum index range to print out in the screen
    GUI(int rs, int en, int d4, int d5, int d6, int d7, int powerPin);
    void Initialize();
    static void UpdateScreen(int column, int row);
    static void PowerOnScreen();
    static void PowerOffScreen();
};
#endif