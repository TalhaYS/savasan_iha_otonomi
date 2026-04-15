#include "KalkisYap.hpp"
#include <iostream>

// Yapıcı (Constructor) fonksiyon
KalkisYap::KalkisYap(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları (Dışarıdan veri almıyorsa boş döner)
BT::PortsList KalkisYap::providedPorts() {
    return {}; 
}

// Otonom kalkış mantığının işlediği yer
BT::NodeStatus KalkisYap::tick() {
    // --------------------------------------------------------
    // TODO: 
    // ROS 2 üzerinden İHA'ya "Takeoff" servisini çağır.
    // Motorları arm et.
    // --------------------------------------------------------
    
    std::cout << "[KALKIŞ] Motorlar arm edildi, kalkış komutu gönderildi." << std::endl;
    return BT::NodeStatus::SUCCESS;
}