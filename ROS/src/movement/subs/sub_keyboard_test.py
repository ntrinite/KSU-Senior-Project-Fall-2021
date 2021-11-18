import rospy
from std_msgs.msg import Int16
from movement.msg import Control

def callback(data):
    print("boing")
    rospy.loginfo("Direction: %f Move? %f", data.direction, data.do_move)

def listener():
    print("making sub")
    rospy.init_node('I_am_sub', anonymous=True)
    rospy.Subscriber("move", Control, callback)
    rospy.spin()

if __name__ == '__main__':
    print("making sub")
    listener()
