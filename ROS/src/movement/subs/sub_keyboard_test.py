import rospy
from std_msgs.msg import Int16

def callback(data):
    print("boing")
    rospy.loginfo(data.data)

def listener():
    print("making sub")
    rospy.init_node('I_am_sub', anonymous=True)
    rospy.Subscriber("cmd_vel", Int16, callback)
    rospy.spin()

if __name__ == '__main__':
    print("making sub")
    listener()
