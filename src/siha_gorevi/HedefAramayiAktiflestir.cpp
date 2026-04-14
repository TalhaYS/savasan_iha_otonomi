#include "HedefAramayiAktiflestir.hpp"
#include <iostream> // std::cout için eklendi

// Yapıcı (Constructor) fonksiyon
HedefAramayiAktiflestir::HedefAramayiAktiflestir(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları (Dışarıdan veri almıyorsa boş döner)
BT::PortsList HedefAramayiAktiflestir::providedPorts() { 
    return {}; 
}

// Otonom arama/devriye mantığının işlediği yer
BT::NodeStatus HedefAramayiAktiflestir::tick() {
    // --------------------------------------------------------
    // TODO (Ekip Arkadaşı): 
    // Otopilota (yaw) kendi etrafında yavaşça dönme komutu ver.
    // Veya önceden belirlenmiş arama (devriye) rotasına gitmesini sağla.
    // --------------------------------------------------------
    
    std::cout << "[SİHA] Ufuk temiz. Hedef aranıyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}