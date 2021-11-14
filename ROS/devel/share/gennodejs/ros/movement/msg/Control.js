// Auto-generated. Do not edit!

// (in-package movement.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Control {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.direction = null;
      this.do_move = null;
    }
    else {
      if (initObj.hasOwnProperty('direction')) {
        this.direction = initObj.direction
      }
      else {
        this.direction = 0;
      }
      if (initObj.hasOwnProperty('do_move')) {
        this.do_move = initObj.do_move
      }
      else {
        this.do_move = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Control
    // Serialize message field [direction]
    bufferOffset = _serializer.int16(obj.direction, buffer, bufferOffset);
    // Serialize message field [do_move]
    bufferOffset = _serializer.bool(obj.do_move, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Control
    let len;
    let data = new Control(null);
    // Deserialize message field [direction]
    data.direction = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [do_move]
    data.do_move = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'movement/Control';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '31f19f0cdb5988f5b529a515002930fb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 direction
    bool do_move
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Control(null);
    if (msg.direction !== undefined) {
      resolved.direction = msg.direction;
    }
    else {
      resolved.direction = 0
    }

    if (msg.do_move !== undefined) {
      resolved.do_move = msg.do_move;
    }
    else {
      resolved.do_move = false
    }

    return resolved;
    }
};

module.exports = Control;
