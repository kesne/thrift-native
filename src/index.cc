#include <nan.h>
#include "Serializer.h"

NAN_MODULE_INIT(InitModule) {
  Serializer::Init(target);
}

NODE_MODULE(myModule, InitModule);
