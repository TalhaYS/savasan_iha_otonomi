#include "YeterliYukseklikteMi.hpp"

// Yapıcı (Constructor) fonksiyon
YeterliYukseklikteMi::YeterliYukseklikteMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları (Dışarıdan "hedef_irtifa" değerini alıyoruz)
BT::PortsList YeterliYukseklikteMi::providedPorts() {
    return { BT::InputPort<double>("hedef_irtifa") }; 
}

// Otonom irtifa kontrol mekanizmasının işlediği yer
BT::NodeStatus YeterliYukseklikteMi::tick() {
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