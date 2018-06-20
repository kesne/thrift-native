{
  "targets": [{
    "target_name": "thrift-native",
    "include_dirs" : [
      "src",
      "<!(node -e \"require('nan')\")"
    ],
    "libraries": [ "-lthrift" ],
    "sources": [
      "src/index.cc",
      "src/Protocol.cc"
    ]
  }]
}
