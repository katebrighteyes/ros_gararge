#include "ros/ros.h"                           
#include "ros_topic_test/MsgTest.h"  
#include <sstream>

int main(int argc, char **argv)                
{
  ros::init(argc, argv, "topic_pub_test");     
  ros::NodeHandle nh;                         


  ros::Publisher ros_test_pub = nh.advertise<ros_topic_test::MsgTest>("ros_test_msg", 500);

  ros::Rate loop_rate(500);

  ros_topic_test::MsgTest msg;    
  int countnum = 0;                            

  while (ros::ok())
  {
    std::stringstream ss;
       
    ss << "Hello My Subscriber ";
    msg.strdata = ss.str();
   
    msg.ndata  = countnum;                      

    ROS_INFO("send msg = strdata %s %d", msg.strdata.c_str(), msg.ndata);       

    ros_test_pub.publish(msg);          

    loop_rate.sleep();                   

    ++countnum;                          
  }

  return 0;
}
