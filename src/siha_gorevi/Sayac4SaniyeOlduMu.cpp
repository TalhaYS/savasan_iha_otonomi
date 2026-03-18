#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class Sayac4SaniyeOlduMu : public BT::ConditionNode
{
public:
    Sayac4SaniyeOlduMu(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("kilit_suresi_in") };
    }

    BT::NodeStatus tick() override
    {
        double sure = 0.0;
        getInput("kilit_suresi_in", sure);

        if (sure >= 4.0) {
            std::cout << "[BAŞARI] Hedefe 4 saniye kilitlenildi!" << std::endl;
            return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku (Paket göndermeye gider)
        }
        return BT::NodeStatus::FAILURE; // "No" oku
    }
};