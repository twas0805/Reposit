#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIOC
#include "pin.h"
#include "treemode.h"
#include "chessmode.h"
#include "allmode.h"
#include "garland.h"
#include "button.h"

std::uint32_t SystemCoreClock = 16'000'000U;

void delay(int cycles)
{
  for(int i = 0; i < cycles; ++i)    
  {   
    asm volatile("");
  }    
}

Pin<GPIOC, 5> pin1;
Pin<GPIOC, 8> pin2;
Pin<GPIOC, 9> pin3;
Pin<GPIOA, 5> pin4;

Button<GPIOC, 13> btn;

AllMode<pin1, pin2, pin3, pin4> all; //�������� ������� ������ ����� "���"
TreeMode<pin1, pin2, pin3, pin4> el; //�������� ������� ������ ����� "������"
ChessMode<pin1, pin2, pin3, pin4> chess; //�������� ������� ������ ��������� �����
Garland<all, el, chess> garland; //�������� ������� ������ ��������

int main()
{
  RCC::AHB1ENR::GPIOAEN::Enable::Set(); //������ ������������ �� ���� A
  RCC::AHB1ENR::GPIOCEN::Enable::Set(); //������ ������������ �� ���� C
  //GPIOC::MODER::MODER13::Input::Set(); //���� C.13 �� ����
  GPIOA::MODER::MODER5::Output::Set(); //���� A.5 �� �����
  GPIOC::MODER::MODER5::Output::Set(); //���� �.5 �� �����
  GPIOC::MODER::MODER8::Output::Set(); //���� �.8 �� �����
  GPIOC::MODER::MODER9::Output::Set(); //���� �.9 �� �����

  for(;;)
  { 
    garland.Update();
    if(btn.IsPressed())
    {
      garland.NextMode();
    }
    delay(1000000);
  }
  
  return 1;
}