# thrift-native

Node.js bindings to Thrift's C++ library. Designed for easy manually serializing / deserializing payloads with thrift. Currently only supports the Compact protocol.

This makes serializing large structs significantly faster. Currently, only the serializer uses the C++ library, and the deserializer just uses the thrift node library.

## Using

First, you need to install the package:
```bash
npm install thrift-native --save
```

You can them import the `Serializer` and `Deserializer` classes and use them on your generated thrift structs:
```js
import { Serializer, Deserializer } from 'thrift-native';
import { MyThriftStruct } from './generated/thrift';

const struct = new MyThriftStruct({ some: 'data' });
const serializer = new Serializer();
struct.write(serializer);

// To get the serialized value and reset the serializer:
const serailizedThrift = serializer.flush();

const deserializer = new Deserializer(serailizedThrift);
const structFromThrift = new MyThriftStruct();
structFromThrift.read(deserializer);
```
