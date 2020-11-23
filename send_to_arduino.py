import serial
import time

# The following line is for serial over GPIO
port = "COM6"

ard = serial.Serial(port, 9600, timeout=5)
time.sleep(2)
i = 0

setTemp1 = bytes(str(1), 'utf-8')
setTemp2 = bytes(str(0), 'utf-8')

for i in range(0, 2):  # Represents 1 (right) followed by a 0 (left) received from our SVM model results
    # Serial write section
    if i % 2 == 0: # if we see a 1
        ard.write(setTemp1)
        print("Python value sent: ")
        print(setTemp1)
        time.sleep(5)
    else: # if we see a 0
        ard.write(setTemp2)
        print("Python value sent: ")
        print(setTemp2)
        time.sleep(5)  # with the port open, the response will be buffered
        # so wait a bit longer for response here

    # Serial read section
    msg = ard.read(ard.inWaiting())  # read everything in the input buffer
    print("Message from Arduino: ")
    print(msg)
    time.sleep(5)
