#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

/*TEST_CASE("infers the breach according to limits") 
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
*/
TEST_CASE("Classify breach according to temperature and cooling type") 
{ 
  BatteryCharacter batteryChar;
  
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
  
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 20) == NORMAL);
  
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 42) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 20) == NORMAL);
  
  
  sendToController(TOO_LOW);
  sendToEmail(TOO_LOW);
  sendToEmail(TOO_HIGH);
  batteryChar.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, batteryChar, 20);
  checkAndAlert(TO_EMAIL, batteryChar, 20);
}
