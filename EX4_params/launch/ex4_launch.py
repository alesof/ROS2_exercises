from launch import LaunchDescription
from launch_ros.actions import Node

import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    pkg_dir = get_package_share_directory('ex4_params')
    param_file = os.path.join(pkg_dir, 'config', 'params.yaml')

    params_node = Node(
        package='ex4_params',
        executable='ex4_params',
        parameters=[param_file],
        output='screen'
    )

    ld = LaunchDescription()
    ld.add_action(params_node)

    return ld
