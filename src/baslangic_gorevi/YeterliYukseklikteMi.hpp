#ifndef YETERLI_YUKSEKLIKTE_MI_HPP
#define YETERLI_YUKSEKLIKTE_MI_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class YeterliYukseklikteMi : public BT::ConditionNode
{
public:
    // Yapıcı fonksiyonumuzun imzası
    YeterliYukseklikteMi(const std::string& name, const BT::NodeConfig& config);

    // XML'den hedef irtifayı almak için port tanımlaması
    static BT::PortsList providedPorts();

    // İrtifa kontrolünü yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif