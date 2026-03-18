#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class SonVurulanHedefiKaydet : public BT::SyncActionNode
{
public:
    SonVurulanHedefiKaydet(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { 
            BT::InputPort<int>("anlik_hedef_id"),
            BT::OutputPort<int>("son_vurulan_id") 
        };
    }

    BT::NodeStatus tick() override
    {
        int hedef_id;
        if (!getInput("anlik_hedef_id", hedef_id)) {
            return BT::NodeStatus::FAILURE;
        }

        // TODO: Bu hedef_id'yi "son_vurulan_id" olarak Blackboard'a (Kara Tahta) yaz.
        // Böylece arama algoritması A'yı vurduktan sonra tekrar A'yı görürse pas geçecek, 
        // ama B'yi vurduktan sonra A'yı tekrar görürse vurabilecek.
        setOutput("son_vurulan_id", hedef_id);
        
        std::cout << "[SİHA] " << hedef_id << " numaralı uçak vuruldu. Bir sonraki hedef farklı olmalı!" << std::endl;
        
        return BT::NodeStatus::SUCCESS;
    }
};