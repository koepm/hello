#include "ros_test/hello_pub.hpp"

HelloworldPublisher::HelloworldPublisher()
	: Node("helloworld_publisher"), count_(0) // Node는 생성자 호출
	                                          //count_(0)매개변수 초기화 count=0 이런느낌
{
	auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
	hello_pub_ = this->create_publisher<std_msgs::msg::String>(
			"helloworld", qos_profile);
	timer_ = this->create_wall_timer(
			1s, std::bind(&HelloworldPublisher::pub_hello_msg, this));
	//timer_ = this->create_wall_timer(1s, [this]() { pub_hello_msg(); });
}

void HelloworldPublisher::pub_hello_msg()
{
	auto msg = std_msgs::msg::String();
	msg.data = "Hello World: " + std::to_string(count_++);
	RCLCPP_INFO(this->get_logger(), "Published message: '%s'", msg.data.c_str());
	hello_pub_->publish(msg);
}

int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<HelloworldPublisher>();
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}
