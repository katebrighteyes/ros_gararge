#include "ros/ros.h"                         
#include "ros_service_test/SrvTest.h"
#include <cstdlib>                           

int main(int argc, char **argv)             
{
  ros::init(argc, argv, "ros_service_client");   

  if (argc != 3) 
  {
    ROS_INFO("execute : rosrun ros_service_test rosd_service_client arg0 arg1");
    return 1;
  }

  ros::NodeHandle nh;     

  ros::ServiceClient ros_service_client = nh.serviceClient<ros_service_test::SrvTest>("ros_service_test");

  ros_service_test::SrvTest srv;

  srv.request.arg1 = atoi(argv[1]);
  srv.request.arg2 = atoi(argv[2]);

  // Request the service. If the request is accepted, display the response value
  if (ros_service_client.call(srv))
  {
    ROS_INFO("Request.arg1 and arg2: %d, %d", (int)srv.request.arg1, (int)srv.request.arg2);
    ROS_INFO("Response.result value: %d", (int)srv.response.resval);
  }
  else
  {
    ROS_ERROR("Failed");
    return 1;
  }
  return 0;
} 

