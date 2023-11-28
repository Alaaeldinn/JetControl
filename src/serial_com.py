# serial_com.py

import serial
import logging

class SerialCom:
    """Handles serial communication with an Arduino."""
    
    def __init__(self, port, baud_rate):
        try:
            self.ser = serial.Serial(port, baud_rate)
            logging.info(f"Serial connection established on port {port}")
        except serial.SerialException as e:
            logging.error(f"Error: Unable to open serial port - {e}")
            # Handle the exception or exit gracefully

    def send_data(self, data):
        """Send data over the serial connection."""
        self.ser.write(data.encode())

    def close_serial_connection(self):
        """Close the serial connection."""
        self.ser.close()
