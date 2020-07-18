#include "ros/ros.h"                        
#include "ros_service_test/SrvTest.h"

bool multiple_func(ros_service_test::SrvTest::Request &req,
                 ros_service_test::SrvTest::Response &res)
{
  res.resval = req.arg1 * req.arg2;

  ROS_INFO("request: arg1=%d, arg2=%d", (int)req.arg1, (int)req.arg2);
  ROS_INFO("result value: %d", (int)res.resval);

  return true;
}

int main(int argc, char **argv)            
{
  ros::init(argc, argv, "ros_service_server");   
  ros::NodeHandle nh;                 

  ros::ServiceServer ros_service_server = nh.advertiseService("ros_service_test", multiple_func);

  ROS_INFO("SERVICE server is ready");

  ros::spin();    

  return 0;
} 

