import time
import rospy
from sensor_msgs.msg import Joy

class MotorController:
    """Controls motors based on input."""

    def __init__(self):
        rospy.init_node('motor_controller_node', anonymous=True)
        self.forward_speed = 0
        self.backward_speed = 0
        self.left_speed = 0
        self.right_speed = 0
        rospy.Subscriber("joy", Joy, self.joy_callback)

    def joy_callback(self, joy_msg):
        """Callback function for processing joystick input."""
        # Assuming axes 1 and 4 control left and right speeds, and axes 0 and 3 control forward and backward speeds
        if len(joy_msg.axes) >= 5:
            self.left_speed = int(100 * joy_msg.axes[1])
            self.right_speed = int(100 * joy_msg.axes[4])
            self.forward_speed = int(100 * joy_msg.axes[0])
            self.backward_speed = int(100 * joy_msg.axes[3])

    def get_control_input(self):
        """Return the current joystick input."""
        forward = self.forward_speed - self.backward_speed
        left = self.left_speed
        right = self.right_speed
        return forward, left, right

    def control_motors(self, forward, left, right):
        """Generate motor control command."""
        # Adjust the command format based on your motor control requirements
        command = f"Forward:{forward} Left:{left} Right:{right}\n"
        return command

    def move_motors_with_control_input(self):
        """Move motors based on control input until interrupted."""
        try:
            while not rospy.is_shutdown():
                forward, left, right = self.get_control_input()
                motor_command = self.control_motors(forward, left, right)
                # Send the motor command as needed (e.g., via SerialCom)
                time.sleep(0.1)  # Adjust the sleep time based on your needs
        except KeyboardInterrupt:
            # Stop motors when interrupted (e.g., by pressing Ctrl+C)
            self.control_motors(0, 0, 0)
