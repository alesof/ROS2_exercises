# Exercise 5 - Executors
This exercise is to test Executors functionalities and Callback Groups on ROS2. It follows the example provided in the second chapter of the book: 'A Concise Introduction to Robot Programming with ROS2'. More on callback groups available at: 'docs.ros.org/en/foxy/How-To-Guides/Using-callback-groups.html'

## Build and Run

Build and source the package
```
$ colcon build --symlink-install --packages-select ex5_executors
$ source install/setup.bash
```

Run the publisher:

```
$ ros2 run ex5_executors
```

Behaviour:

This node runs a publisher and a subscriber node in the same process. To inspect available nodes and make sure both are running open another console window and enter:
```
$ ros2 node list
```

To check node infos:
```
$ ros2 node info /publisher_cpp 
```

