#include "SonVurulanHedefiKaydet.hpp"
#include <iostream>

// Yapıcı fonksiyon
SonVurulanHedefiKaydet::SonVurulanHedefiKaydet(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları
BT::PortsList SonVurulanHedefiKaydet::providedPorts() {
    return { 
        BT::InputPort<int>("anlik_hedef_id"),
        BT::OutputPort<int>("son_vurulan_id") 
    };
}

// Otonom kayıt mekanizmasının işlediği yer
BT::NodeStatus SonVurulanHedefiKaydet::tick() {
    int hedef_id;
    
    // Eğer porttan anlık hedef ID'sini okuyamazsak hata döndür
    if (!getInput("anlik_hedef_id", hedef_id)) {
        return BT::NodeStatus::FAILURE;
    }

    // --------------------------------------------------------
    // TODO: Bu hedef_id'yi "son_vurulan_id" olarak Blackboard'a yaz.
    // --------------------------------------------------------
    
    // Veriyi Blackboard'a yaz
    setOutput("son_vurulan_id", hedef_id);
    
    std::cout << "[SİHA] " << hedef_id << " numaralı uçak vuruldu. Bir sonraki hedef farklı olmalı!" << std::endl;
    
    return BT::NodeStatus::SUCCESS;
}