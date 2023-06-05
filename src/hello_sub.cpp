#include "ros_test/hello_sub.hpp"

using std::placeholders::_1;

HelloworldSubscriber::HelloworldSubscriber()
	:Node("Helloworld_Subscriber")
{
	auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
	hello_sub_ = this->create_subscription<std_msgs::msg::String>("helloworld",
			qos_profile,
			std::bind(&HelloworldSubscriber::sub_hello_msg, this, _1));
}

void HelloworldSubscriber::sub_hello_msg(const std_msgs::msg::String::SharedPtr msg) const
{
	RCLCPP_INFO(this->get_logger(), "Received message: '%s'",
			msg->data.c_str());
}


int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);
	auto node = std::make_shared<HelloworldSubscriber>();
	rclcpp::spin(node);
	rclcpp::shutdown();
	return 0;
}
