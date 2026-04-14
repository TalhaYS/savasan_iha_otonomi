#ifndef TUM_SAYACLARI_SIFIRLA_HPP
#define TUM_SAYACLARI_SIFIRLA_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class TumSayaclariSifirla : public BT::SyncActionNode
{
public:
    // Yapıcı (Constructor) fonksiyonumuzun imzası
    TumSayaclariSifirla(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'daki süreleri sıfırlamak (yazmak) için port tanımlaması
    static BT::PortsList providedPorts();

    // Sıfırlama işlemini yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif // TUM_SAYACLARI_SIFIRLA_HPP