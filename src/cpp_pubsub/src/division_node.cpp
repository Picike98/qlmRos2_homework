#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

class DivisionNode : public rclcpp::Node {
public:
    DivisionNode() : Node("division_node") {
        // Subscriber to /input_numbers
        subscription_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
            "/input_numbers", 10, std::bind(&DivisionNode::topic_callback, this, std::placeholders::_1));

        // Publisher to /division_result
        publisher_ = this->create_publisher<std_msgs::msg::Float64>("/division_result", 10);
        RCLCPP_INFO(this->get_logger(),"Init");
    }

private:
    void topic_callback(const std_msgs::msg::Float64MultiArray::SharedPtr msg) {

        if (msg->data.size() != 2) {
            RCLCPP_ERROR(this->get_logger(), "Error: Expected exactly 2 numbers in the input.");
            return;
        }

        // Extract numbers
        double num1 = msg->data[0];
        double num2 = msg->data[1];

        RCLCPP_INFO(this->get_logger(),"Msg rec.");

        // Division
        if (num2 == 0) {
            RCLCPP_ERROR(this->get_logger(), "Error: Division by zero!");
            return;
        }

        double result = num1 / num2;

        // Publish result
        auto result_msg = std_msgs::msg::Float64();
        result_msg.data = result;
        publisher_->publish(result_msg);

        RCLCPP_INFO(this->get_logger(), "Divided: %f / %f = %f", num1, num2, result);       
    }

    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DivisionNode>());
    rclcpp::shutdown();
    return 0;
}
