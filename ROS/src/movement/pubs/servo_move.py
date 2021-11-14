import rospy
from std_msgs.msg import Int16
import time

def publisher():
    pub = rospy.Publisher('cmd_vel', Int16, queue_size=10)
    rospy.init_node('blep')
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(90)
        rospy.loginfo("servor move to 90")
        time.sleep(1)
        pub.publish(45)
        rospy.loginfo("Servor move to 45")
        time.sleep(1)
        pub.publish(120)
        rospy.loginfo("servor move to 120")
        time.sleep(1)
        pub.publish(0)
        rospy.loginfo("servor move to 0")
        time.sleep(1)

        rate.sleep()

if __name__ == '__main__':
    publisher()