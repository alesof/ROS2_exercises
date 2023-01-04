#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class PublisherNode : public rclcpp::Node{

    public:
        PublisherNode(): Node("publisher_cpp"){

            // Use crate_publisher which is a public method of rclcpp:Node, it returns a shared_ptr to
            // a publisher object. Args are the name of the topic and the Queue
            publisher_ = create_publisher<std_msgs::msg::Int32>("test_topic",10);

            timer_ = create_wall_timer(500ms, std::bind(&PublisherNode::timer_cb,this));
        }

        // timer callback which increments at each iteration the message data field
        void timer_cb(){
            msg_.data += 1;
            publisher_->publish(msg_);
        }

    private:
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        std_msgs::msg::Int32 msg_;

};

int main(int argc, char* argv[]){
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}