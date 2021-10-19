import rospy
from std_msgs.msg import String
import time
# from pynput import keyboard
# import keyboard

def pub_go():

    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node("bloop", anonymous=True)
    rate = rospy.Rate(10)
    print("BLAP")
    key = "wow"
    while not key == "x" or not rospy.is_shutdown():
        key = raw_input("enter command")
        if(key == "w"):
            pub.publish("Forward")
            print("Forward")
        elif(key == "s"):
            pub.publish("Down")
            print("Down")
        elif(key == "d"):
            pub.publish('Right')
            print("Right")
        elif(key == "a"):
            pub.publish("Left")
            print("Left")
        else:
            print("No movement")
        rate.sleep()

def publisher():
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    #rospy.init_node('blep')
    # with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    #     listener.join()
    #print("enter command")
    #key = raw_input("enter command")
    print("going")
    pub_go()
    



