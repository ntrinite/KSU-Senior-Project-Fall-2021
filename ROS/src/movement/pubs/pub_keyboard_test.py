#!/usr/bin/env python2

import rospy
from std_msgs.msg import Int16
import time
from pynput import keyboard

pub = rospy.Publisher('cmd_vel', Int16, queue_size=10)
def on_press(key):
    print("key pressed was {} ", key )
    rate = rospy.Rate(10) #hz
    print("BLAP")
    if(key.char == 'w'):
        pub.publish(8)
        print("Forward")
    elif(key.char == 's'):
        pub.publish(2)
        print("Down")
    elif(key.char == 'd'):
        pub.publish(6)
        print("Right")
    elif(key.char == 'a'):
        pub.publish(4)
        print("Left")
    else:
        print("idk dude")
    # rospy.sleep()

def on_release(key):
    print("{} was released.", key)
    pub = rospy.Publisher('cmd_vel', Int16, queue_size=10)
    pub.publish(17)
    if key == keyboard.Key.esc:
        return False

def publisher():
    pub = rospy.Publisher('cmd_vel', Int16, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    rospy.init_node('blep')
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
    # rospy.spin()
