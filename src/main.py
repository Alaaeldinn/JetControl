# main.py
from motor_control import MotorController
from serial_com import SerialCom
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)

motor_controller = MotorController()

# Create an instance of JetsonToArduinoCommunication
## Choose the Port you will Use
jetson_communication = SerialCom(port='COM4', baud_rate=9600)

try:
    # Example: Move motors based on control input until interrupted
    command  = motor_controller.move_motors_with_control_input()
    jetson_communication.send_data(command)
finally:
    command = jetson_communication.close_serial_connection()
    jetson_communication.send_data(command)
