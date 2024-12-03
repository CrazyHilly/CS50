from fpdf import FPDF
import sys

name = input("Name: ")

# Creating PDF
pdf = FPDF(orientation="P", unit="mm", format="A4")
pdf.set_title("CS50 Shirtificate")
pdf.add_page()

# Adding title
pdf.set_font('helvetica', '', 50)
pdf.cell(0, 55, "CS50 Shirtificate", align="C", center=True)

pdf.ln(60)

# Adding image
try:
    pdf.image("shirtificate.png", w=pdf.epw, keep_aspect_ratio=True)
except:
    print('Cannon open "shirtificate.png" file')

pdf.ln(-140)

# Adding text
pdf.set_font('helvetica', '', 25)
pdf.set_text_color(255, 255, 255)
pdf.cell(120, 20, f"{name} took CS50", align="C", center=True)

# Creating PDF file
pdf.output("shirtificate.pdf")