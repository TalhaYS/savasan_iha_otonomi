#ifndef TOLERANS_SAYACINI_ILERLET_HPP
#define TOLERANS_SAYACINI_ILERLET_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class ToleransSayaciniIlerlet : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    ToleransSayaciniIlerlet(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'dan tolerans süresini okuyup yazmak için port tanımlaması
    static BT::PortsList providedPorts();

    // Süre artırma işlemini yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif