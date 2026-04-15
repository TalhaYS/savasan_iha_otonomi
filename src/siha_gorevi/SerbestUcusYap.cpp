#include "SerbestUcusYap.hpp"
#include <iostream>

SerbestUcusYap::SerbestUcusYap(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config) {}

BT::PortsList SerbestUcusYap::providedPorts() { return {}; }

BT::NodeStatus SerbestUcusYap::tick() {
    // --------------------------------------------------------
    // TODO: 
    // Otopilota (Mavros) sıradaki waypoint koordinatını gönder.
    // İHA'nın görev rotasında serbestçe uçmasını sağla.
    // --------------------------------------------------------
    
    std::cout << "[UÇUŞ] Serbest uçuş rotasında (Waypoint) ilerleniyor..." << std::endl;
    return BT::NodeStatus::SUCCESS;
}