cmake_minimum_required(VERSION 3.0.2)
project(ros_topic_test)


find_package(catkin REQUIRED COMPONENTS
  message_generation 
  roscpp
  std_msgs
)


add_message_files(FILES MsgTest.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  LIBRARIES ros_topic_test
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(topic_pub_test src/topic_pub_test.cpp)
add_dependencies(topic_pub_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topic_pub_test ${catkin_LIBRARIES})

add_executable(topic_sub_test src/topic_sub_test.cpp)
add_dependencies(topic_sub_test ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(topic_sub_test ${catkin_LIBRARIES})
