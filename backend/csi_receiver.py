# csi_receiver.py
# UDP + signal processing + MQTT

import socket
import json
import paho.mqtt.client as mqtt
from config import THRESHOLDS

# UDP setup
UDP_IP = "0.0.0.0"
UDP_PORT = 5005
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

# MQTT setup
mqtt_client = mqtt.Client()
mqtt_client.connect("localhost", 1883, 60)

def process_csi_data(data):
    # Placeholder for signal processing
    # Implement CSI data processing here
    processed_data = data  # Dummy processing
    return processed_data

def main():
    print("CSI Receiver started...")
    while True:
        data, addr = sock.recvfrom(1024)
        processed = process_csi_data(data)
        mqtt_client.publish("csi/data", json.dumps(processed))

if __name__ == "__main__":
    main()
