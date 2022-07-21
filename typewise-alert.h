#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void checkLowLimitBreach(double value, double lowerLimit, BreachType* breach);
void checkUpLimitBreach(double value, double upperLimit, BreachType* breach);
void evaluateLimit_PASSIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
void evaluateLimit_HI_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
void evaluateLimit_MED_ACTIVE_COOLING(CoolingType coolingType, int* lowerLimit, int* upperLimit);
