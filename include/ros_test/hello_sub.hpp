#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class HelloworldSubscriber : public rclcpp::Node
{
	public:
		HelloworldSubscriber();

	private:
		void sub_hello_msg(const std_msgs::msg::String::SharedPtr msg) const;
		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr hello_sub_;
};
