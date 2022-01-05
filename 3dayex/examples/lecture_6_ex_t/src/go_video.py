#!/usr/bin/env python

import cv2, time
import rospy, rospkg
import numpy as np

from ackermann_msgs.msg import AckermannDriveStamped

ack_publisher = None

cv_image = np.empty(shape=[0])


  if x_location == None:
    r_center = rpos

  x_location = (r_center - rpos)
  x_location = (x_location/3) * (0.017)
    
  detect_area = hsv_line[2:15,120:520]
  cntzero = cv2.countNonZero(detect_area)

  if cntzero > 2400:
    drive(0,0)
    time.sleep(3)

  drive(x_location,0.36)

  cv2.imshow("origin", cv_image)
  cv2.imshow("view", view)

  time.sleep(0.01)

cv2.destroyAllWindows()
