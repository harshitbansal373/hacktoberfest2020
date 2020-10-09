def count_word(str):
    words = str.split()
    dict = {}
    for i in words:
        dict[i] = words.count(i)
    return dict


def max_occurance_word(str):
    dict = count_word(str)
    key = list(dict.keys())
    val = list(dict.values())
    ans = key[val.index(max(val))]
    return ans


if __name__ == '__main__':
    input_string = input()
    dict = count_word(input_string)
    st = max_occurance_word(input_string)
    print(st)