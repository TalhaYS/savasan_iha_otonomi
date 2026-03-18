#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class HedefVurusAlanindaMi : public BT::ConditionNode
{
public:
    HedefVurusAlanindaMi(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    static BT::PortsList providedPorts() { return {}; }

    BT::NodeStatus tick() override
    {
        // --------------------------------------------------------
        // TODO: OpenCV veya YOLO'dan gelen "hedefin piksel koordinatlarını" al.
        // Görüntünün merkezindeki o %5'lik sanal kutunun içinde mi diye kontrol et.
        // Aynı zamanda hedef, kara listedeki (daha önce vurulan) bir hedef Mİ diye kontrol et!
        // --------------------------------------------------------
        
        bool alanin_icinde = true; // ROS 2 / Görüntü işleme verisine göre değişecek

        if(alanin_icinde) {
            return BT::NodeStatus::SUCCESS; // "Yes" oku
        } else {
            return BT::NodeStatus::FAILURE; // "No" oku (Toleransa düşürür)
        }
    }
};