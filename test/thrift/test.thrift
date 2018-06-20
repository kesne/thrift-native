include "common.thrift"
include "listings.thrift"

struct Work {
  1: optional i32 num1 = 0,
  2: required i32 num2,
  3: optional string comment,
}

struct FirstName {
  1: string name
}

struct LastName {
  1: string name
}

struct Name {
  1: FirstName first_name
  2: LastName last_name
}

struct Everything {
  1: i8 byte_val
  2: i16 i16_val
  3: i32 i32_val
  4: i64 i64_val
  5: set<string> set_val
  6: list<string> list_val
  7: map<string, string> map_val
  8: string string_val
  9: bool bool_val
  10: double double_val
}
