# Practice Problems Repository

Welcome to the Practice Problems Repository! This repository is dedicated to solving programming problems related to various topics such as:

- Search
- Arrays
- Strings
- Maps
- Lists

## Purpose

The main goal of this repository is to provide solutions to these problems in different programming languages. This will help in understanding and comparing how different languages handle similar tasks.

## Contributing

Feel free to contribute by adding new problems, solutions, or improving existing ones.

## Languages Covered

- Python
- Java
- C++


from reportlab.lib.pagesizes import letter
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.units import cm

# Crear el documento
file_path = "/mnt/data/Esfuerzos_Cortantes_por_Torsion.pdf"
doc = SimpleDocTemplate(file_path, pagesize=letter,
                        rightMargin=72, leftMargin=72,
                        topMargin=72, bottomMargin=18)

styles = getSampleStyleSheet()
styleN = styles["Normal"]
styleH = styles["Heading1"]

content = []

# Título
content.append(Paragraph("Esfuerzos cortantes por torsión", styleH))
content.append(Spacer(1, 12))

# Contenido del documento
texto = [
    ("Concepto básico", """
En mecánica de materiales, la torsión es el tipo de carga que hace que un elemento estructural (como un eje o una varilla) gire o se retuerza alrededor de su eje longitudinal. Este fenómeno ocurre comúnmente en ejes de transmisión, llaves de tuercas, tornillos, etc.

Cuando un cuerpo está sometido a torsión, se producen esfuerzos cortantes internos en su sección transversal, los cuales son responsables de resistir el par de torsión aplicado. A diferencia del esfuerzo normal (que actúa perpendicularmente a la sección), el esfuerzo cortante por torsión actúa tangencialmente.
    """),
    
    ("Fórmulas relacionadas", """
Para un eje circular sólido sometido a torsión pura, el esfuerzo cortante τ en un punto a una distancia r del eje se calcula con:

    τ = (T * r) / J

Donde:
- τ: esfuerzo cortante [Pa o N/m²]
- T: torque o momento torsor aplicado [N·m]
- r: distancia desde el eje al punto donde se calcula el esfuerzo [m]
- J: momento polar de inercia de la sección transversal [m⁴]

Para sección circular sólida:

    J = (π * d⁴) / 32

Para sección circular hueca:

    J = (π * (do⁴ - di⁴)) / 32

Para ángulo de giro θ:

    θ = (T * L) / (J * G)

Donde:
- G: módulo de rigidez del material [Pa]
- L: longitud del eje [m]
- θ: ángulo de giro en radianes
    """),

    ("Ejemplo explicativo", """
Un eje circular sólido de acero de 2 cm de diámetro y 1.5 m de longitud está sometido a un torque de 120 N·m. Se pide calcular el esfuerzo cortante máximo.

Datos:
- d = 0.02 m → r = 0.01 m
- T = 120 N·m
- J = π * (0.02)^4 / 32 = 7.854 × 10⁻¹⁰ m⁴

τmáx = (120 * 0.01) / (7.854 × 10⁻¹⁰) ≈ 1.53 × 10⁶ Pa = 1.53 MPa
    """),

    ("Nivel más avanzado", """
El esfuerzo cortante no es uniforme: es cero en el centro del eje y máximo en la superficie externa.

Deformación angular:
    τ = G * γ
Donde γ es la deformación angular en radianes.
    """),

    ("Problema sencillo", """
Un eje circular sólido de aluminio de 3 cm de diámetro y 1.2 m de largo se somete a un torque de 60 N·m.

Datos:
- d = 0.03 m → r = 0.015 m
- J = π * (0.03)^4 / 32 = 7.95 × 10⁻⁹ m⁴
- G = 27 × 10⁹ Pa

1. τmáx = (60 * 0.015) / (7.95 × 10⁻⁹) ≈ 1.13 × 10⁵ Pa = 113 kPa
2. θ = (60 * 1.2) / (7.95 × 10⁻⁹ * 27 × 10⁹) ≈ 0.33 rad ≈ 18.9°
    """),

    ("Aplicaciones en ingeniería", """
- Ejes de transmisión de automóviles
- Tornillos y pernos
- Barras de torsión en suspensión de vehículos
- Llaves y herramientas manuales
- Componentes estructurales sometidos a cargas de torsión
    """)
]

for title, body in texto:
    content.append(Paragraph(f"<b>{title}</b>", styleN))
    content.append(Spacer(1, 6))
    content.append(Paragraph(body.strip().replace("\n", "<br />"), styleN))
    content.append(Spacer(1, 12))

# Crear el PDF
doc.build(content)
file_path
