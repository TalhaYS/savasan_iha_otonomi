#ifndef HEDEF_VURUS_ALANINDA_MI_HPP
#define HEDEF_VURUS_ALANINDA_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class HedefVurusAlanindaMi : public BT::ConditionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    HedefVurusAlanindaMi(const std::string& name, const BT::NodeConfig& config);

    // Port tanımlaması
    static BT::PortsList providedPorts();

    // Vuruş alanı kontrolünü yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif