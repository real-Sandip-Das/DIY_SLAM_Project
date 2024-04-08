import State
import socket_py as sck

angles = []
distances = []

class SLAM_Map:
    def __init__(self):
        self.robot = State()
    def scan(self, UDP_object: sck.UDP_connection, is_rot: bool):
        angles = []
        distances = []
        i = 0
        while i<181*2:
            message = UDP_object.receive()
            if message:
                # Split the line into angle and distance
                angle_str, distance_str = message.split(' ')
                angle = int(angle_str)
                distance = float(distance_str)

                # Store angle and distance data
                angles.append(angle)
                distances.append(distance)
                plot_data = list(zip(angles, distances))
                if is_rot:
                    self.robot.render()
                i += 1
