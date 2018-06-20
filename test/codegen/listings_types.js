//
// Autogenerated by Thrift Compiler (0.10.0)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//
"use strict";

var thrift = require('thrift');
var Thrift = thrift.Thrift;
var Q = thrift.Q;


var ttypes = module.exports = {};
var Neighborhood = module.exports.Neighborhood = function(args) {
  this.neighborhoodId = null;
  this.name = null;
  if (args) {
    if (args.neighborhoodId !== undefined && args.neighborhoodId !== null) {
      this.neighborhoodId = args.neighborhoodId;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field neighborhoodId is unset!');
    }
    if (args.name !== undefined && args.name !== null) {
      this.name = args.name;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field name is unset!');
    }
  }
};
Neighborhood.prototype = {};
Neighborhood.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I64) {
        this.neighborhoodId = input.readI64();
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.STRING) {
        this.name = input.readString();
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Neighborhood.prototype.write = function(output) {
  output.writeStructBegin('Neighborhood');
  if (this.neighborhoodId !== null && this.neighborhoodId !== undefined) {
    output.writeFieldBegin('neighborhoodId', Thrift.Type.I64, 1);
    output.writeI64(this.neighborhoodId);
    output.writeFieldEnd();
  }
  if (this.name !== null && this.name !== undefined) {
    output.writeFieldBegin('name', Thrift.Type.STRING, 2);
    output.writeString(this.name);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

var ListingLocationUpdate = module.exports.ListingLocationUpdate = function(args) {
  this.listingId = null;
  this.offsetLat = null;
  this.offsetLng = null;
  this.locationUpdateTimestamp = null;
  this.cityId = null;
  this.canonicalNeighborhoodId = null;
  this.neighborhoods = null;
  if (args) {
    if (args.listingId !== undefined && args.listingId !== null) {
      this.listingId = args.listingId;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field listingId is unset!');
    }
    if (args.offsetLat !== undefined && args.offsetLat !== null) {
      this.offsetLat = args.offsetLat;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field offsetLat is unset!');
    }
    if (args.offsetLng !== undefined && args.offsetLng !== null) {
      this.offsetLng = args.offsetLng;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field offsetLng is unset!');
    }
    if (args.locationUpdateTimestamp !== undefined && args.locationUpdateTimestamp !== null) {
      this.locationUpdateTimestamp = args.locationUpdateTimestamp;
    } else {
      throw new Thrift.TProtocolException(Thrift.TProtocolExceptionType.UNKNOWN, 'Required field locationUpdateTimestamp is unset!');
    }
    if (args.cityId !== undefined && args.cityId !== null) {
      this.cityId = args.cityId;
    }
    if (args.canonicalNeighborhoodId !== undefined && args.canonicalNeighborhoodId !== null) {
      this.canonicalNeighborhoodId = args.canonicalNeighborhoodId;
    }
    if (args.neighborhoods !== undefined && args.neighborhoods !== null) {
      this.neighborhoods = Thrift.copyList(args.neighborhoods, [ttypes.Neighborhood]);
    }
  }
};
ListingLocationUpdate.prototype = {};
ListingLocationUpdate.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I64) {
        this.listingId = input.readI64();
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.DOUBLE) {
        this.offsetLat = input.readDouble();
      } else {
        input.skip(ftype);
      }
      break;
      case 3:
      if (ftype == Thrift.Type.DOUBLE) {
        this.offsetLng = input.readDouble();
      } else {
        input.skip(ftype);
      }
      break;
      case 4:
      if (ftype == Thrift.Type.I64) {
        this.locationUpdateTimestamp = input.readI64();
      } else {
        input.skip(ftype);
      }
      break;
      case 5:
      if (ftype == Thrift.Type.I64) {
        this.cityId = input.readI64();
      } else {
        input.skip(ftype);
      }
      break;
      case 6:
      if (ftype == Thrift.Type.I64) {
        this.canonicalNeighborhoodId = input.readI64();
      } else {
        input.skip(ftype);
      }
      break;
      case 7:
      if (ftype == Thrift.Type.LIST) {
        var _size0 = 0;
        var _rtmp34;
        this.neighborhoods = [];
        var _etype3 = 0;
        _rtmp34 = input.readListBegin();
        _etype3 = _rtmp34.etype;
        _size0 = _rtmp34.size;
        for (var _i5 = 0; _i5 < _size0; ++_i5)
        {
          var elem6 = null;
          elem6 = new ttypes.Neighborhood();
          elem6.read(input);
          this.neighborhoods.push(elem6);
        }
        input.readListEnd();
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

ListingLocationUpdate.prototype.write = function(output) {
  output.writeStructBegin('ListingLocationUpdate');
  if (this.listingId !== null && this.listingId !== undefined) {
    output.writeFieldBegin('listingId', Thrift.Type.I64, 1);
    output.writeI64(this.listingId);
    output.writeFieldEnd();
  }
  if (this.offsetLat !== null && this.offsetLat !== undefined) {
    output.writeFieldBegin('offsetLat', Thrift.Type.DOUBLE, 2);
    output.writeDouble(this.offsetLat);
    output.writeFieldEnd();
  }
  if (this.offsetLng !== null && this.offsetLng !== undefined) {
    output.writeFieldBegin('offsetLng', Thrift.Type.DOUBLE, 3);
    output.writeDouble(this.offsetLng);
    output.writeFieldEnd();
  }
  if (this.locationUpdateTimestamp !== null && this.locationUpdateTimestamp !== undefined) {
    output.writeFieldBegin('locationUpdateTimestamp', Thrift.Type.I64, 4);
    output.writeI64(this.locationUpdateTimestamp);
    output.writeFieldEnd();
  }
  if (this.cityId !== null && this.cityId !== undefined) {
    output.writeFieldBegin('cityId', Thrift.Type.I64, 5);
    output.writeI64(this.cityId);
    output.writeFieldEnd();
  }
  if (this.canonicalNeighborhoodId !== null && this.canonicalNeighborhoodId !== undefined) {
    output.writeFieldBegin('canonicalNeighborhoodId', Thrift.Type.I64, 6);
    output.writeI64(this.canonicalNeighborhoodId);
    output.writeFieldEnd();
  }
  if (this.neighborhoods !== null && this.neighborhoods !== undefined) {
    output.writeFieldBegin('neighborhoods', Thrift.Type.LIST, 7);
    output.writeListBegin(Thrift.Type.STRUCT, this.neighborhoods.length);
    for (var iter7 in this.neighborhoods)
    {
      if (this.neighborhoods.hasOwnProperty(iter7))
      {
        iter7 = this.neighborhoods[iter7];
        iter7.write(output);
      }
    }
    output.writeListEnd();
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};
