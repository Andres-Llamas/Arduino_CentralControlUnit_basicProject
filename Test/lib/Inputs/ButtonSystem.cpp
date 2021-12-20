#include "ButtonSystem.h"

bool canPushLeft = true, canPushRight = true, canPushUp = true, canPushDown = true, canPushSelect = true;
int currentState;
int holdingButtonDelay = 500;
/**
 * Constructor
 * Just enter the button pins
 */
ButtonSystem::ButtonSystem(int leftButtonPin, int rightButtonPin, int upButtonPin, int downButtonPin, int selectButtonPin)
{
  _leftButtonPin = leftButtonPin;
  _rightButtonPin = rightButtonPin;
  _upButtonPin = upButtonPin;
  _downButtonPin = downButtonPin;
  _selectButtonPin = selectButtonPin;
};

bool ButtonSystem::CheckOneButtonState(int buttonPin, bool &available, bool loop)
{
  currentState = digitalRead(buttonPin);
  if (loop) // to pass several inputs when holding button down
  {
    if (currentState == LOW) //pushing button
    {
      if (available) // to first pass the input before start looping;
      {
        available = false;
        return true;
      }
      delay(holdingButtonDelay);
      currentState = digitalRead(buttonPin);
      if (currentState == LOW) // check if user is still holding the button
      {
        return true;
      }
    }

    available = true;
    return false;
  }
  else // to avoid receive several inputs when holding button down
  {
    if (currentState == LOW) //pushing button
    {
      if (available)
      {
        available = false;
        return true;
      }
    }
    else
    {
      available = true;
    }
    return false;
  }
}

bool ButtonSystem::CheckLeftButton(bool loop)
{
  if (CheckOneButtonState(_leftButtonPin, canPushLeft, loop))
  {
    OnPushedButton(-1, 0); // move left
    return true;
  }
  return false;
}
bool ButtonSystem::CheckRightButton(bool loop)
{
  if (CheckOneButtonState(_rightButtonPin, canPushRight, loop))
  {
    OnPushedButton(1, 0); // move right
    return true;
  }
  return false;
}
bool ButtonSystem::CheckUpButton(bool loop)
{
  if (CheckOneButtonState(_upButtonPin, canPushUp, loop))
  {
    OnPushedButton(0, 1); // move up 1
    return true;
  }
  return false;
}
bool ButtonSystem::CheckDownButton(bool loop)
{
  if (CheckOneButtonState(_downButtonPin, canPushDown, loop))
  {
    OnPushedButton(0, -1); // move down 1
    return true;
  }
  return false;
}
bool ButtonSystem::CheckSelectButton(bool loop)
{
  if (CheckOneButtonState(_selectButtonPin, canPushSelect, loop))
  {
    Behaviours::OnSelectButton();
    delay(200);
    return true;
  }
  return false;
}

void ButtonSystem::OnPushedButton(int column, int row)
{  
  GUI::UpdateScreen(column, row);
}