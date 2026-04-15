#ifndef QR_KONUM_BILGISI_GIRILDI_MI_HPP
#define QR_KONUM_BILGISI_GIRILDI_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class QrKonumBilgisiGirildiMi : public BT::ConditionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    QrKonumBilgisiGirildiMi(const std::string& name, const BT::NodeConfig& config);

    // Konum verisini Blackboard'a yazmak için port tanımlaması
    static BT::PortsList providedPorts();

    // Asıl karar mekanizmasının çalışacağı tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif