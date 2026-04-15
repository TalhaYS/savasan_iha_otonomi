#ifndef HEDEF_TESPIT_EDILDI_MI_HPP
#define HEDEF_TESPIT_EDILDI_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class HedefTespitEdildiMi : public BT::ConditionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    HedefTespitEdildiMi(const std::string& name, const BT::NodeConfig& config);

    // Vurulan uçağı tekrar görmemek için ID okuyacak port tanımlaması
    static BT::PortsList providedPorts();

    // Asıl hedef tespit mantığının çalışacağı tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif