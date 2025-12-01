
import time 
import serial
import sys

# ============================================================================
# ARDUINO SERIAL COMMUNICATION DEMO
# ============================================================================

# You should change the port name according to your system
# For Windows, it might be something like 'COM4'
# For MacOS or Linux, it might be something like '/dev/ttyUSB0' or '/dev/cu.usbmodem2101'
# Use check_ports.py to find the correct port
ARDUINO_PORT = '/dev/cu.usbmodem1101'

# Ensure the baud rate matches your Arduino sketch

BAUD_RATE = 115200
TIMEOUT = 0.1

def connect_arduino(port, baudrate, timeout):

	try:
		arduino = serial.Serial(port=port, baudrate=baudrate, timeout=timeout)
		time.sleep(2)  # Wait for Arduino to reset
		print(f"✓ Connected to Arduino on {port} at {baudrate} baud")
		return arduino
	except serial.SerialException as e:
		print(f"✗ Failed to connect: {e}")
		sys.exit(1)

def read_serial_data(arduino):
	#  Read a single line of data from Arduino
	if arduino.in_waiting > 0:
		arduino.flush() 
		data = arduino.read(arduino.in_waiting) # more responsive than readline
		return data.decode('utf-8').rstrip()
	return None

def write_read(arduino, command):
	# Send data to Arduino and read response
	arduino.write(bytes(command, 'utf-8'))
	time.sleep(0.05)
	data = arduino.readline() # Read response from Arduino
	return data.decode('utf-8').rstrip()

def demo_mode_1():
	# Press Ctrl+C to stop
	try:
		while True:
			data = read_serial_data(arduino)
			if data:
				print(f"Received: {data}")
			time.sleep(0.1)
			# Sleep longer for things that don't need constant monitoring
	except KeyboardInterrupt:
		print("\nDemo 1 stopped")

def demo_mode_2():
	try:
		while True:
			command = input("Enter a command (or 'q' to quit): ")
			if command.lower() == 'q':
				break
			value = write_read(arduino, command)
			print(f"Response: {value}")
	except KeyboardInterrupt:
		print("\nDemo 2 stopped")

if __name__ == "__main__":
	try:
		# Connect to Arduino
		arduino = connect_arduino(ARDUINO_PORT, BAUD_RATE, TIMEOUT)
		
		# Choose demo
		print("\nSelect demo mode:")
		print("1. Continuous reading")
		print("2. Send command and receive response")
	
		choice = input("Enter choice (1-2): ")
		
		if choice == '1':
			demo_mode_1()
		elif choice == '2':
			demo_mode_2()
		else:
			print("Invalid choice")
	
	except Exception as e:
		print(f"Error: {e}")
	
	finally:
		if arduino.is_open:
			arduino.close()
			print("Serial connection closed")

# You can only open one serial connection to the Arduino at a time.
# If you have another program (like the Arduino IDE Serial Monitor) open,
# you need to close it before running this script.