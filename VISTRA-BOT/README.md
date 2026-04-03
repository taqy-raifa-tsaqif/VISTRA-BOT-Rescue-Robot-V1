# **VISTRA-BOT: Visionary Rescue Robot**



\[English] | \[Bahasa Indonesia]



English



VISTRA-BOT is an advanced amphibious rescue robot designed for hazardous environment monitoring and search-and-rescue (SAR) operations. Developed for then KOSSMI 2026 competition, this project focuses on robust wireless control and secure real-time visual telemetry.



Key Features



* Dual-Processing System: Utilizes an ESP32 for motion control and an ESP32-CAM for dedicated video streaming.
* Secure Telemetry: Integrated Web Server with session-based authentication and brute-force protection.
* Wireless Control: High-precision 4-axis movement using a PS3 Controller via Bluetooth HID.
* Dynamic Observation: Dual-servo pan-tilt mechanism for a wide field of view.
* Rescue Payload: Integrated relay module for auxiliary tools (pumps, lights, etc.).



Hardware



&#x20;1. ESP32 DevKit V1

&#x20;2. ESP32-CAM

&#x20;3. L298N Dual H-Bridge

&#x20;4. 2x MG90S/SG90 Servos

&#x20;5. 1-Channel Relay

&#x20;6. PS3 Controller 

&#x20;7. 6v pumps

&#x20;8. 4x 3,2v battery



Bahasa Indonesia



VISTRA-BOT adalah robot penyelamat amfibi canggih yang dirancang untuk pemantauan lingkungan berbahaya dan operasi pencarian dan penyelamatan (SAR). Proyek ini dikembangkan untuk kompetisi KOSSMI 2026, dengan fokus pada kendali nirkabel yang tangguh dan telemetri visual real-time yang aman.



Fitur Utama

* Sistem Dual-Processing: Menggunakan ESP32 untuk kontrol gerak dan ESP32-CAM khusus untuk streaming video.
* Telemetri Aman: Web Server terintegrasi dengan autentikasi berbasis sesi dan perlindungan brute-force.
* Kendali Nirkabel: Pergerakan 4-sumbu presisi tinggi menggunakan Stik PS3 melalui Bluetooth HID.
* Observasi Dinamis: Mekanisme pan-tilt dual-servo untuk bidang pandang yang luas.
* Payload Penyelamatan: Modul relay terintegrasi untuk alat tambahan (pompa, lampu, dll).





Komponen

1. 
2. ESP32 DevKit V1
3. ESP32-CAM
4. L298N Dual H-Bridge
5. 2x Servo MG90S/SG90
6. 1-Channel Relay
7. Stik PS3
8. pompa DC 6v
9. 4x baterai 3,2v





Setup \& Installation / Instalasi



Libraries: Install "**Ps3Controller"** and "**ESP32Servo"** in Arduino IDE.

MAC Address: Sync your PS3 Controller MAC address with the code in "**motor \& servo control"**

Network: Connect to SSID **ESP32-CA**M (Pass: **esp32cam123**) and access "192.168.4.1".

Login: User:**admin** | Pass:**admin123**.





Achievement

Presented and Competed in:

KOSSMI (Kompetisi Sains Siswa Muslim Indonesia) 2026



Developed by Taqy Raifa Tsaqif-@theyoungengineeer.

