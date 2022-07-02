#pragma once
#include <Arduino.h>
#include "MemoryCheck.h"
#include <ArduinoJson.h>
#include <ESPRandom.h>
#include "MESSAGE.h"

class CALL_Message : public MESSAGE
{
protected:
  String action;

public:
  void buildFrame();
  CALL_Message(String _action);
  String getAction() const;

};
