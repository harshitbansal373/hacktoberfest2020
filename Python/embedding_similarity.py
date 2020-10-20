# three ways of doing the same operation (calculate embedding similarity using cosine between vectors)


def cosine(emb1, emb2):
    from numpy import dot
    from numpy.linalg import norm

    return dot(emb1, emb2) / (norm(emb1) * norm(emb2))


def cosine2(emb1, emb2):
    from scipy import spatial

    return 1 - spatial.distance.cosine(emb1, emb2)


def cosine3(emb1, emb2):
    dot = 0
    norm1 = 0
    norm2 = 0
    for i in range(len(emb1)):
        dot += emb1[i] * emb2[i]
        norm1 += emb1[i] ** 2
        norm2 += emb2[i] ** 2
    norm1 = norm1 ** (1 / 2)
    norm2 = norm2 ** (1 / 2)
    return dot / (norm1 * norm2)


a = [3, 45, 7, 2]
b = [2, 54, 13, 15]
print(cosine(a, b), cosine(a, b), cosine3(a, b))

