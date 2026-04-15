#include "ToleransSayaciniIlerlet.hpp"

// Yapıcı fonksiyon
ToleransSayaciniIlerlet::ToleransSayaciniIlerlet(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Port tanımlamaları
BT::PortsList ToleransSayaciniIlerlet::providedPorts() {
    return { BT::InputPort<double>("tolerans_suresi_in"),
             BT::OutputPort<double>("tolerans_suresi_out") };
}

// Otonom tolerans sayacı mekanizmasının işlediği yer
BT::NodeStatus ToleransSayaciniIlerlet::tick() {
    double anlik_tolerans = 0.0;
    
    // Blackboard'dan anlık süreyi çek
    getInput("tolerans_suresi_in", anlik_tolerans);

    // --------------------------------------------------------
    // TODO: 
    // Geçen zamanı hesaplayıp tolerans süresine ekle.
    // --------------------------------------------------------
    
    double yeni_tolerans = anlik_tolerans + 0.1; 
    
    // Yeni süreyi Blackboard'a yaz
    setOutput("tolerans_suresi_out", yeni_tolerans);
    
    return BT::NodeStatus::SUCCESS;
}