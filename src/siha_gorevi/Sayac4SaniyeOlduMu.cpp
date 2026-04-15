#include "Sayac4SaniyeOlduMu.hpp"
#include <iostream> // std::cout için eklendi

// Yapıcı fonksiyon
Sayac4SaniyeOlduMu::Sayac4SaniyeOlduMu(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları
BT::PortsList Sayac4SaniyeOlduMu::providedPorts() {
    return { BT::InputPort<double>("kilit_suresi_in") };
}

// Otonom süre kontrol mekanizmasının işlediği yer
BT::NodeStatus Sayac4SaniyeOlduMu::tick() {
    double sure = 0.0;
    
    // Blackboard'dan anlık süreyi çek
    getInput("kilit_suresi_in", sure);

    // Eğer süre 4 saniyeye ulaştıysa veya geçtiyse
    if (sure >= 4.0) {
        std::cout << "[BAŞARI] Hedefe 4 saniye kilitlenildi!" << std::endl;
        return BT::NodeStatus::SUCCESS; // Şemadaki "Yes" oku
    }
    
    return BT::NodeStatus::FAILURE; // "No" oku
}