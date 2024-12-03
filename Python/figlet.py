import sys
import random
from pyfiglet import Figlet

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) == 1:
    font = random.choice(fonts)

elif len(sys.argv) == 3:
    arg = sys.argv[1].lower()
    font = sys.argv[2].lower()

    if arg != '-f' or arg != '--font' and font not in fonts:
        print('Invalid usage')
        sys.exit(1)

else:
    print('Invalid usage')
    sys.exit(1)


text = input('Input: ').strip()
figlet.setFont(font=font)
print(figlet.renderText(text))
sys.exit(0)