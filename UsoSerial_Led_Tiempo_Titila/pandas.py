import pandas as pd

# Definimos un color de referencia (Rojo anaranjado) y sus valores en distintos formatos
data = [
    ["HEX", "#FF5733", "Formato digital compacto usado en web"],
    ["RGB", "rgb(255, 87, 51)", "Modelo aditivo para pantallas"],
    ["HSB", "hsb(14°, 80%, 100%)", "Matiz, saturación y brillo"],
    ["HSL", "hsl(14°, 100%, 60%)", "Matiz, saturación y luminosidad"],
    ["CMYK", "cmyk(0%, 66%, 80%, 0%)", "Modelo sustractivo para impresión"],
    ["LAB", "lab(62.74, 55.27, 44.22)", "Modelo perceptual independiente del dispositivo"],
    ["HKS", "HKS 7", "Referencia de impresión offset (Europa)"],
    ["Copic", "R27", "Código de marcador para ilustración"],
    ["Prismacolor", "Crimson Red 924", "Referencia de lápiz/marcador físico"]
]

df = pd.DataFrame(data, columns=["Formato / Sistema", "Ejemplo", "Uso principal"])

import caas_jupyter_tools  # noqa: E402
caas_jupyter_tools.display_dataframe_to_user(name="Comparativa de formatos de color", dataframe=df)
