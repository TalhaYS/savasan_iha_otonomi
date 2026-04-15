#ifndef ISTASYONA_PAKETI_GONDER_HPP
#define ISTASYONA_PAKETI_GONDER_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class IstasyonaPaketiGonder : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    IstasyonaPaketiGonder(const std::string& name, const BT::NodeConfig& config);

    // Port tanımlaması
    static BT::PortsList providedPorts();

    // Asıl haberleşme ve paket gönderme mantığının çalışacağı tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif