#ifndef SON_VURULAN_HEDEFI_KAYDET_HPP
#define SON_VURULAN_HEDEFI_KAYDET_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class SonVurulanHedefiKaydet : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    SonVurulanHedefiKaydet(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'dan anlık hedefi okuyup, son vurulan olarak yazmak için port tanımlaması
    static BT::PortsList providedPorts();

    // Asıl kayıt işlemini yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif