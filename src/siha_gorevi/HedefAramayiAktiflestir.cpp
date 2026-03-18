#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class HedefAramayiAktiflestir : public BT::SyncActionNode
{
public:
    HedefAramayiAktiflestir(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() { return {}; }

    BT::NodeStatus tick() override
    {
        // TODO (Ekip Arkadaşı): 
        // Otopilota (yaw) kendi etrafında yavaşça dönme komutu ver.
        // Veya önceden belirlenmiş arama (devriye) rotasına gitmesini sağla.
        
        std::cout << "[SİHA] Ufuk temiz. Hedef aranıyor..." << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};