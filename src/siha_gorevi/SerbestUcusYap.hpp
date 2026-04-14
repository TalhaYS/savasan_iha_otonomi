#ifndef SERBEST_UCUS_YAP_HPP
#define SERBEST_UCUS_YAP_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class SerbestUcusYap : public BT::SyncActionNode
{
public:
    SerbestUcusYap(const std::string& name, const BT::NodeConfig& config);
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override;
};

#endif // SERBEST_UCUS_YAP_HPP