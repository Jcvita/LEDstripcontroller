import time
import random
import serial

ser = serial.Serial('/dev/ttyS0', 115200)

def send_static_rgb(r: str, g: str, b: str):
    r = '00'[:3-len(r)] + r
    g = '00'[:3-len(r)] + g  # padding for data formatting
    b = '00'[:3-len(r)] + b

    ser.write(f"RGB>{r + g + b}")

def party_mode(freq: int):
    while True:
        send_static_rgb(str(random.randint(0, 254)), str(random.randint(0, 254)), str(random.randint(0, 255)))
        time.sleep(1000/freq)
        