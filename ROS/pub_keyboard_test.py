import rospy
from std_msgs.msg import String
import time
from pynput import keyboard

def on_press(key):
    rospy.init_node('blep')
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    print("key pressed was {} ", key )
    rate = rospy.Rate(10)
    if(key.char == 'w'):
        pub.plubish("Forward")
    elif(key.char == 's'):
        pub.publish("Down")
    elif(key.char == 'd'):
        pub.publish('Right')
    else(key.char == 'a'):
        pub.publish("Left")
    rospy.spin()

def on_release(key):
    print("{} was released.", key)
    if key == keyboard.Key.esc:
        return False

def publisher():
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
