#include "behaviortree_cpp/condition_node.h"
#include "rclcpp/rclcpp.hpp"

class QrKonumBilgisiGirildiMi : public BT::ConditionNode
{
public:
    QrKonumBilgisiGirildiMi(const std::string& name, const BT::NodeConfig& config)
        : BT::ConditionNode(name, config) {}

    // Konum geldiyse bu konumu Blackboard'a yazalım ki dalış algoritması bilsin
    static BT::PortsList providedPorts() {
        return { BT::OutputPort<std::string>("qr_hedef_koordinat") }; 
    }

    BT::NodeStatus tick() override
    {
        // --------------------------------------------------------
        // TODO (Ekip Arkadaşı): 
        // 1. Yarışma sunucusuna bağlanan ROS 2 Subscriber'ından veri geldi mi kontrol et.
        // 2. Eğer geçerli bir QR koordinatı elimizde varsa "veri_geldi = true" yap ve 
        //    koordinatları değişkene aktar.
        // --------------------------------------------------------
        
        bool veri_geldi = false; // ROS 2'den gelen duruma göre güncellenecek
        std::string koordinat_verisi = ""; 

        if (veri_geldi) {
            // Koordinatı diğer düğümlerin kullanması için tahtaya yaz
            setOutput("qr_hedef_koordinat", koordinat_verisi);
            std::cout << "[KAMİKAZE] QR Konum bilgisi alındı, Kamikaze moduna geçiliyor!" << std::endl;
            return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku
        } else {
            std::cout << "[SİHA] QR bilgisi yok, SİHA (Hava-Hava) devriyesine devam..." << std::endl;
            return BT::NodeStatus::FAILURE; // Şemadaki "No" oku (SİHA'ya geçer)
        }
    }
};