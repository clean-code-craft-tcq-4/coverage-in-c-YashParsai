#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "checker.h"

TEST_CASE("Test checkAndAlert functionality")
{
    BatteryCharacter batteryChar;

    batteryChar.coolingType = PASSIVE_COOLING;
    REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,-1) == 1);
    REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,20) == 0);
    REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar,36) == 1);

    batteryChar.coolingType = HI_ACTIVE_COOLING;
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,-1) == 1);
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,20) == 0);
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,46) == 1);

    batteryChar.coolingType = MED_ACTIVE_COOLING;
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,-1) == 1);
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,20) == 0);
    REQUIRE(checkAndAlert(TO_EMAIL, batteryChar,42) == 1);
 }
