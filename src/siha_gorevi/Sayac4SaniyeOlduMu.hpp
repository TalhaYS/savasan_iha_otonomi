#ifndef SAYAC_4_SANIYE_OLDU_MU_HPP
#define SAYAC_4_SANIYE_OLDU_MU_HPP

#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"
#include <string>

class Sayac4SaniyeOlduMu : public BT::ConditionNode
{
public:
    // Yapıcı (Constructor) fonksiyonumuzun imzası
    Sayac4SaniyeOlduMu(const std::string& name, const BT::NodeConfig& config);

    // Blackboard'dan mevcut kilitlenme süresini okumak için port tanımlaması
    static BT::PortsList providedPorts();

    // 4 saniye kontrolünü yapacak tick fonksiyonunun imzası
    BT::NodeStatus tick() override;
};

#endif // SAYAC_4_SANIYE_OLDU_MU_HPP