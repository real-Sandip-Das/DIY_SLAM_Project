import serial
import State

ser = serial.Serial('/dev/ttyUSB0', 9600)
angles = []
distances = []

if __name__ == "__main__":
    robot = State()
    try:
        while True:
            # Read serial data line by line
            line = ser.readline().decode().strip()
            if line:
                # Split the line into angle and distance
                angle_str, distance_str = line.split(',')
                angle = int(angle_str)
                distance = float(distance_str)

                # Store angle and distance data
                angles = []
                distances = []
                angles.append(angle)
                distances.append(distance)
                #Continue from here
                list(zip(angles, distances))

    except KeyboardInterrupt:
        print("Interrupted, closing serial connection...")
        ser.close()
