#ifndef PIN
#define PIN

#include "ipin.h"

template<typename Port, int pinNumber>
class Pin : public IPin
{
public:
void Toggle() const override
{
  Port::ODR::Toggle(1 << pinNumber);  
}
void SetLow() const override
{
  Port::ODR::Write(Port::ODR::Get() & ~(1 << pinNumber));
}
};

#endif
