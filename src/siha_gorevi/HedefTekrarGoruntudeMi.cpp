#include "HedefTekrarGoruntudeMi.hpp"

HedefTekrarGoruntudeMi::HedefTekrarGoruntudeMi(const std::string& name, const BT::NodeConfig& config)
    : BT::ConditionNode(name, config) {}

BT::PortsList HedefTekrarGoruntudeMi::providedPorts() { return {}; }

BT::NodeStatus HedefTekrarGoruntudeMi::tick() {
    // --------------------------------------------------------
    // TODO: 
    // Görüntü işleme topic'inden anlık veriyi kontrol et.
    // Bounding box tekrar ekranda belirdi mi?
    // --------------------------------------------------------
    
    bool tekrar_yakalandi_mi = false; // Görüntü işlemeye göre güncellenecek

    if (tekrar_yakalandi_mi) {
        return BT::NodeStatus::SUCCESS; // Şemada kilide geri dön
    } else {
        return BT::NodeStatus::FAILURE; // Şemada aramaya/serbest uçuşa devam et
    }
}