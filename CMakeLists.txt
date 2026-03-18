cmake_minimum_required(VERSION 3.8)
project(savasan_iha_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Gerekli ROS 2 ve BehaviorTree paketlerini bul
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp REQUIRED)

# Tüm C++ dosyalarımızı tek bir çalıştırılabilir dosyada (savasan_main_node) birleştir
add_executable(savasan_main_node
  src/main.cpp
  src/baslangic_gorevi/KalkisYap.cpp
  src/baslangic_gorevi/YeterliYukseklikteMi.cpp
  src/baslangic_gorevi/Yuksekligi10mArttir.cpp
  src/baslangic_gorevi/QrKonumBilgisiGirildiMi.cpp
  src/siha_gorevi/HedefTespitEdildiMi.cpp
  src/siha_gorevi/HedefiOrtala.cpp
  src/siha_gorevi/HedefVurusAlanindaMi.cpp
  src/siha_gorevi/KilitlenmeSayaciniIlerlet.cpp
  src/siha_gorevi/ToleransSayaciniIlerlet.cpp
  src/siha_gorevi/ToleransAsildiMi.cpp
  src/siha_gorevi/TumSayaclariSifirla.cpp
  src/siha_gorevi/Sayac4SaniyeOlduMu.cpp
  src/siha_gorevi/SonVurulanHedefiKaydet.cpp
  src/siha_gorevi/IstasyonaPaketiGonder.cpp
  src/siha_gorevi/HedefAramayiAktiflestir.cpp
)

# Kütüphane bağlantılarını yap
ament_target_dependencies(savasan_main_node
  rclcpp
  behaviortree_cpp
)

# config klasöründeki XML dosyamızın derleme sonrası çalışma alanına kopyalanması için
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

# Oluşan düğümü kurulum klasörüne at
install(TARGETS savasan_main_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()