#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

void test_checkAndAlert(void);

int dummy_temp[3][3] = { {-1,5,36}, {-2,13,47}, {-3,40,45} };

TEST_CASE("Test Check and Alert") 
{
  test_checkAndAlert();
}

void test_checkAndAlert(void)
{
  AlertTarget       alertTarget;
  BatteryCharacter  batteryChar;
  double            temperatureInc;
  CoolingType       coolType;
  int               ii, jj;
  
  strcpy(batteryChar.brand, "BOSCH");
  alertTarget = TO_EMAIL;
  for(ii=0; ii <= MED_ACTIVE_COOLING; ii++)
  {
    batteryChar.coolingType =   ii;
    for(jj=0; jj < 3; jj++)
    {
      temperatureInc = dummy_temp[(int)coolType][jj];
      checkAndAlert(alertTarget, batteryChar, temperatureInc);
    }
  }
}
