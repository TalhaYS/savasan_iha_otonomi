#include "rclcpp/rclcpp.hpp"
#include "behaviortree_cpp/bt_factory.h"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include "baslangic_gorevi/KalkisYap.hpp"
#include "baslangic_gorevi/QrKonumBilgisiGirildiMi.hpp"
#include "baslangic_gorevi/YeterliYukseklikteMi.hpp"
#include "baslangic_gorevi/Yuksekligi10mArttir.hpp"
#include "siha_gorevi/HedefAramayiAktiflestir.hpp"
#include "siha_gorevi/HedefiOrtala.hpp"
#include "siha_gorevi/HedefTespitEdildiMi.hpp"
#include "siha_gorevi/HedefVurusAlanindaMi.hpp"
#include "siha_gorevi/IstasyonaPaketiGonder.hpp"
#include "siha_gorevi/KilitlenmeSayaciniIlerlet.hpp"
#include "siha_gorevi/Sayac4SaniyeOlduMu.hpp"
#include "siha_gorevi/SonVurulanHedefiKaydet.hpp"
#include "siha_gorevi/ToleransAsildiMi.hpp"
#include "siha_gorevi/ToleransSayaciniIlerlet.hpp"
#include "siha_gorevi/TumSayaclariSifirla.hpp"

// Sınıf başlıkları buraya eklenecek (Gerçek kodda .hpp olarak eklenmelidir)
// #include "baslangic_gorevi/KalkisYap.hpp" vs...

int main(int argc, char **argv)
{
    // ROS 2'yi başlat
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("savasan_iha_main_node");
    RCLCPP_INFO(node->get_logger(), "Otonomi Sistemi Ayaga Kalkiyor...");

    // BT Fabrikasını oluştur
    BT::BehaviorTreeFactory factory;

    // 1. DÜĞÜMLERİ FABRİKAYA KAYDET
    // Başlangıç Görevleri
    factory.registerNodeType<KalkisYap>("KalkisYap");
    factory.registerNodeType<YeterliYukseklikteMi>("YeterliYukseklikteMi");
    factory.registerNodeType<Yuksekligi10mArttir>("Yuksekligi10mArttir");
    factory.registerNodeType<QrKonumBilgisiGirildiMi>("QrKonumBilgisiGirildiMi");

    // SİHA Görevleri
    factory.registerNodeType<HedefTespitEdildiMi>("HedefTespitEdildiMi");
    factory.registerNodeType<HedefiOrtala>("HedefiOrtala");
    factory.registerNodeType<HedefVurusAlanindaMi>("HedefVurusAlanindaMi");
    factory.registerNodeType<KilitlenmeSayaciniIlerlet>("KilitlenmeSayaciniIlerlet");
    factory.registerNodeType<ToleransSayaciniIlerlet>("ToleransSayaciniIlerlet");
    factory.registerNodeType<ToleransAsildiMi>("ToleransAsildiMi");
    factory.registerNodeType<TumSayaclariSifirla>("TumSayaclariSifirla");
    factory.registerNodeType<Sayac4SaniyeOlduMu>("Sayac4SaniyeOlduMu");
    factory.registerNodeType<SonVurulanHedefiKaydet>("SonVurulanHedefiKaydet");
    factory.registerNodeType<IstasyonaPaketiGonder>("IstasyonaPaketiGonder");
    factory.registerNodeType<HedefAramayiAktiflestir>("HedefAramayiAktiflestir");
    // 2. XML DOSYASINI BUL VE YÜKLE
    std::string pkg_path = ament_index_cpp::get_package_share_directory("savasan_iha_pkg");
    std::string xml_file = pkg_path + "/config/gorev_agaci.xml";
    
    auto tree = factory.createTreeFromFile(xml_file);
    BT::Groot2Publisher publisher(tree);

    // 3. OTONOMİ DÖNGÜSÜ
    rclcpp::Rate loop_rate(10); // Saniyede 10 kez çalışsın (10 Hz)
    while (rclcpp::ok()) {
        tree.tickExactlyOnce(); // Ağacı bir tur çalıştır
        rclcpp::spin_some(node); // ROS 2 callback'lerini dinle
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}