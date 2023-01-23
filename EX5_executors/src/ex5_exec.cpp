#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class PublisherNode : public rclcpp::Node{

    public:
        PublisherNode(): Node("publisher_cpp"){
            publisher_ = create_publisher<std_msgs::msg::Int32>("test_topic",10);
            cb_group_ = this->create_callback_group(rclcpp::callback_group::CallbackGroupType::MutuallyExclusive);
            timer_ = create_wall_timer(500ms, std::bind(&PublisherNode::timer_cb,this), cb_group_);
        }
        void timer_cb(){
            msg_.data += 1;
            publisher_->publish(msg_);
        }

    private:
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
        rclcpp::callback_group::CallbackGroup::SharedPtr cb_group_;
        rclcpp::TimerBase::SharedPtr timer_;
        std_msgs::msg::Int32 msg_;

};

class SubscriberNode : public rclcpp::Node{

    public:
        SubscriberNode(): Node("subscriber_cpp"){
            subscriber_ = create_subscription<std_msgs::msg::Int32>("test_topic",10,
                std::bind(&SubscriberNode::sub_cb, this, _1));
        }
        void sub_cb(const std_msgs::msg::Int32::SharedPtr msg){
            RCLCPP_INFO(get_logger(), "Data: %d", msg->data);
        }

    private:
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscriber_; 

};

int main(int argc, char* argv[]){
    
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor exec;

    auto pub_node = std::make_shared<PublisherNode>();
    auto sub_node = std::make_shared<SubscriberNode>();

    exec.add_node(pub_node);
    exec.add_node(sub_node);
    exec.spin();

    rclcpp::shutdown();
    return 0;
}