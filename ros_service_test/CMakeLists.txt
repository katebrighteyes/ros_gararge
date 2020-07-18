cmake_minimum_required(VERSION 3.0.2)
project(ros_service_test)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_service_files(FILES SrvTest.srv)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  LIBRARIES ros_service_test
  CATKIN_DEPENDS std_msgs roscpp
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ros_service_server src/ros_service_server.cpp)
add_dependencies(ros_service_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_service_server ${catkin_LIBRARIES})

add_executable(ros_service_client src/ros_service_client.cpp)
add_dependencies(ros_service_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_service_client ${catkin_LIBRARIES})

