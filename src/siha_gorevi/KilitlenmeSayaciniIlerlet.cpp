#include "KilitlenmeSayaciniIlerlet.hpp"

// Yapıcı (Constructor) fonksiyonun içi
KilitlenmeSayaciniIlerlet::KilitlenmeSayaciniIlerlet(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

// Hangi portları kullanacağımızın tanımı
BT::PortsList KilitlenmeSayaciniIlerlet::providedPorts() {
    return { BT::InputPort<double>("kilit_suresi_in"),
             BT::OutputPort<double>("kilit_suresi_out") };
}

// Asıl mantığın işlediği tick fonksiyonunun içi
BT::NodeStatus KilitlenmeSayaciniIlerlet::tick() {
    double anlik_sure = 0.0;
    getInput("kilit_suresi_in", anlik_sure);

    // --------------------------------------------------------
    // TODO (Ekip Arkadaşı): 
    // 1. Önceki tick'ten bu yana geçen zamanı (delta_time) hesapla.
    // 2. anlik_sure değerine bu zamanı ekle ve kilit_suresi_out olarak tahtaya yaz.
    // 3. Tolerans sayacını sıfırla (çünkü hedef tekrar alana girdi).
    // --------------------------------------------------------
    
    double yeni_sure = anlik_sure + 0.1; // Örnek artış
    setOutput("kilit_suresi_out", yeni_sure);
    
    return BT::NodeStatus::SUCCESS;
}