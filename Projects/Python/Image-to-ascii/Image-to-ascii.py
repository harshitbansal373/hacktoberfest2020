import PIL.Image as Image
# image_path = '/home/lemark/Downloads/WhatsApp Image 2020-07-02 at 6.00.37 PM.jpeg'
image_path = 'Full path to your Image file'
ASCII_CHARS = ["@", "#", "S", "X", "*", "+", "^", ";", ":", ",", "."]
new_width = 100


def resize(image):
    '''
    Resizes the PIL.Image object to a new height and width
    to change your output change new_width variable defined
    above

    Return a PIL.Image object
    '''

    width, height = image.size
    aspect_ratio = height/width
    new_height = int(aspect_ratio*new_width)
    return image.resize((new_width, new_height))


def Grey(image):
    '''
    Returns a Monocromatic greyscale PIL.Image
    '''
    return image.convert(mode="L")


def image_to_ascii(image):
    '''
    takes a monochannel PIL.Image object, gets the pixel val
    (which is always < 255) and gets the questiont val of 25
    (b/w 0 and 10), if you want to change the Ascii characters
    in your image file change ASCII_CHARS list 'high intensity'
    characters first and 11 string constituents.
    '''
    data = image.getdata()
    return ''.join(ASCII_CHARS[val//25] for val in data)


def main():
    '''
    Writes the output generated in "Ascii-Image.txt" in the
    current directory file if you wish to save your previous
    txt file rename it or move it out of that directory as it
    will overwrites it.
    '''
    try:
        image = Image.open(image_path)
    except Exception:
        print('Not a valid image path')
        return

    new_img = Grey(resize(image))
    text = image_to_ascii(new_img)
    pix_count = len(text)

    final_ascii = '\n'.join(text[i:i+new_width]
                            for i in range(0, pix_count, new_width))

    with open('Ascii-Image.txt', 'w') as f:
        f.write(final_ascii)


if __name__ == "__main__":
    main()
