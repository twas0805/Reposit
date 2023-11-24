#ifndef CHESSMODE
#define CHESSMODE

#include "imode.h"
#include <array>

template<auto& ... pins>
class ChessMode : public IMode
{
public:
  void Update() override
  {
    ToggleAll();
  }
  void Clear() override
  {
    ClearAll();
    SetOdd();
  }
private:
  std::array<IPin*, sizeof ... (pins)> leds = {static_cast<IPin*> (&pins)...};
  void SetOdd()
  {
    for(int i = 1; i < leds.size(); i+=2)
    {
      leds[i]->Toggle();
    }
  }
  void ClearAll()
{
  for(auto it: leds)
  {
    it->SetLow();
  }
}
  void ToggleAll()
  {
    for(auto it: leds)
    {
      it->Toggle();
    }
  }
};

#endif