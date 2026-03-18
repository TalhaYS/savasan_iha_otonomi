#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class TumSayaclariSifirla : public BT::SyncActionNode
{
public:
    TumSayaclariSifirla(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::OutputPort<double>("kilit_suresi_out"),
                 BT::OutputPort<double>("tolerans_suresi_out") };
    }

    BT::NodeStatus tick() override
    {
        // Tahtadaki (Blackboard) süreleri 0'la
        setOutput("kilit_suresi_out", 0.0);
        setOutput("tolerans_suresi_out", 0.0);
        
        return BT::NodeStatus::SUCCESS;
    }
};