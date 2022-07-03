#include "OCPPCore.h"

OCPPCore::OCPPCore(VirtualOCPP *_ocppImplementation, OCPPWebsocketVirtual *_wsImpl)
    : ocppImplementation(_ocppImplementation), wsImpl(_wsImpl)
{
}

OCPPCore::~OCPPCore()
{
}