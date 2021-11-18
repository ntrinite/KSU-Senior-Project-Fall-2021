// Generated by gencpp from file movement/Control.msg
// DO NOT EDIT!


#ifndef MOVEMENT_MESSAGE_CONTROL_H
#define MOVEMENT_MESSAGE_CONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace movement
{
template <class ContainerAllocator>
struct Control_
{
  typedef Control_<ContainerAllocator> Type;

  Control_()
    : direction(0)
    , do_move(false)  {
    }
  Control_(const ContainerAllocator& _alloc)
    : direction(0)
    , do_move(false)  {
  (void)_alloc;
    }



   typedef int16_t _direction_type;
  _direction_type direction;

   typedef uint8_t _do_move_type;
  _do_move_type do_move;





  typedef boost::shared_ptr< ::movement::Control_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::movement::Control_<ContainerAllocator> const> ConstPtr;

}; // struct Control_

typedef ::movement::Control_<std::allocator<void> > Control;

typedef boost::shared_ptr< ::movement::Control > ControlPtr;
typedef boost::shared_ptr< ::movement::Control const> ControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::movement::Control_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::movement::Control_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::movement::Control_<ContainerAllocator1> & lhs, const ::movement::Control_<ContainerAllocator2> & rhs)
{
  return lhs.direction == rhs.direction &&
    lhs.do_move == rhs.do_move;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::movement::Control_<ContainerAllocator1> & lhs, const ::movement::Control_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace movement

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::movement::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::movement::Control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::movement::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::movement::Control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::movement::Control_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::movement::Control_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::movement::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "31f19f0cdb5988f5b529a515002930fb";
  }

  static const char* value(const ::movement::Control_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x31f19f0cdb5988f5ULL;
  static const uint64_t static_value2 = 0xb529a515002930fbULL;
};

template<class ContainerAllocator>
struct DataType< ::movement::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "movement/Control";
  }

  static const char* value(const ::movement::Control_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::movement::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 direction\n"
"bool do_move\n"
;
  }

  static const char* value(const ::movement::Control_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::movement::Control_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.direction);
      stream.next(m.do_move);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Control_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::movement::Control_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::movement::Control_<ContainerAllocator>& v)
  {
    s << indent << "direction: ";
    Printer<int16_t>::stream(s, indent + "  ", v.direction);
    s << indent << "do_move: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.do_move);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOVEMENT_MESSAGE_CONTROL_H