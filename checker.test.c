#include<stdio.h>
#include"typewise-alert.h"
#include"checker.h"

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
