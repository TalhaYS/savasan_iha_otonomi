#ifndef HEDEF_TEKRAR_GORUNTUDE_MI_HPP
#define HEDEF_TEKRAR_GORUNTUDE_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class HedefTekrarGoruntudeMi : public BT::ConditionNode
{
public:
    HedefTekrarGoruntudeMi(const std::string& name, const BT::NodeConfig& config);
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override;
};

#endif