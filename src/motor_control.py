# motor_control.py

import time

class MotorController:
    """Controls motors based on input."""
    
    def __init__(self):
        pass
    
    def get_control_input(self):
        """Placeholder for control input abstraction (e.g., joystick input)."""
        return 100, 50  # Example values

    def control_motors(self, front_left, front_right, rear_left, rear_right):
        """Generate motor control command."""
        command = f"FL{front_left}FR{front_right}RL{rear_left}RR{rear_right}\n"
        return command

    def move_motors_with_control_input(self):
        """Move motors based on control input until interrupted."""
        try:
            while True:
                left_speed, right_speed = self.get_control_input()
                self.control_motors(left_speed, left_speed, right_speed, right_speed)
        except KeyboardInterrupt:
            # Stop motors when interrupted (e.g., by pressing Ctrl+C)
            self.control_motors(0, 0, 0, 0)
