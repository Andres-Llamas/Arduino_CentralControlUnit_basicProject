#ifndef ButtonSystem_h
#define ButtonSystem_h
#include "Behaviours.h"
#include <Arduino.h>

class ButtonSystem
{
private:
    void OnPushedButton(int column, int row);
public:
    int _leftButtonPin, _rightButtonPin, _upButtonPin, _downButtonPin, _selectButtonPin;
    bool CheckOneButtonState(int buttonPin, bool &available, bool loop = false);
    bool CheckLeftButton(bool loop = false);
    bool CheckRightButton(bool loop = false);
    bool CheckUpButton(bool loop = false);
    bool CheckDownButton(bool loop = false);
    bool CheckSelectButton(bool loop = false);
    ButtonSystem(int leftButtonPin, int rightButtonPin, int upButtonPin, int downButtonPin, int selectButtonPin);
};
#endif