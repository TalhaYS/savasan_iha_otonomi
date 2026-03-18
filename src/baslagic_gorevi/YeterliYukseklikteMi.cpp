#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class YeterliYukseklikteMi : public BT::ConditionNode
{
public:
    YeterliYukseklikteMi(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("hedef_irtifa") }; // XML'den hedef irtifayı alabilir
    }

    BT::NodeStatus tick() override
    {
        // --------------------------------------------------------
        // TODO (Ekip Arkadaşı): 
        // İHA'nın anlık irtifa sensörünü (Örn: /mavros/global_position/rel_alt) oku.
        // Eğer güncel irtifa >= hedef_irtifa ise SUCCESS döndür.
        // Eğer altındaysa FAILURE döndür.
        // --------------------------------------------------------
        
        bool irtifa_tamam_mi = false; // Buraya ROS 2 mantığı gelecek
        
        if(irtifa_tamam_mi) {
            return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku
        } else {
            return BT::NodeStatus::FAILURE; // Şemadaki "No" oku
        }
    }
};