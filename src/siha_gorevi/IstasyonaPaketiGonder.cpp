#include "IstasyonaPaketiGonder.hpp"
#include <iostream>
// Yapıcı fonksiyon
IstasyonaPaketiGonder::IstasyonaPaketiGonder(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları 
BT::PortsList IstasyonaPaketiGonder::providedPorts() { 
    return {}; 
}

// Otonom haberleşme mantığının işlediği yer
BT::NodeStatus IstasyonaPaketiGonder::tick() {
    // --------------------------------------------------------
    // TODO: 
    // Yarışma sunucusunun istediği JSON formatındaki paketi hazırla.
    // ROS 2 Publisher ile sunucuya ilet.
    // --------------------------------------------------------
    
    std::cout << "[ATEŞ!] Kilitlenme paketi yarışma sunucusuna gönderildi!" << std::endl;
    return BT::NodeStatus::SUCCESS;
}