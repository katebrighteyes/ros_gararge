cmake_minimum_required(VERSION 2.8.3)
project(darknet_sub)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  std_msgs
  darknet_ros
  darknet_ros_msgs
  sensor_msgs
)

add_message_files(FILES MsgState.msg)
generate_messages(DEPENDENCIES std_msgs)


###################################
## catkin specific configuration ##
###################################
catkin_package(
  LIBRARIES acc_logic_ros
  CATKIN_DEPENDS roscpp std_msgs darknet_ros darknet_ros_msgs sensor_msgs 
)


###########
## Build ##
###########

link_directories(
  /usr/local/cuda/lib64
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${RPLIDAR_SDK_PATH}/include
  ${RPLIDAR_SDK_PATH}/src  
)

add_executable(darknet_sub_node src/darknet_sub_node.cpp)
add_dependencies(darknet_sub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(darknet_sub_node
  cuda
  cudart
  cublas
  pthread
  ${catkin_LIBRARIES}
)



