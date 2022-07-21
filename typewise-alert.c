#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
	BreachType breach = NORMAL;
	checkLowLimitBreach(value, lowerLimit, &breach);
	checkUpLimitBreach(value, upperLimit, &breach);
 /* if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;*/
  
}

void checkLowLimitBreach(double value, double lowerLimit, BreachType* breach)
{
	if(value < lowerLimit)
	{
		*breach = TOO_LOW;
	}
}

void checkUpLimitBreach(double value, double upperLimit, BreachType* breach)
{
        if(value > upperLimit)
        {
                *breach = TOO_HIGH;
        }
}


BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = 0;
  int upperLimit = 0;
 /* switch(coolingType) 
  {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }*/
  evaluateLimit_PASSIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  evaluateLimit_HI_ACTIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  evaluateLimit_MED_ACTIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void evaluateLimit_PASSIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit)
{
	if(coolingType == PASSIVE_COOLING)
	{
		*lowerLimit = 0;
		*upperLimit = 35;
	}
}

void evaluateLimit_HI_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit)
{
        if(coolingType == HI_ACTIVE_COOLING)
        {
                *lowerLimit = 0;
                *upperLimit = 45;
        }
}

void evaluateLimit_MED_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit)
{
        if(coolingType == MED_ACTIVE_COOLING)
        {
                *lowerLimit = 0;
                *upperLimit = 40;
        }
}


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  if(alertTarget == TO_CONTROLLER)
  {
	sendToController(breachType);
  }
  else if (alertTarget == TO_EMAIL)
  {
	sendToEmail(breachType);
  }

  /*switch(alertTarget) 
  {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }*/
}

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  switch(breachType)
  {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
