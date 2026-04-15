#include "HedefTespitEdildiMi.hpp"

// Yapıcı fonksiyon
HedefTespitEdildiMi::HedefTespitEdildiMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları
BT::PortsList HedefTespitEdildiMi::providedPorts() {
    return { BT::InputPort<int>("son_vurulan_id") }; 
}

// Otonom hedef tespit mekanizmasının işlediği yer
BT::NodeStatus HedefTespitEdildiMi::tick() {
    int son_hedef = -1;
    
    // Eğer porttan bir ID gelirse, bunu son_hedef değişkenine kaydet
    getInput("son_vurulan_id", son_hedef);

    // --------------------------------------------------------
    // TODO: 
    // YOLO veya OpenCV'den gelen hedefleri kontrol et.
    // Eğer ekranda bir İHA varsa ve bu İHA'nın ID'si "son_hedef" DEĞİLSE tespit edildi de.
    // --------------------------------------------------------
    
    bool hedef_var_mi = false; // Görüntü işleme sonucuna göre değişecek

    if (hedef_var_mi) {
        return BT::NodeStatus::SUCCESS;
    }
    
    return BT::NodeStatus::FAILURE; // Yoksa aramaya geçecek
}