#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class KalkisYap : public BT::SyncActionNode
{
public:
    KalkisYap(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return {}; // Dışarıdan veri almıyorsa boş kalır
    }

    BT::NodeStatus tick() override
    {
        // --------------------------------------------------------
        // TODO (Ekip Arkadaşı): 
        // ROS 2 üzerinden İHA'ya "Takeoff" (Örn: mavros/cmd/takeoff) servisini çağır.
        // Motorları arm et (çalıştır).
        // --------------------------------------------------------
        
        std::cout << "[KALKIŞ] Motorlar arm edildi, kalkış komutu gönderildi." << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};