#include "ToleransAsildiMi.hpp"
#include <iostream>

// Yapıcı fonksiyon
ToleransAsildiMi::ToleransAsildiMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları
BT::PortsList ToleransAsildiMi::providedPorts() {
    return { BT::InputPort<double>("tolerans_suresi_in") };
}

// Otonom tolerans kontrol mekanizmasının işlediği yer
BT::NodeStatus ToleransAsildiMi::tick() {
    double sure = 0.0;
    
    // Blackboard'dan anlık tolerans süresini çek
    getInput("tolerans_suresi_in", sure);

    // Eğer süre 1 saniyeye ulaştıysa veya geçtiyse
    if (sure >= 1.0) {
        std::cout << "[HATA] 1 Saniyelik tolerans aşıldı, kilit bozuldu!" << std::endl;
        return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku
    }
    
    return BT::NodeStatus::FAILURE; // "No" oku
}