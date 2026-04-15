#ifndef YUKSEKLIGI_10M_ARTTIR_HPP
#define YUKSEKLIGI_10M_ARTTIR_HPP

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class Yuksekligi10mArttir : public BT::SyncActionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    Yuksekligi10mArttir(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'dan veri okuma ve yazma portlarının tanımlaması
    static BT::PortsList providedPorts();

    // İrtifa artırma işlemini yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif