import rospy
from std_msgs.msg import Int16
from movement.msg import Control
import time
# from pynput import kaaaaeyboard
# import keyboard


def publisher():
    pub = rospy.Publisher('move', Control, queue_size=1)
    msg = Control()
    msg.do_move = True
    rate = rospy.Rate(10)
    key = "wow"
    while not key == "x" or not rospy.is_shutdown():
        key = raw_input("enter command ")
        print("BLAP")
        if(key == 'w'):
            msg.direction = 8
            msg.speed = 250
            pub.publish(msg)
            print("Forward")
        elif(key == 's'):
            msg.direction = 2
            msg.speed = 250
            pub.publish(msg)
            print("Down")
        elif(key == 'd'):
            msg.direction = 6
            msg.speed = 250
            pub.publish(msg)
            print("Right")
        elif(key == 'a'):
            msg.direction = 4
            msg.speed = 250
            pub.publish(msg)
            print("Left")
        elif(key == 't'):
            msg.direction = 69
            msg.speed = 150
            pub.publish(msg)
            print("Stepper up")
        elif(key == 'g'):
            msg.direction = 420
            msg.speed = -150
            pub.publish(msg)
            print("Stepper down")
        else:
            print("idk dude")
            msg.direction = 0
            msg.speed = 0
            pub.publish(msg)
    rospy.sleep()



    # pub = rospy.Publisher('move', Control, queue_size=10)
    # msg = Control()
    # msg.do_move = True
    # print("key pressed was {} ".format(key))
    # rate = rospy.Rate(10) #hz
    # try:
    #     if(key.char == 'w'):
    #         msg.direction = 8
    #         msg.speed = 250
    #         pub.publish(msg)
    #         print("Forward")
    #     elif(key.char == 's'):
    #         msg.direction = 2
    #         msg.speed = 250
    #         pub.publish(msg)
    #         print("Down")
    #     elif(key.char == 'd'):
    #         msg.direction = 6
    #         msg.speed = 150
    #         pub.publish(msg)
    #         print("Right")
    #     elif(key.char == 'a'):
    #         msg.direction = 4
    #         msg.speed = 150
    #         pub.publish(msg)
    #         print("Left")
    #     else:
    #         print("idk dude")
    #         msg.direction = 0
    #         msg.speed = 0
    #         pub.publish(msg)
    #     # rospy.sleep()
    #     # pub.publish(msg)
    # except AttributeError:
    #     pass
    # rate.sleep()

if __name__ == '__main__':
    # with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    #     listener.join()
    rospy.init_node('blep')
    print("going")
    publisher()
