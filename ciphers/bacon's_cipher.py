"""
Program to encode and decode Baconian or Bacon's Cipher
Wikipedia reference : https://en.wikipedia.org/wiki/Bacon%27s_cipher
"""

encode_dict = {
    "a": "AAAAA",
    "b": "AAAAB",
    "c": "AAABA",
    "d": "AAABB",
    "e": "AABAA",
    "f": "AABAB",
    "g": "AABBA",
    "h": "AABBB",
    "i": "ABAAA",
    "j": "BBBAA",
    "k": "ABAAB",
    "l": "ABABA",
    "m": "ABABB",
    "n": "ABBAA",
    "o": "ABBAB",
    "p": "ABBBA",
    "q": "ABBBB",
    "r": "BAAAA",
    "s": "BAAAB",
    "t": "BAABA",
    "u": "BAABB",
    "v": "BBBAB",
    "w": "BABAA",
    "x": "BABAB",
    "y": "BABBA",
    "z": "BABBB",
    " ": " ",
}

decode_dict = {}
for alphabet in encode_dict:
    decode_dict[encode_dict[alphabet]] = alphabet


def encode(word: str) -> str:
    """
    Encodes to Baconian cipher
    >>> encode("hello")
    'AABBBAABAAABABAABABAABBAB'
    >>> encode("hello world")
    'AABBBAABAAABABAABABAABBAB BABAAABBABBAAAAABABAAAABB'
    >>> encode("hello world!")
    Traceback (most recent call last):
        ...
    Exception: encode() accepts only alphabets
    """
    encoded = ""
    for letter in word.lower():
        if letter.isalpha() or letter == " ":
            encoded += encode_dict[letter]
        else:
            raise Exception("encode() accepts only alphabets")
    return encoded


def decode(coded: str) -> str:
    """
    Decodes from Baconian cipher
    >>> decode("AABBBAABAAABABAABABAABBAB BABAAABBABBAAAAABABAAAABB")
    'hello world'
    >>> decode("AABBBAABAAABABAABABAABBAB")
    'hello'
    >>> encode("AABBBAABAAABABAABABAABBAB BABAAABBABBAAAAABABAAAABB!")
    Traceback (most recent call last):
        ...
    Exception: encode() accepts only alphabets
    """
    if set(coded) - {"A", "B", " "} != set() and set(coded) - {"A", "B"} != set():
        raise Exception("decode accepts only 'A', 'B' and ' '")
    words = coded.split()
    decoded = ""
    for word in words:
        while len(word) != 0:
            decoded += decode_dict[word[:5]]
            word = word[5:]
        decoded += " "
    decoded = decoded.strip(" ")
    return decoded


if "__name__" == "__main__":
    from doctest import testmod

    testmod()
