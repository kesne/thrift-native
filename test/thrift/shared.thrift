const i32 SHARED_INT = 45

struct Code {
  1: i64 status
}

struct SharedStruct {
  1: required Code code
  2: required string value
}
