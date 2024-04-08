from gui_visualizer import SLAM_Map
import socket_py as sck
import tkinter as tk
import tkinter as tk


UDP_object = sck.UDP_connection()

root = tk.Tk()
root.title("Robot Control Window")

canvas = tk.Canvas(root, width=200, height=200)
canvas.pack()

#TODO: measure the time taken by the car to rotate ninety degrees

def read_linear_distance():
    UDP_object.send('M')
    message = UDP_object.receive()
    _, dist_str = message.split(' ')
    return float(dist_str)

key_squares = {'W': None, 'A': None, 'S': None, 'D': None} # Dictionary to map keys to squares
key_state = {'W': None, 'A': None, 'S': None, 'D': None}
key_linear_movement = ['W', 'S']
key_rotational_movement = ['A', 'D']
cur_key = 'J'

first_key_press = True

# Function to handle key press events
def key_press(event):
    global Map
    global first_key_press
    key = event.char.upper()
    if key in key_squares:
        if first_key_press:
            UDP_object.send('Q')
            Map.scan(UDP_object, False)
            global lin_dist
            lin_dist = read_linear_distance()
            cur_movement_mode = key_linear_movement
        key_state[key] ^= True
        if key_state[key]:
            fill_color = "gray"
            cur_key = key
        else:
            fill_color = "white"
            cur_key = 'J'
        for k in key_state:
            if(key_state[k] and k != key):
                key_state[k] = False
                canvas.itemconfig(key_squares[k], fill="white")
        canvas.itemconfig(key_squares[key], fill=fill_color)
        if cur_key == 'J':
            if cur_movement_mode == key_linear_movement:
                cur_dist = read_linear_distance()
                Map.robot.move_linear(lin_dist-cur_dist)
                lin_dist = cur_dist
            Map.scan(UDP_object, True)
        if cur_key in key_linear_movement:
            cur_movement_mode = key_linear_movement
        if cur_key in key_rotational_movement:
            if cur_key == 'A':
                Map.robot.rotate(90)
            elif cur_key == 'D':
                Map.robot.rotate(-90)
            cur_movement_mode = key_rotational_movement
        UDP_object.send(cur_key)
        print(cur_key) #printing the current state for debugging purposes
        first_key_press = False

# Create squares and labels
for key, (x, y) in zip(key_squares, [(75, 25), (25, 75), (75, 75), (125, 75)]):
    square_id = canvas.create_rectangle(x, y, x+50, y+50, fill="white")
    canvas.create_text(x+25, y+25, text=key, font=("Helvetica", 20))
    key_squares[key] = square_id

# Bind key press and release events
root.bind("<KeyPress>", key_press)

Map = SLAM_Map()
print(cur_key)
UDP_object.send(cur_key)
root.mainloop()
