#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class ToleransSayaciniIlerlet : public BT::SyncActionNode
{
public:
    ToleransSayaciniIlerlet(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("tolerans_suresi_in"),
                 BT::OutputPort<double>("tolerans_suresi_out") };
    }

    BT::NodeStatus tick() override
    {
        double anlik_tolerans = 0.0;
        getInput("tolerans_suresi_in", anlik_tolerans);

        // TODO (Ekip Arkadaşı): 
        // Geçen zamanı hesaplayıp tolerans süresine ekle.
        double yeni_tolerans = anlik_tolerans + 0.1; 
        setOutput("tolerans_suresi_out", yeni_tolerans);
        
        return BT::NodeStatus::SUCCESS;
    }
};