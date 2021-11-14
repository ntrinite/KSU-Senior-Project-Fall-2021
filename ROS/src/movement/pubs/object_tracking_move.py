# object tracking implementation 
from imutils import video
from imutils.video import VideoStream
from imutils.video import FPS
import imutils
import cv2
import rospy
from movement.msg import Control



print("Creating object tracker...")
tracker = cv2.TrackerCSRT_create()
print(tracker)
initBB = None

# Sets winddow size
width = 1280
height = 960

print("Starting video stream...")
video_stream = cv2.VideoCapture(0)
video_stream.set(3, width)
video_stream.set(4, height)

if video_stream.isOpened() == False: 
    print("Error while attempting to open video stream.")

fps = None

while video_stream.isOpened(): 
    # read in the frame of the video stream
    ret, frame = video_stream.read()
    
    if initBB is not None:
        (success, box) = tracker.update(frame)

        if success:
            (x, y, w, h) = [int(v) for v in box]
            cv2.rectangle(frame, (x,y), (x+w, y+h), (0, 255, 0), 2)
            # print("({}, {}) , W and H is ({}, {})".format(x,y,x+w,y+h))
            BB_center_x = x + w/2
            BB_center_y = h/2
            screen_center_x = width/2
            if (BB_center_x <= screen_center_x + 50 and BB_center_x >= screen_center_x - 50):
                print("CENTER!!! \nBB center: {} \nScreen center: {} ".format(BB_center_x, screen_center_x))
            else:
                print("not there yet, \nBB center: {} \nScreen center: {} ".format(BB_center_x, screen_center_x))
        
        #fps.update()
        #fps.stop()

    if ret == True:
        cv2.imshow("Frame", frame)
        key = cv2.waitKey(1)

        if key == ord("s"):
            initBB = cv2.selectROI("Frame", frame, fromCenter = False, showCrosshair = True)
            # BB_x = initBB.x
            tracker.init(frame, initBB)
            fps = FPS().start()
    
        elif key == ord("q"):
            break
    else: 
        break
    
video_stream.release()
cv2.destroyAllWindows()
    

