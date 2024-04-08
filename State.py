import numpy as np
import cv2 as cv

angle_limit = 180
image_length = 1280 #along x direction
image_width = 720 #along y direction
scale = 10 #centimeters(in the real world) per pixel length
sensor_dist_cm = 2 #TODO: measure the distance of the sensor to the midpoint of the 2 wheels

def round_up(x: float) -> int:
    return int(np.floor(x+0.5))

class State:
    def __init__(self):
        self.x = 1280//2
        self.y = 720//2
        self.theta_deg = 0 #zero means along +ve x axis, ninety means along +ve y axis
        #position of the midpoint of the two wheels
        #self.theta_deg: orientation of the line joining (self.x, self.y) and the Sensor's position
        self.sensor_dist = scale*sensor_dist_cm
        self.map = np.zeros((image_width, image_length, 3), dtype=np.uint8)
    def plot(self, theta_rel_deg, dist, is_temporary: bool):
        theta_abs_deg = (self.theta_deg+theta_rel_deg)%360
        theta_abs_rad = theta_abs_deg*np.pi/180
        self_theta_rad = self.theta_deg*np.pi/180
        point_x = round_up(self.x+self.sensor_dist*np.cos(self_theta_rad)+dist*np.cos(theta_abs_rad))
        point_y = round_up(self.y+self.sensor_dist*np.sin(self_theta_rad)+dist*np.sin(theta_abs_rad))
        if is_temporary:
            cv.circle(self.temp_map, (point_x, point_y), 1, (0, 0, 255), thickness=1)
        else:
            cv.circle(self.map, (point_x, point_y), 1, (255, 0, 0), thickness=1)
    def move_linear(self, dist: float):
        cur_theta_rad = self.theta_deg*np.pi/180
        self.x += dist*np.cos(cur_theta_rad)
        self.y += dist*np.sin(cur_theta_rad)
    def rotate(self, theta_deg:int):
        self.theta_deg += theta_deg
        self.theta_deg %= 360
    def render(self, show_temp: bool, latest_scan):
        #show_temp: show the temporary map while adjusting the slider in the Tkinter GUI
        if show_temp:
            self.temp_map = self.map.copy()
        for (angle_deg, dist) in latest_scan:
            self.plot(angle_deg, dist, show_temp)
        if show_temp:
            cv.imshow("Map Display", self.temp_map)
        else:
            cv.imshow("Map Display", self.map)
