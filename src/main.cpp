#include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>
#include "MyOCPPImplementation.h"
#include "MyArduinoWebsocketsAdapter.h"
#include "OCPPCore.h"
#include "MyRequestHandlerRepository.h"
#include "SentMessageRepository.h"
//#include "core/OCPP.h"
#include "HeapDebug.h"

MyRequestHandlerRepository *reqHandlerRepoPtr = new MyRequestHandlerRepository;
SentMessageRepository *sentMessageRepoPtr = new SentMessageRepository;

//"gergelyszalay.hu"
WebsocketServerAddress wsAddress("192.168.1.74", 3000, "/fromdevice", "ocpp2.0.1");

OCPPEventHandlers *eventHandlersPtr = new OCPPEventHandlers(sentMessageRepoPtr, reqHandlerRepoPtr);

MyArduinoWebsocketsAdapter *myWsAdapterPtr = new MyArduinoWebsocketsAdapter(wsAddress, eventHandlersPtr);

MyOCPPImplementation *myOCPPImplementationPtr = new MyOCPPImplementation(myWsAdapterPtr, sentMessageRepoPtr, reqHandlerRepoPtr);

OCPPCore OCPP(myOCPPImplementationPtr, myWsAdapterPtr);


void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);

  OCPP.setup();
}

void loop()
{
  DEBUG_LN_HEAP(2000);
  OCPP.loop();
}