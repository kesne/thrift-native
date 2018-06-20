#include <nan.h>
#include "Protocol.h"

NAN_MODULE_INIT(InitModule) {
  Protocol::Init(target);
}

NODE_MODULE(myModule, InitModule);
