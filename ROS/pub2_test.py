import rospy
from std_msgs.msg import String
import time
# from pynput import keyboard
import keyboard

keep_listening = True
pub = rospy.Publisher('cmd_vel', String, queue_size=10)

def key_press(key):
    print("key pressed was ", key )
    rate = rospy.Rate(10)
    print("BLAP")
    if(key.name == 'w'):
        pub.publish("Forward")
        print("Forward")
    elif(key.name == 's'):
        pub.publish("Down")
        print("Down")
    elif(key.name == 'd'):
        pub.publish('Right')
        print("Right")
    elif(key.name == 'a'):
        pub.publish("Left")
        print("Left")
    else:
        keep_listening = False

def on_release(key):
    print("{} was released.", key)
    # if key == keyboard.Key.esc:
    return False

def publisher():
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    rospy.init_node('blep')
    # with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    #     listener.join()
    keyboard.on_press(key_press)
    while keep_listening:
        rospy.spin()
