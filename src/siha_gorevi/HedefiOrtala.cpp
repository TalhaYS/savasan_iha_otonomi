#include "HedefiOrtala.hpp"
#include <iostream> 

// Yapıcı fonksiyon
HedefiOrtala::HedefiOrtala(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları
BT::PortsList HedefiOrtala::providedPorts() { 
    return {}; 
}

// Otonom ortalama ve PID mantığının işlediği yer
BT::NodeStatus HedefiOrtala::tick() {
    // --------------------------------------------------------
    // TODO: 
    // Hedefin piksel koordinatları ile ekranın merkezi arasındaki farkı bul.
    // PID algoritması ile otopilota dönüş komutu gönder.
    // --------------------------------------------------------
    
    std::cout << "[SİHA] Hedef takip ediliyor, ortalanıyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}