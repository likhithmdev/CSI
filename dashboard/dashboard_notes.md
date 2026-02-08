# Dashboard Notes

## Overview
This document provides notes for the Node-RED dashboard used in the Non-Contact Patient Monitor project. The dashboard visualizes real-time patient data received via MQTT from the Python backend.

## Key Components
- **MQTT Input Node**: Subscribes to `csi/data` topic to receive processed CSI data.
- **Debug Node**: For testing and monitoring incoming data.
- **Dashboard UI**: Includes charts for heart rate, breathing rate, and temperature.

## Setup Instructions
1. Import `flows.json` into Node-RED.
2. Ensure MQTT broker is running on localhost:1883.
3. Access the dashboard at http://localhost:1880/ui.

## Viva Explanation
- Explain how Node-RED integrates with MQTT for real-time data visualization.
- Discuss the flow of data from ESP32 → Python Backend → Node-RED Dashboard.
