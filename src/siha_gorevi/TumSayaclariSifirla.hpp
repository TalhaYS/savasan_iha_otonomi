#ifndef TUM_SAYACLARI_SIFIRLA_HPP
#define TUM_SAYACLARI_SIFIRLA_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class TumSayaclariSifirla : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    TumSayaclariSifirla(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'daki süreleri sıfırlamak için port tanımlaması
    static BT::PortsList providedPorts();

    // Sıfırlama işlemini yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif 