#include<stdio.h>
#include"typewise-alert.h"

void checkLowLimitBreach(double value, double lowerLimit, BreachType* breach);
void checkUpLimitBreach(double value, double upperLimit, BreachType* breach);
void evaluateLimit_PASSIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
void evaluateLimit_HI_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
void evaluateLimit_MED_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
