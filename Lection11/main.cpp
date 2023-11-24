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

AllMode<pin1, pin2, pin3, pin4> all; //Создание объекта класса режим "все"
TreeMode<pin1, pin2, pin3, pin4> el; //Создание объекта класса режим "елочки"
ChessMode<pin1, pin2, pin3, pin4> chess; //Создание объекта класса шахматный режим
Garland<all, el, chess> garland; //Создание объекта класса гирлянда

int main()
{
  RCC::AHB1ENR::GPIOAEN::Enable::Set(); //Подача тактирования на порт A
  RCC::AHB1ENR::GPIOCEN::Enable::Set(); //Подача тактирования на порт C
  //GPIOC::MODER::MODER13::Input::Set(); //Порт C.13 на ввод
  GPIOA::MODER::MODER5::Output::Set(); //Порт A.5 на вывод
  GPIOC::MODER::MODER5::Output::Set(); //Порт С.5 на вывод
  GPIOC::MODER::MODER8::Output::Set(); //Порт С.8 на вывод
  GPIOC::MODER::MODER9::Output::Set(); //Порт С.9 на вывод

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