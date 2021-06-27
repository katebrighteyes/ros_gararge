cd
sudo apt-get install ros-melodic-image-transport ros-melodic-vision-msgs

./install_catkinws.sh dnn_ws
cd dnn_ws/src

git clone https://github.com/dusty-nv/ros_deep_learning

cd ..

catkin_make

source devel/setup.bash 

echo "source ~/dnn_ws/devel/setup.bash" >> ~/.bashrc

# VIEWER

roslaunch ros_deep_learning video_viewer.ros1.launch input:=/dev/video1 output:=display://0

# detection

roslaunch ros_deep_learning detectnet.ros1.launch input:=/dev/video1 output:=display://0



