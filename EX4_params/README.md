# Exercise 4 - Parameters
This exercise is to test Parameters in ROS2.

## Build and Run

Build and source the package
```
$ colcon build --symlink-install --packages-select ex4_params
$ source install/setup.bash
```

Launch the node:

```
$ ros2 launch ex4_params ex4_launch.py
```

Behaviour:

This node instantiates the following parameters and then logs them in the consolle using a callback.

```
topic_num: 2
topic_nam: [test1, test2]
topic_typ: [std_msgs/msg/Int32, std_msgs/msg/String]
```

 
