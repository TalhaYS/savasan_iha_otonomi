#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class HedefiOrtala : public BT::SyncActionNode
{
public:
    HedefiOrtala(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() { return {}; }

    BT::NodeStatus tick() override
    {
        // TODO (Ekip Arkadaşı): 
        // Hedefin piksel koordinatları ile ekranın merkezi (örn: 640x360) arasındaki farkı (error) bul.
        // PID algoritması ile otopilota (mavros/setpoint_velocity) dönüş komutu (Yaw/Pitch) gönder.
        
        std::cout << "[SİHA] Hedef takip ediliyor, ortalanıyor..." << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};