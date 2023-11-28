#!/usr/bin/env python3

import rospy
from motor_control import MotorController
from serial_com import SerialCom
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)

def main():
    rospy.init_node('motor_control_node', anonymous=True)

    motor_controller = MotorController()

    # Create an instance of JetsonToArduinoCommunication
    ## Choose the Port you will Use
    jetson_communication = SerialCom(port='/dev/ttyUSB0', baud_rate=9600)  # Update the port accordingly

    try:
        # Example: Move motors based on control input until interrupted
        command = motor_controller.move_motors_with_control_input()
        jetson_communication.send_data(command)
    finally:
        command = jetson_communication.close_serial_connection()
        jetson_communication.send_data(command)

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
