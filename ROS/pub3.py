import rospy
from std_msgs.msg import String
import time
# from pynput import keyboard
# import keyboard

# keep_listening = True
pub = rospy.Publisher('cmd_vel', String, queue_size=10)

def key_press(key):
    print("key pressed was ", key )
    rate = rospy.Rate(10)
    print("BLAP")
    if(key == 'w'):
        pub.publish("Forward")
        print("Forward")
    elif(key == 's'):
        pub.publish("Down")
        print("Down")
    elif(key == 'd'):
        pub.publish('Right')
        print("Right")
    elif(key == 'a'):
        pub.publish("Left")
        print("Left")
    else:
        keep_listening = False


def publisher():
    pub = rospy.Publisher('cmd_vel', String, queue_size=10)
    rospy.init_node('blep')

if __name__ == '__main__':
    rospy.init_node('blep')
    # with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    #     listener.join()
    key = input()
    while not key == "x":
        key_press(key)
        rospy.spin()
