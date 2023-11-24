#ifndef TREEMODE
#define TREEMODE

#include "imode.h"
#include <array>

template<auto& ... pins>
class TreeMode : public IMode
{
public:
void Update() override
{  
  leds[i++]->Toggle();
  if(i == leds.size())
  {
    i = 0;
  }
}
void Clear() override
{
  i=0;
  ClearAll();
}
private:
  std::size_t i = 0;
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