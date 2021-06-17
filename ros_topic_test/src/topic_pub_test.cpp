#include "ros/ros.h"                           
#include "ros_topic_test/MsgTest.h"  
#include <sstream>

int main(int argc, char **argv)                
{
  //todo 1
  
  
  
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

    //todo 2
                  

    ++countnum;                          
  }

  return 0;
}
