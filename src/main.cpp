#include <Arduino.h>
#include "FS.h"
#include <LITTLEFS.h>
#include "MyOCPPImplementation.h"
#include "MyArduinoWebsocketsAdapter.h"
#include "OCPPCore.h"
#include "MyRequestHandlerRepository.h"
#include "SentMessageRepository.h"
#include "HeapDebug.h"
#include "PRIVATE.h"

// Create connection address
String connectionURL = String(URL) + String("/") + String(STATION_ID);
WebsocketServerAddress wsAddress(HOST, PORT, connectionURL, OCPP_VERSION);

// We store the default callback for each message here
// You can define the callbacks in 2 places:
// - the MyRequestHandlerRepository.cpp file
// - at the creation of each message, in the constructor of each message
MyRequestHandlerRepository *reqHandlerRepoPtr = new MyRequestHandlerRepository;

// For storing messages that are waiting for a reply from the CSMS
SentMessageRepository *sentMessageRepoPtr = new SentMessageRepository;

// Create the message handling implementation
OCPPEventHandlers *eventHandlersPtr = new OCPPEventHandlers(sentMessageRepoPtr, reqHandlerRepoPtr);

// Create the OCPP websocket class, inject the message handler implementation as a dependency
MyArduinoWebsocketsAdapter *myWsAdapterPtr = new MyArduinoWebsocketsAdapter(wsAddress, eventHandlersPtr);

// This is where we define the main communication loop and create messages
MyOCPPImplementation *myOCPPImplementationPtr = new MyOCPPImplementation(myWsAdapterPtr, sentMessageRepoPtr, reqHandlerRepoPtr);

// Put all of the above into one class
OCPPCore OCPP(myOCPPImplementationPtr, myWsAdapterPtr);

void setup()
{
  USE_SERIAL.begin(115200);
  USE_SERIAL.setDebugOutput(true);
  delay(100);

  OCPP.setup();
}

void loop()
{
  // DEBUG_LN_HEAP(2000);
  OCPP.loop();
  vTaskDelay(1);
}