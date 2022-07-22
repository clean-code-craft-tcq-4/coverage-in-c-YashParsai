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
	char string[30];
	sprintf(string, "%x : %x\n", header, breachType);
	printString(string);
}

void sendToEmail(BreachType breachType) 
{
  	const char* recepient = "a.b@c.com";
	char string[60];
  
	  if(breachType == TOO_LOW)
	  {
		sprintf(string,"To: %s\n Hi, the temperature is too low\n",recepient);
		printString(string);
	  }
	  else if(breachType == TOO_HIGH)
	  {
		sprintf(string,"To: %s\n Hi, the temperature is too high\n",recepient);
		printString(string);
	  }
}

void printString(char* string)
{
	printf("%s",string);
}
