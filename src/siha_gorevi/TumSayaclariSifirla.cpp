#include "TumSayaclariSifirla.hpp"

// Yapıcı (Constructor) fonksiyon
TumSayaclariSifirla::TumSayaclariSifirla(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları (Dışarıya sıfırlanmış değerleri vereceğiz)
BT::PortsList TumSayaclariSifirla::providedPorts() {
    return { BT::OutputPort<double>("kilit_suresi_out"),
             BT::OutputPort<double>("tolerans_suresi_out") };
}

// Otonom sıfırlama mekanizmasının işlediği yer
BT::NodeStatus TumSayaclariSifirla::tick() {
    // Tahtadaki (Blackboard) süreleri 0'la
    setOutput("kilit_suresi_out", 0.0);
    setOutput("tolerans_suresi_out", 0.0);
    
    return BT::NodeStatus::SUCCESS;
}