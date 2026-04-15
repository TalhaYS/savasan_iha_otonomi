#ifndef TOLERANS_ASILDI_MI_HPP
#define TOLERANS_ASILDI_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class ToleransAsildiMi : public BT::ConditionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    ToleransAsildiMi(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'dan tolerans süresini okumak için port tanımlaması
    static BT::PortsList providedPorts();

    // Tolerans kontrolünü yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif