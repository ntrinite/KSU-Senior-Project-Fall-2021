import rospy
from std_msgs.msg import String
import time
from pynput import keyboard

pub = rospy.Publisher('cmd_vel', String, queue_size=10)
def on_press(key):
    print("key pressed was {} ", key )
    rate = rospy.Rate(10)
    print("BLAP")
    if(key.char == 'w'):
        pub.publish("Forward")
        print("Forward")
    elif(key.char == 's'):
        pub.publish("Down")
        print("Down")
    elif(key.char == 'd'):
        pub.publish('Right')
        print("Right")
    elif(key.char == 'a'):
        pub.publish("Left")
        print("Left")
    else:
        print("idk dude")

def on_release(key):
    print("{} was released.", key)
    if key == keyboard.Key.esc:
        return False

def publisher():
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    rospy.init_node('blep')
    with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
        listener.join()
    rospy.spin()
