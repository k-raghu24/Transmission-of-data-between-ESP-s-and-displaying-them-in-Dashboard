# Transmission of Data Between ESPs and Displaying Them in a Dashboard

## 📌 Project Overview

This project demonstrates wireless communication between ESP microcontrollers and the visualization of transmitted data through a dashboard. The system enables data collected or processed by one ESP device to be transmitted to another ESP device, where it can be received and displayed for monitoring.

The project combines embedded systems, wireless communication, and dashboard visualization to provide a simple and efficient IoT-based monitoring solution.

## ✨ Features

- **ESP-to-ESP Communication:** Enables wireless data transmission between ESP microcontrollers.
- **Data Reception:** Receives transmitted information at the destination ESP device.
- **Dashboard Visualization:** Displays received data through a dashboard interface.
- **Real-Time Monitoring:** Makes transmitted information accessible for convenient monitoring.
- **IoT Integration:** Demonstrates the integration of embedded hardware and a software-based interface.
- **Modular Design:** Can be extended to support additional data types and monitoring applications.

## 🛠️ Technologies Used

- **Hardware:** ESP microcontrollers (ESP32/ESP8266, as applicable)
- **Programming:** Arduino IDE and C/C++
- **Communication:** Wireless communication between ESP devices
- **Dashboard:** Dashboard interface for displaying received data
- **Domain:** Internet of Things (IoT) and Embedded Systems

## ⚙️ System Architecture

The project follows a transmitter–receiver–dashboard workflow:

1. **Data Generation:** The transmitting ESP obtains or prepares the data.
2. **Data Transmission:** The data is sent wirelessly to the receiving ESP.
3. **Data Reception:** The receiving ESP processes the incoming information.
4. **Dashboard Display:** The received data is made available for visualization on the dashboard.
5. **Monitoring:** Users can observe the displayed information through the dashboard interface.

## 🔄 Working Principle

The transmitting ESP sends data to another ESP using the communication method configured in the project. The receiving device obtains the transmitted data and makes it available to the dashboard. This allows information to be monitored through a user-friendly interface instead of relying only on serial monitor output.

## 🚀 Getting Started

### Prerequisites

- ESP development boards
- USB cables and a computer
- Arduino IDE
- Required ESP board package and libraries
- Dashboard files included in the repository
- Appropriate power supplies and connecting wires

### Installation and Setup

1. Clone this repository:

   ```bash
   git clone https://github.com/k-raghu24/Transmission-of-data-between-ESP-s-and-displaying-them-in-Dashboard.git
   ```

2. Open the downloaded project folder.
3. Open the transmitter and receiver source files in Arduino IDE.
4. Install the required board packages and libraries.
5. Configure the communication settings according to the project code.
6. Connect the ESP boards to the computer and upload the corresponding programs.
7. Power on the devices and verify that data is being transmitted and received successfully.
8. Open and configure the dashboard according to the files and instructions provided in the repository.
9. Verify that the received data is displayed correctly on the dashboard.

## 📂 Project Structure

The repository contains the source code and supporting files required to implement ESP-to-ESP communication and dashboard visualization.

- **Transmitter Code:** Handles data transmission from the sending ESP.
- **Receiver Code:** Handles reception and processing of incoming data.
- **Dashboard Files:** Provide the interface for displaying the received data.
- **Supporting Files:** Include any additional configuration or project resources.

*Refer to the repository files for the exact filenames and implementation details.*

## 🎯 Applications

- IoT-based remote monitoring
- Wireless data exchange between embedded devices
- Sensor data visualization
- Embedded system monitoring dashboards
- Smart monitoring and automation systems

## 🔮 Future Enhancements

- Add support for multiple ESP devices.
- Integrate additional sensors and data sources.
- Improve dashboard design and responsiveness.
- Add historical data storage and graphical analysis.
- Implement alerts for specific data conditions.
- Extend the system for remote monitoring over a network.

## 👨‍💻 Author

**Raghu Raman K.**

GitHub: [@k-raghu24](https://github.com/k-raghu24)

## 📄 License

This project is available for learning and educational purposes. Add a suitable open-source license to the repository if you intend to permit reuse and redistribution.
