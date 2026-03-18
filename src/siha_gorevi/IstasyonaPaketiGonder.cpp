#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class IstasyonaPaketiGonder : public BT::SyncActionNode
{
public:
    IstasyonaPaketiGonder(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() { return {}; }

    BT::NodeStatus tick() override
    {
        // TODO (Ekip Arkadaşı): 
        // Yarışma sunucusunun istediği JSON formatındaki paketi (sistem saati, hedef kordinatı vb.) hazırla.
        // ROS 2 Publisher ile sunucuya ilet.
        
        std::cout << "[ATEŞ!] Kilitlenme paketi yarışma sunucusuna gönderildi!" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};