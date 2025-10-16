import tkinter as tk
import threading
import time
import serial

# --- CONFIGURAR EL PUERTO SERIAL ---
# Ajustá el nombre del puerto según tu sistema (ej: "COM3" en Windows, "/dev/ttyUSB0" en Linux)
arduino = serial.Serial('COM5', 9600, timeout=1)

# --- FUNCIONES ---
def leer_serial():
    """Lee el puerto serie continuamente en un hilo separado."""
    global ultimo_valor
    while True:
        if arduino.in_waiting > 0:
            try:
                linea = arduino.readline().decode('utf-8').strip()
                if linea:
                    ultimo_valor = linea
            except:
                pass
        time.sleep(0.1)

def actualizar_label():
    """Actualiza el texto del label con el valor más reciente."""
    label_valor.config(text=f"Lectura: {ultimo_valor}")
    ventana.after(200, actualizar_label)  # Repite cada 200 ms

# --- INTERFAZ TKINTER ---
ventana = tk.Tk()
ventana.title("Lectura Arduino en Tiempo Real")

label_titulo = tk.Label(ventana, text="Valor del sensor:", font=("Arial", 14))
label_titulo.pack(pady=10)

label_valor = tk.Label(ventana, text="Esperando datos...", font=("Consolas", 18, "bold"))
label_valor.pack(pady=10)

ultimo_valor = "—"

# Iniciar hilo de lectura serial
hilo_serial = threading.Thread(target=leer_serial, daemon=True)
hilo_serial.start()

# Iniciar actualización de la interfaz
actualizar_label()

ventana.mainloop()
