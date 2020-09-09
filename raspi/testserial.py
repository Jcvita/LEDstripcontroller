'''
testserial.py isn't used for any type of communication during the project but is for testing purposes
'''
import serial
import time

ser = serial.Serial('/dev/ttyUSB0', baudrate=115200)

def main():
    ser.open()
    while ser.inWaiting():
        time.sleep(2000)
        ser.write(b'f')
    print(ser.read().decode())

if __name__ == '__main__':
    main()

