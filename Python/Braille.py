from __future__ import unicode_literals
import optparse

alphabraille = ['⠁', '⠃', '⠉', '⠙', '⠑', '⠋', '⠛', '⠓', '⠊', '⠚', '⠅', '⠇',
 '⠍', '⠝', '⠕', '⠏', '⠟', '⠗', '⠎', '⠞', '⠥', '⠧', '⠺', '⠭', '⠽', '⠵']
numbraille = ['⠼⠁', '⠼⠃', '⠼⠉', '⠼⠙', '⠼⠑', '⠼⠋', '⠼⠛', '⠼⠓', '⠼⠊', '⠼⠚']
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']

enc = None
dec = None

usage = "usage: %prog -arg"
parser = optparse.OptionParser(usage=usage)

parser.add_option('-e', dest="enc", type="string", help="enc plain text to Braille")
parser.add_option('-d', dest="dec", type="string", help="dec Braille into plain text")


(options, args) = parser.parse_args()
if not options:
    parser.error("incorrect number of arguments")

if options.enc:
    enc = options.enc
if options.dec:
    dec = options.dec.decode('utf8', 'ignore')

def main():
    s = ""
    if enc:
        for n in enc:
            if n in alphabet:
                s += alphabraille[alphabet.index(n)]
            elif n in nums:
                s += numbraille[nums.index(n)]

        print(s)
        return

    if dec:
        for n in dec:
            if n in alphabraille:
                s += alphabet[alphabraille.index(n)]
        print(s)
        return

if __name__ == "__main__":
    main()
