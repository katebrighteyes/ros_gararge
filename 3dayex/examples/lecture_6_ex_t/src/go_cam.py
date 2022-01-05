#!/usr/bin/env python

import cv2, time
import rospy
import numpy as np

from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from ackermann_msgs.msg import AckermannDriveStamped

ack_publisher = None




  if cv2.waitKey(1) & 0Xff == 27:
    break

cv2.destroyAllWindows()
