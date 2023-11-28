import serial
import logging
import queue

class SerialCom:
    """Handles serial communication with an Arduino."""
    
    def __init__(self, port, baud_rate):
        try:
            self.ser = serial.Serial(port, baud_rate)
            self.message_queue = queue.Queue()
            logging.info(f"Serial connection established on port {port}")
        except serial.SerialException as e:
            logging.error(f"Error: Unable to open serial port - {e}")
            # Handle the exception or exit gracefully

    def send_data(self, data):
        """Queue data to be sent over the serial connection."""
        self.message_queue.put(data)

    def process_queue(self):
        """Send queued data over the serial connection."""
        while not self.message_queue.empty():
            message = self.message_queue.get()
            self.ser.write(message.encode())

    def close_serial_connection(self):
        """Close the serial connection."""
        self.ser.close()
