#ifndef HEDEF_ARAMAYI_AKTIFLESTIR_HPP
#define HEDEF_ARAMAYI_AKTIFLESTIR_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class HedefAramayiAktiflestir : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    HedefAramayiAktiflestir(const std::string& name, const BT::NodeConfig& config);

    // Portları belirten fonksiyonumuzun imzası
    static BT::PortsList providedPorts();

    // Asıl arama mantığının çalışacağı tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif