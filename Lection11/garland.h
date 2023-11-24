#ifndef GARLAND
#define GARLAND

#include "imode.h"
#include <array>

template<auto& ... modes>
class Garland
{
public:
void NextMode()
{
  pCurrentMode = mModes[i];
  pCurrentMode->Clear();
  i++;
  if(i == mModes.size())
  {
    i = 0;
  }
}
void Update()
{
  pCurrentMode->Update();
}
private:
  std::array<IMode*, sizeof ... (modes)> mModes = {static_cast<IMode*> (&modes)...};
  IMode* pCurrentMode = mModes[0];
  std::size_t i = 0;
};

#endif