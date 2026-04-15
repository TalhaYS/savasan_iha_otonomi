#ifndef HEDEFI_ORTALA_HPP
#define HEDEFI_ORTALA_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class HedefiOrtala : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    HedefiOrtala(const std::string& name, const BT::NodeConfig& config);

    // Portları belirten fonksiyonumuzun imzası
    static BT::PortsList providedPorts();

    // Asıl PID ve ortalama mantığının çalışacağı tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif