import rospy
from std_msgs.msg import Int16
import time
# from pynput import kaaaaeyboard
# import keyboard


def publisher():
    pub = rospy.Publisher('cmd_vel', Int16, queue_size=10)
    rospy.init_node('blep')
    rate = rospy.Rate(10)
    key = "wow"
    while not key == "x" or not rospy.is_shutdown():
        key = raw_input("enter command ")
        print("BLAP")
        if(key == "w"):
            pub.publish(8)
            print("Forward")
        elif(key == "s"):
            pub.publish(2)
            print("Down")
        elif(key == "d"):
            pub.publish(6)
            print("Right")
        elif(key == "a"):
            pub.publish(4)
            print("Left")
        else:
            print("No movement")
    rospy.sleep()

if __name__ == '__main__':
    # with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    #     listener.join()
    print("going")
    publisher()