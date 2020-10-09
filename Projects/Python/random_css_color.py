"""
Usage: python random_css_color.py

This simple script can be run from the command line, and prints a random color
as RGB tuple and a hex string.

Imports:
    random as random
"""
import random


if __name__ == "__main__":
    ints = [random.randint(0,255) for _ in range(3)]
    hexs = [hex(x)[2:] for x in ints]
    hex_str = "#" + "".join([hs.zfill(2) for hs in hexs])

    print("Random color as RGB tuple: ", tuple(ints))
    print("Random color as hex string: ", hex_str)