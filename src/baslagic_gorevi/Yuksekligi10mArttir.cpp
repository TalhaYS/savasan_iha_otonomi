#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

class Yuksekligi10mArttir : public BT::SyncActionNode
{
public:
    Yuksekligi10mArttir(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}

    // Blackboard'dan güncel hedef irtifayı okuyup, yenisini yazacağız
    static BT::PortsList providedPorts() {
        return { BT::InputPort<double>("guncel_hedef_irtifa"),
                 BT::OutputPort<double>("yeni_hedef_irtifa") };
    }

    BT::NodeStatus tick() override
    {
        double irtifa = 0.0;
        if (!getInput("guncel_hedef_irtifa", irtifa)) {
            // Eğer porttan veri alamazsak varsayılan bir irtifa belirleyebiliriz
            irtifa = 0.0; 
        }

        // İrtifayı 10 metre artır
        double yeni_irtifa = irtifa + 10.0;

        // --------------------------------------------------------
        // TODO (Ekip Arkadaşı): 
        // 1. Otopilota (mavros) yeni_irtifa değerini setpoint (gitmesi gereken hedef) olarak gönder.
        // --------------------------------------------------------
        
        // Yeni değeri Blackboard'a yaz ki diğer düğümler de bilsin
        setOutput("yeni_hedef_irtifa", yeni_irtifa);

        std::cout << "[YÜKSELİŞ] İrtifa 10m artırılıyor. Yeni Hedef: " << yeni_irtifa << " metre." << std::endl;
        
        return BT::NodeStatus::SUCCESS;
    }
};