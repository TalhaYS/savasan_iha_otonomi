#ifndef KILITLENME_SAYACINI_ILERLET_HPP
#define KILITLENME_SAYACINI_ILERLET_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class KilitlenmeSayaciniIlerlet : public BT::SyncActionNode
{
public:
    // Yapıcı (Constructor) fonksiyonumuzun imzası
    KilitlenmeSayaciniIlerlet(const std::string& name, const BT::NodeConfig& config);

    // Portları belirten fonksiyonumuzun imzası
    static BT::PortsList providedPorts();

    // Asıl işi yapacak olan tick fonksiyonumuzun imzası
    BT::NodeStatus tick() override;
};

#endif // KILITLENME_SAYACINI_ILERLET_HPP