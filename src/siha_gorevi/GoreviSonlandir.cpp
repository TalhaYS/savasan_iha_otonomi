#include "GoreviSonlandir.hpp"
#include <iostream>

GoreviSonlandir::GoreviSonlandir(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList GoreviSonlandir::providedPorts() { return {}; }

BT::NodeStatus GoreviSonlandir::tick() {
    // --------------------------------------------------------
    // TODO (Ekip Arkadaşı): 
    // İHA'ya "Return to Launch" (RTL) veya "Land" komutu gönder.
    // --------------------------------------------------------
    
    std::cout << "[GÖREV BİTTİ] Kilitlenme başarılı, görev tamamlandı. Eve dönüş başlatılıyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}