#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class HedefTespitEdildiMi : public BT::ConditionNode
{
public:
    HedefTespitEdildiMi(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() {
        return { BT::InputPort<int>("son_vurulan_id") }; // Vurulan uçağı tekrar görmemek için
    }

    BT::NodeStatus tick() override
    {
        int son_hedef = -1;
        getInput("son_vurulan_id", son_hedef);

        // TODO (Ekip Arkadaşı): 
        // YOLO veya OpenCV'den gelen hedefleri (bounding box) kontrol et.
        // Eğer ekranda bir İHA varsa ve bu İHA'nın ID'si "son_hedef" DEĞİLSE tespit edildi de.
        
        bool hedef_var_mi = false; // Görüntü işleme sonucuna göre değişecek

        if (hedef_var_mi) {
            return BT::NodeStatus::SUCCESS;
        }
        return BT::NodeStatus::FAILURE; // Yoksa aramaya geçecek
    }
};