#include "Yuksekligi10mArttir.hpp"
#include <iostream> // std::cout için eklendi

// Yapıcı (Constructor) fonksiyon
Yuksekligi10mArttir::Yuksekligi10mArttir(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları (Dışarıdan anlık irtifayı al, yeni irtifayı dışarı ver)
BT::PortsList Yuksekligi10mArttir::providedPorts() {
    return { BT::InputPort<double>("guncel_hedef_irtifa"),
             BT::OutputPort<double>("yeni_hedef_irtifa") };
}

// Otonom irtifa artırma mantığının işlediği yer
BT::NodeStatus Yuksekligi10mArttir::tick() {
    double irtifa = 0.0;
    
    // Eğer porttan veri alamazsak varsayılan bir irtifa belirleyebiliriz
    if (!getInput("guncel_hedef_irtifa", irtifa)) {
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