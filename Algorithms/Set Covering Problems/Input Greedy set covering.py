# Input untuk soal Greedy set covering problem

# Input jumlah fasilitas
while True:
    n = raw_input("Berapa jumlah lokasi fasilitas? ")
    try:
        n = int(n)
        break
    except ValueError:
        print "Masukkan angka"

# Input nama fasilitas
Fas = []
c = []
for j in range(n):
    nama = raw_input("Nama fasilitas {}? ".format(j+1))
    Fas.append(nama)

# Input biaya pendirian fasilitas
c = []
for j in range(n):
    while True:
        biaya = raw_input("Biaya pendirian fasilitas {}? ".format(Fas[j]))
        try:
            biaya = int(biaya)
            c.append(biaya)
            break
        except ValueError:
            print "Masukkan angka"        

# Input jumlah area permintaan
while True:
    m = raw_input("Berapa jumlah area permintaan? ")
    try:
        m = int(m)
        break
    except ValueError:
        print "Masukkan angka"

# Input nama area permintaan
Dem = []
for i in range(m):
    nama = raw_input("Nama area permintaan {}? ".format(i+1))
    Dem.append(nama)

# Input matriks cakupan pelayanan fasilitas terhadap area permintaan
a = []
for i in range(m):
    baris = []
    for j in range(n):
        pesan = "Apakah area {} terlayani oleh fasilitas {}? (y/t) ".format(Dem[i],Fas[j])
        cov = raw_input(pesan)
        if cov.lower() == 'y':
            baris.append(1)
        else:
            baris.append(0)
    a.append(baris)

print "Fasilitas", Fas
print "Wilayah permintaan", Dem
print "Biaya pendirian fasilitas", c
print "Matriks pelayanan fasilitas", a
