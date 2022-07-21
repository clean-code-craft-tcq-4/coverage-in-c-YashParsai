#include <stdio.h>
#include "typewise-alert.h"
#include"checker.h"
BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
	BreachType breach = NORMAL;
	checkLowLimitBreach(value, lowerLimit, &breach);
	checkUpLimitBreach(value, upperLimit, &breach);
	return breach;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  	int lowerLimit = 0;
  	int upperLimit = 0;

  	evaluateLimit_PASSIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  	evaluateLimit_HI_ACTIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  	evaluateLimit_MED_ACTIVE_COOLING(coolingType, &lowerLimit, &upperLimit);
  
  	return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

bool checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
	
  	BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  	
	if(breachType != NORMAL)
	{
		sendAlert(alertTarget, breachType);
		return true;
	}
	return false;
}

void sendAlert( AlertTarget alertTarget, BreachType breachType)
{
	if(alertTarget == TO_CONTROLLER)
  	{
		sendToController(breachType);
  	}
  	else if (alertTarget == TO_EMAIL)
  	{
		sendToEmail(breachType);
  	}
}	


void sendToController(BreachType breachType) 
{
	  const unsigned short header = 0xfeed;
	  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) 
{
  	const char* recepient = "a.b@c.com";
  
	  if(breachType == TOO_LOW)
	  {
	      printf("To: %s\n", recepient);
	      printf("Hi, the temperature is too low\n");

	  }
	  else if(breachType == TOO_HIGH)
	  {
	      printf("To: %s\n", recepient);
	      printf("Hi, the temperature is too high\n");

	  }
}
