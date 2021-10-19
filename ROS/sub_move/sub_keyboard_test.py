import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo(data.data)

def listener():
    rospy.init_node('I_am_sub')
    rospy.Subscriber("cmd_vel", String, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
