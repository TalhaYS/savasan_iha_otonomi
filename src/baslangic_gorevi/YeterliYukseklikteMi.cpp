#include "YeterliYukseklikteMi.hpp"

// Yapıcı fonksiyon
YeterliYukseklikteMi::YeterliYukseklikteMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları
BT::PortsList YeterliYukseklikteMi::providedPorts() {
    return { BT::InputPort<double>("hedef_irtifa") }; 
}

// Otonom irtifa kontrol mekanizmasının işlediği yer
BT::NodeStatus YeterliYukseklikteMi::tick() {
    // --------------------------------------------------------
    // TODO: 
    // İHA'nın anlık irtifa sensörünü oku.
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