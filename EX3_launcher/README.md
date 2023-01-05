# Exercise 3 - Launcher
This exercise is to test Launcher files in ROS2. It uses the same publisher/subscriber nodes defined in exercise2.

## Build and Run

Build and source the package
```
$ colcon build --symlink-install --packages-select ex3_launcher
$ source install/setup.bash
```

Launch a publisher and a subscriber using the launch file:

```
$ ros2 launch ex3_launcher pub_sub_launch.py
```
