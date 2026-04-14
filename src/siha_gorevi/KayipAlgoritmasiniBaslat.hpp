#ifndef KAYIP_ALGORITMASINI_BASLAT_HPP
#define KAYIP_ALGORITMASINI_BASLAT_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class KayipAlgoritmasiniBaslat : public BT::SyncActionNode
{
public:
    KayipAlgoritmasiniBaslat(const std::string& name, const BT::NodeConfig& config);
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override;
};

#endif // KAYIP_ALGORITMASINI_BASLAT_HPP