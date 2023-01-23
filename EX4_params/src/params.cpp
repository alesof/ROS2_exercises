#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include <vector>
#include <string>

using namespace std::chrono_literals;
using std::placeholders::_1;

class ParamNode : public rclcpp::Node{

    public:
        ParamNode(): Node("ex4_param_node"){

            declare_parameter("topic_num", 2);
            declare_parameter("topic_nam", std::vector<std::string>());
            declare_parameter("topic_typ", std::vector<std::string>());

            get_parameter("topic_num", topic_num_);
            get_parameter("topic_nam", topic_nam_);
            get_parameter("topic_typ", topic_typ_);

            timer_ = create_wall_timer(500ms, std::bind(&ParamNode::timer_cb,this));

        }

        void timer_cb(){

            RCLCPP_INFO(get_logger(), "Topic Number: %d", topic_num_);
            for(int i=0; i<topic_num_; i++){
                RCLCPP_INFO_STREAM(get_logger(), "Topic Name: " << topic_nam_[i] <<'\t');
                //RCLCPP_INFO_STREAM(get_logger(), "haha ");
            }
            for(int i=0; i<topic_num_; i++){
                RCLCPP_INFO_STREAM(get_logger(), "Topic Type: " << topic_typ_[i] <<'\t');
                //RCLCPP_INFO_STREAM(get_logger(), "haha ");
            }
            
        }

    private:
        rclcpp::TimerBase::SharedPtr timer_;

        int topic_num_;
        std::vector<std::string> topic_nam_;
        std::vector<std::string> topic_typ_;

};

int main(int argc, char* argv[]){
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ParamNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}