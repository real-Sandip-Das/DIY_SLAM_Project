import socket_py as sck
import tkinter as tk

root = tk.Tk()
root.title("Robot Control Demo")

canvas = tk.Canvas(root, width=200, height=200)
canvas.pack()

key_squares = {'W': None, 'A': None, 'S': None, 'D': None} # Dictionary to map keys to squares
key_state = {'W':False, 'A':False, 'S': False, 'D': False}
cur_key = 'J'

# Function to handle key press events
def key_press(event):
    key = event.char.upper()
    if key in key_squares:
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
        sck.send(cur_key)
        print(cur_key) #printing the current state for debugging purposes

# Create squares and labels
for key, (x, y) in zip(key_squares, [(75, 25), (25, 75), (75, 75), (125, 75)]):
    square_id = canvas.create_rectangle(x, y, x+50, y+50, fill="white")
    canvas.create_text(x+25, y+25, text=key, font=("Helvetica", 20))
    key_squares[key] = square_id

# Bind key press and release events
root.bind("<KeyPress>", key_press)

print(cur_key)
root.mainloop()
