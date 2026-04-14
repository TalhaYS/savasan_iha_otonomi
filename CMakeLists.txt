cmake_minimum_required(VERSION 3.12)
project(savasan_iha_pkg) # Kendi paketinin adını yazmayı unutma

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. BAĞIMLILIKLARI BULMA
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(ament_index_cpp REQUIRED)

# 2. HPP DOSYALARININ YERİNİ GÖSTERME (GÜNCELLENDİ)
# Artık include yerine src klasörüne bakmasını söylüyoruz
include_directories(
  src
  src/baslangic_gorevi
  src/siha_gorevi
)

  # 3. ÇALIŞTIRILABİLİR DOSYA (EXECUTABLE) OLUŞTURMA
add_executable(otonom_kontrol_node
  src/main.cpp
  
  # Başlangıç Görevi Dosyaları
  src/baslangic_gorevi/KalkisYap.cpp
  src/baslangic_gorevi/QrKonumBilgisiGirildiMi.cpp
  src/baslangic_gorevi/YeterliYukseklikteMi.cpp
  src/baslangic_gorevi/Yuksekligi10mArttir.cpp

  # SİHA Görevi Dosyaları
  src/siha_gorevi/GoreviSonlandir.cpp
  src/siha_gorevi/HedefAramayiAktiflestir.cpp
  src/siha_gorevi/HedefiOrtala.cpp
  src/siha_gorevi/HedefTekrarGoruntudeMi.cpp
  src/siha_gorevi/HedefTespitEdildiMi.cpp
  src/siha_gorevi/HedefVurusAlanindaMi.cpp
  src/siha_gorevi/IstasyonaPaketiGonder.cpp
  src/siha_gorevi/KayipAlgoritmasiniBaslat.cpp
  src/siha_gorevi/KilitlenmeSayaciniIlerlet.cpp
  src/siha_gorevi/Sayac4SaniyeOlduMu.cpp
  src/siha_gorevi/SerbestUcusYap.cpp
  src/siha_gorevi/SonVurulanHedefiKaydet.cpp
  src/siha_gorevi/ToleransAsildiMi.cpp
  src/siha_gorevi/ToleransSayaciniIlerlet.cpp
  src/siha_gorevi/TumSayaclariSifirla.cpp
)

# 4. BAĞIMLILIKLARI KODUMUZA BAĞLAMA
ament_target_dependencies(otonom_kontrol_node
  rclcpp
  behaviortree_cpp
  ament_index_cpp
)

# 5. KURULUM (INSTALL) AYARLARI
install(TARGETS
  otonom_kontrol_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()