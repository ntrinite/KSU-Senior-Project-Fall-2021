import rospy

def callback(data):
    rospy.loginfo(data.data)

def listener():
    rospy.init_node('I am sub')
    rospy.Subscriber("cmd_vel", String, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
