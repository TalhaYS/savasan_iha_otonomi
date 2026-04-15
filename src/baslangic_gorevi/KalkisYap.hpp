#ifndef KALKIS_YAP_HPP
#define KALKIS_YAP_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class KalkisYap : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    KalkisYap(const std::string& name, const BT::NodeConfig& config);

    // Portları belirten fonksiyonumuzun imzası
    static BT::PortsList providedPorts();

    // Asıl işi yapacak olan tick fonksiyonumuzun imzası
    BT::NodeStatus tick() override;
};

#endif