#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class ToleransAsildiMi : public BT::ConditionNode
{
public:
    ToleransAsildiMi(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("tolerans_suresi_in") };
    }

    BT::NodeStatus tick() override
    {
        double sure = 0.0;
        getInput("tolerans_suresi_in", sure);

        if (sure >= 1.0) {
            std::cout << "[HATA] 1 Saniyelik tolerans aşıldı, kilit bozuldu!" << std::endl;
            return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku (Sıfırlamaya gider)
        }
        return BT::NodeStatus::FAILURE; // "No" oku
    }
};