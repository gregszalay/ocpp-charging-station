#include <Arduino.h>
#include "MemoryCheck.h"
#include "FS.h"
#include <LITTLEFS.h>
#include "MyOCPPImplementation.h"
#include "MyArduinoWebsocketsAdapter.h"
#include "OCPPCore.h"
#include "MyRequestHandlerRepository.h"
#include "SentMessageRepository.h"
//#include "core/OCPP.h"

// This needs to be the first object created!
static MemoryCheck MEMORY_CHECK;

MyRequestHandlerRepository *reqHandlerRepoPtr = new MyRequestHandlerRepository;
SentMessageRepository *sentMessageRepoPtr = new SentMessageRepository;

WebsocketServerAddress wsAddress("gergelyszalay.hu", 3000, "/echo", "ocpp2.0.1");

OCPPEventHandlers *eventHandlersPtr = new OCPPEventHandlers(sentMessageRepoPtr, reqHandlerRepoPtr);
/* MemoryCheck::newnew(); */

MyArduinoWebsocketsAdapter *myWsAdapterPtr = new MyArduinoWebsocketsAdapter(wsAddress, eventHandlersPtr);
/* MemoryCheck::newnew(); */

MyOCPPImplementation *myOCPPImplementationPtr = new MyOCPPImplementation(myWsAdapterPtr, sentMessageRepoPtr, reqHandlerRepoPtr);
/* MemoryCheck::newnew(); */

OCPPCore OCPP(myOCPPImplementationPtr, myWsAdapterPtr);

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  OCPP.setup();
}

void loop()
{
  OCPP.loop();
}