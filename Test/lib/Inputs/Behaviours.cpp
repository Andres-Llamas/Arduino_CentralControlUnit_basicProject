#include "Behaviours.h"

int _relayForLightsPin;
bool isScreenOn = true;
bool canCheck_On_Off_ScreenStatus = true; // to being able to turn screen off in the next switch iteration in order to avoid it occur immediately

Behaviours::Behaviours(int relayForLights)
{
    _relayForLightsPin = relayForLights;
}

void Behaviours::OnSelectButton()
{
    if (isScreenOn == false)
    {
        Turn_Off_On_Screen(true);
        canCheck_On_Off_ScreenStatus = false;
    }
    switch (GUI::currentMenuIndex)
    {
    case 0: // main menu
        switch (GUI::currentRowIndex)
        {
        case 0: // first option
            TurnOnLights();
            break;
        case 2: // second option
            if (canCheck_On_Off_ScreenStatus)
            {
                Turn_Off_On_Screen(false);
            }
        default:
            break;
        }
        break;

    default:
        break;
    }
    canCheck_On_Off_ScreenStatus = true;
}

void Behaviours::TurnOnLights()
{
    int lightsState = digitalRead(_relayForLightsPin);
    if (lightsState == HIGH)
        digitalWrite(_relayForLightsPin, LOW);
    else
        digitalWrite(_relayForLightsPin, HIGH);
}

void Behaviours::Turn_Off_On_Screen(bool turnOn)
{
    if (turnOn)
    {
        GUI::PowerOnScreen();
        isScreenOn = true;
    }
    else
    {
        GUI::PowerOffScreen();
        isScreenOn = false;
    }
}