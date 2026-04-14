#include "HedefiOrtala.hpp"
#include <iostream> // std::cout için eklendi

// Yapıcı (Constructor) fonksiyon
HedefiOrtala::HedefiOrtala(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları (Dışarıdan veri almıyorsa boş döner)
BT::PortsList HedefiOrtala::providedPorts() { 
    return {}; 
}

// Otonom ortalama ve PID mantığının işlediği yer
BT::NodeStatus HedefiOrtala::tick() {
    // --------------------------------------------------------
    // TODO (Ekip Arkadaşı): 
    // Hedefin piksel koordinatları ile ekranın merkezi (örn: 640x360) arasındaki farkı (error) bul.
    // PID algoritması ile otopilota (mavros/setpoint_velocity) dönüş komutu (Yaw/Pitch) gönder.
    // --------------------------------------------------------
    
    std::cout << "[SİHA] Hedef takip ediliyor, ortalanıyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}