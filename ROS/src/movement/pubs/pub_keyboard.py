#!/usr/bin/env python2

import rospy
from std_msgs.msg import Int16
from movement.msg import Control
import time
from pynput import keyboard

def on_press(key):
    pub = rospy.Publisher('cmd_vel', Control, queue_size=10)
    msg = Control()
    msg.do_move = True
    print("key pressed was {} ".format(key))
    rate = rospy.Rate(10) #hz
    try:
        if(key.char == 'w'):
            msg.direction = 8
            msg.speed = 250
            print("Forward")
        elif(key.char == 's'):
            msg.direction = 2
            msg.speed = 250
            print("Down")
        elif(key.char == 'd'):
            msg.direction = 6
            msg.speed = 150
            print("Right")
        elif(key.char == 'a'):
            msg.direction = 4
            msg.speed = 150
            print("Left")
        else:
            print("idk dude")
            msg.direction = 0
            msg.speed = 0
        # rospy.sleep()
        pub.publish(msg)
    except AttributeError:
        pass

def on_release(key):
    print("{} was released.".format(str(key)))
    pub = rospy.Publisher('cmd_vel', Control, queue_size=10)
    msg = Control()
    msg.do_move = False
    msg.direction = 17
    msg.speed = 0
    pub.publish(msg)
    if key == keyboard.Key.esc:
        return False

if __name__ == '__main__':
    rospy.init_node('blep')
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
    # rospy.spin()
