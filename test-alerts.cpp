#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

int dummy_temp[3][3] = { {-1,5,36}, {-2,13,47}, {-3,40,45} };

TEST_CASE("Test Check and Alert") 
{
  test_checkAndAlert();
}

void test_checkAndAlert(void)
{
  AlertTarget       alertTarget;
  BatteryCharacter  batteryChar;
  double            temperatureInC;
  CoolingType       coolType;
  int               ii, jj;
  
  batteryChar.brand = "BOSCH";
  alertTarget = TO_MAIL;
  for(ii=0; ii < coolType.MED_ACTIVE_COOLING; ii++)
  {
    batteryChar.coolingType =   ii;
    for(jj=0; jj < 3; jj++)
    {
      temperatureInc = dummy_temp[ii][jj];
      checkAndAlert(alertTarget, batteryChar, temperatureInc);
    }
  }
}
