#include "GUI.h"
#include <LiquidCrystal.h>
#include <Wire.h>
#include <math.h>

int _rs, _en, _d4, _d5, _d6, _d7;
int ScreenPowerLightPin;
const int menuSize = 5;
const int submenuSize = 5;
int GUI::currentLevelInMenu = 1; // this is the maximum index of mainCategories that can be printed out
int GUI::currentMenuIndex = 0;
int GUI::currentRowIndex = 0;

LiquidCrystal _lcd(_rs, _en, _d4, _d5, _d6, _d7);
String menus[menuSize][submenuSize] = {
    {"Turn on lights", "Check plants", "Turn off Screen ", "Options", "-"}, // Main menu
    {"Back"},                                                          // Make music menu
    {"Back"},                                                          // place holder menu (to be replaced in the future)
    {"Back"},                                                          // place holder menu (to be replaced in the future)
    {"Back"}                                                           // Options menu
};
void UpdateMainMenu(int row);
void MainMenu();
// Constructor
GUI::GUI(int rs, int en, int d4, int d5, int d6, int d7, int powerPin)
{
    _rs = rs;
    _en = en;
    _d4 = d4;
    _d5 = d5;
    _d6 = d6;
    _d7 = d7;
    LiquidCrystal lcd(_rs, _en, _d4, _d5, _d6, _d7);
    _lcd = lcd;
    ScreenPowerLightPin = powerPin;
}

void GUI::Initialize()
{
    _lcd.begin(16, 2);
    _lcd.print("Hello master!!");
    delay(1500);
    _lcd.clear();
    GUI::ToMainMenu();
}

void GUI::ToMainMenu()
{
    GUI::currentMenuIndex = 0;
    GUI::currentRowIndex = 0;
    UpdateMainMenu(0);
}

void GUI::UpdateScreen(int column, int row)
{
    switch (currentMenuIndex)
    {
    case 0:
        UpdateMainMenu(row);
        break;
    default:
        break;
    }
}

void UpdateMainMenu(int row)
{
    GUI::currentLevelInMenu -= row; // is - because to go down is resting -1, meaning the menu level is increasing to down
    _lcd.blink();
    if (GUI::currentLevelInMenu >= 1)
    {
        if (GUI::currentLevelInMenu < submenuSize)
        {
            _lcd.clear();
            _lcd.setCursor(1, 0);
            _lcd.print(menus[0][GUI::currentLevelInMenu - 1]); // to print out the last category of the next in order to have two categories in screen
            _lcd.setCursor(1, 1);
            _lcd.print(menus[0][GUI::currentLevelInMenu]);
            _lcd.home();
            GUI::currentRowIndex -= row;
        }
        else
        {
            GUI::currentRowIndex = submenuSize - 1;
            GUI::currentLevelInMenu = submenuSize - 1;
        }
    }
    else
    {
        GUI::currentRowIndex = 0;
        GUI::currentLevelInMenu = 1;
    }    
}

void GUI::PowerOffScreen()
{
    _lcd.noDisplay();  
    _lcd.off();      
    digitalWrite(ScreenPowerLightPin, LOW);
}
void GUI::PowerOnScreen()
{
    _lcd.display();
    _lcd.on();        
    digitalWrite(ScreenPowerLightPin, HIGH);
}