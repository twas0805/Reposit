#ifndef ALLMODE
#define ALLMODE

#include "imode.h"
#include <array>

template<auto& ... pins>
class AllMode : public IMode
{
public:
void Update() override
{  
  for(auto it: leds)
  {
    it->Toggle();
  }
}

void Clear() override
{
  ClearAll();
}
private:
  std::array<IPin*, sizeof ... (pins)> leds = {static_cast<IPin*> (&pins)...};
  void ClearAll()
{
  for(auto it: leds)
  {
    it->SetLow();
  }
}
};

#endif