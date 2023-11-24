#ifndef BUTTON
#define BUTTON

#include "ibutton.h"
#include <array>

template<typename Port, int pinNumber>
class Button : public IButton
{
public:
bool IsPressed() override
{
  if(((Port::IDR::Get()&(1 << pinNumber))==0) && (isSet))
  {
    isSet = false;
  } else if(((Port::IDR::Get()&(1 << pinNumber))==(1 << pinNumber)) && (!isSet))
  {
    isSet = true;
    return true;
  }
  return 0;
}
private:
  bool isSet = true;
};

#endif