# Exercise 2 - Publish Subscribe
This exercise is to test Publish Subscribe protocol on ROS2. It follows the example provided in the second chapter of the book: 'A Concise Introduction to Robot Programming with ROS2'. 

## Build and Run

Build and source the package
```
$ colcon build --symlink-install --packages-select ex2_pub_sub
$ source install/setup.bash
```

Run the publisher:

```
$ ros2 run ex2_pub_sub ex2_pub
```

Open another terminal and run the Subscriber:

```
$ ros2 run ex2_pub_sub ex2_sub
```
