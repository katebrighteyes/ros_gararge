
#include "ros/ros.h"
#include "darknet_ros_msgs/BoundingBoxes.h"
#include "darknet_ros_msgs/BoundingBox.h"
#include "darknet_sub/MsgState.h" 
#include <pthread.h>

#define RAD2DEG(x) ((x)*180./M_PI)

using namespace std;

string target = "person";
bool detect_target = false;
int state_num = 0; 
darknet_sub::MsgState msg;
ros::Publisher state_pub;

void msgCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg)
{
}

#if 1
void *test(void *data)
{

}
#endif

int main(int argc, char **argv)
{
    cout<<"darknet_sub_node" <<endl;
#if 1

    pthread_t thread_t;
    int status;

    ros::init(argc, argv, "darknet_sub_node");
    ros::NodeHandle nh;
    ros::Subscriber obj_sub = nh.subscribe("/darknet_ros/bounding_boxes",100,msgCallback);
 	
    state_pub = nh.advertise<darknet_sub::MsgState>("cur_state", 100);

	
    if (pthread_create(&thread_t, NULL, test, 0) < 0)
    {
        printf("thread create error:");
        exit(0);
    }


    ros::spin();

    pthread_join(thread_t, (void **)&status);
    printf("Thread End %d\n", status);
#endif

	return 0;
}

