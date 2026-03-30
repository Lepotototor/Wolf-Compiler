#include <iostream>

#include "driver/wolf_driver.hh"

int main(int argc, char** argv)
{
  driver::WolfDriver driver{argc, argv};
  driver.run();
  return 0;
}
