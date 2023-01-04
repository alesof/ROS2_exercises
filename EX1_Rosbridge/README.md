# Exercise 1 - Rosbridge
This exercise is to test rosbridge on ROS2. It follows the example provided [here](https://foxglove.dev/blog/using-rosbridge-with-ros2)  

## HTML file

The HTML file contains javascript used to show the status of the connection and messages published on the '\test_topic' topic.

## To Run

Install the specific version of rosbridge for your ROS2 distro:
```
$ sudo apt install ros-<YOUR-DISTRO>-rosbridge-server
$ source /opt/ros/<YOUR-DISTRO>/setup.bash
```

Launch a webserver from a terminal window:
```
$ ros2 launch rosbridge_server rosbridge_websocket_launch.xml 
```
Refresh the page, it should show the status "Connected".

Publish on '\test_topic' data using:
```
$ ros2 topic pub /test_topic std_msgs/String "data: 'test1'" --r 1
```

Messages published on the topic should now appear on the page.
