include "shared.thrift"

typedef shared.SharedStruct CommonStruct
typedef shared.SharedUnion CommonUnion
typedef shared.SHARED_INT COMMON_INT

exception AuthException {
  1: i32 code
  2: string message
}

struct Metadata {
    1: required i32 traceId
    2: optional i32 clientId
}
