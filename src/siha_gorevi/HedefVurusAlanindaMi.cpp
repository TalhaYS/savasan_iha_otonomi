#include "HedefVurusAlanindaMi.hpp"

// Yapıcı fonksiyon
HedefVurusAlanindaMi::HedefVurusAlanindaMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

// Port tanımlamaları 
BT::PortsList HedefVurusAlanindaMi::providedPorts() {
    return {}; 
}

// Otonom vuruş alanı kontrol mekanizmasının işlediği yer
BT::NodeStatus HedefVurusAlanindaMi::tick() {
    // --------------------------------------------------------
    // TODO: OpenCV veya YOLO'dan gelen "hedefin piksel koordinatlarını" al.
    // Görüntünün merkezindeki o %5'lik sanal kutunun içinde mi diye kontrol et.
    // Aynı zamanda hedef, kara listedeki bir hedef Mİ diye kontrol et!
    // --------------------------------------------------------
    
    bool alanin_icinde = true; // ROS 2 / Görüntü işleme verisine göre değişecek

    if(alanin_icinde) {
        return BT::NodeStatus::SUCCESS; // "Yes" oku
    } else {
        return BT::NodeStatus::FAILURE; // "No" oku (Toleransa düşürür)
    }
}