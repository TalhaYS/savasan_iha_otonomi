#include "KayipAlgoritmasiniBaslat.hpp"
#include <iostream>

KayipAlgoritmasiniBaslat::KayipAlgoritmasiniBaslat(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList KayipAlgoritmasiniBaslat::providedPorts() { return {}; }

BT::NodeStatus KayipAlgoritmasiniBaslat::tick() {
    // --------------------------------------------------------
    // TODO (Ekip Arkadaşı): 
    // Hedefin son görüldüğü koordinatları Blackboard'dan çek.
    // O bölgeye doğru genişleyen bir spiral arama (loiter) veya gimbal taraması komutu gönder.
    // --------------------------------------------------------
    
    std::cout << "[KAYIP] Tolerans aşıldı! Son bilinen konuma yönelik kayıp arama manevrası başlatıldı!" << std::endl;
    return BT::NodeStatus::SUCCESS;
}