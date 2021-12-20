#ifndef Behaviours_h
#define Behaviours_h
#include "GUI.h"
class Behaviours
{
private:
    static void TurnOnLights();
    static void Turn_Off_On_Screen(bool turnOn);
public:
    static void OnSelectButton();
    Behaviours(int relayForLights);
};
#endif