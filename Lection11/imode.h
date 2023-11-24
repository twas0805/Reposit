#ifndef IMODE
#define IMODE

class IMode
{
public:
  virtual void Update() = 0;
  virtual void Clear() = 0;
};

#endif