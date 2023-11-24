#ifndef IPIN
#define IPIN

class IPin
{
public:
  virtual void Toggle() const = 0;
  virtual void SetLow() const = 0;
};

#endif