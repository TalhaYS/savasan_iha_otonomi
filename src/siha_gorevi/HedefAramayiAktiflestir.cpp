#include "HedefAramayiAktiflestir.hpp"
#include <iostream>

// Yapıcıfonksiyon
HedefAramayiAktiflestir::HedefAramayiAktiflestir(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları
BT::PortsList HedefAramayiAktiflestir::providedPorts() { 
    return {}; 
}

// Otonom arama/devriye mantığının işlediği yer
BT::NodeStatus HedefAramayiAktiflestir::tick() {
    // --------------------------------------------------------
    // TODO: 
    // Otopilota kendi etrafında yavaşça dönme komutu ver.
    // Veya önceden belirlenmiş arama rotasına gitmesini sağla.
    // --------------------------------------------------------
    
    std::cout << "[SİHA] Ufuk temiz. Hedef aranıyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}