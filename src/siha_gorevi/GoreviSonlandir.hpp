#ifndef GOREVI_SONLANDIR_HPP
#define GOREVI_SONLANDIR_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class GoreviSonlandir : public BT::SyncActionNode
{
public:
    GoreviSonlandir(const std::string& name, const BT::NodeConfig& config);
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override;
};

#endif