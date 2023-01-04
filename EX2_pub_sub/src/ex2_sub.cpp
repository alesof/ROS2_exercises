#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class SubscriberNode : public rclcpp::Node{

    public:
        SubscriberNode(): Node("subscriber_cpp"){

            // Use create_subscribion which is a public method of rclcpp:Node, it returns a shared_ptr to
            // a subscriber object. Args are the name of the topic, the Queue, the callback
            subscriber_ = create_subscription<std_msgs::msg::Int32>("test_topic",10,
                std::bind(&SubscriberNode::sub_cb, this, _1));

        }

        // timer callback which increments at each iteration the message data field
        void sub_cb(const std_msgs::msg::Int32::SharedPtr msg){
            RCLCPP_INFO(get_logger(), "Data: %d", msg->data);
        }

    private:
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscriber_; 

};

int main(int argc, char* argv[]){
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}