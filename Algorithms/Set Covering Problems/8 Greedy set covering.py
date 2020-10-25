# greedy set covering

#========================== INPUT PROGRAM ==========================
### data contoh slide
### Fasilitas j
##Fas = ["Bandung", "Semarang", "Solo"]
##
### Area permintaan i
##Dem = ["DKI Jakarta", "Jawa Barat", "Jawa Tengah", "Yogyakarta", "Jawa Timur"]
##
### Biaya pendirian fasilitas j
##c = [100, 150, 75]
##
### matriks pelayanan fasilitas j terhadap area i
##a = [[1,0,0],
##     [1,1,0],
##     [1,1,1],
##     [0,1,1],
##     [0,1,1]]

# data lain
# Fasilitas j
Fas = ["S1", "S2", "S3", "S4", "S5"]

# Area permintaan i
Dem = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']

# Biaya pendirian fasilitas j
c = [180, 70, 50, 220, 100]

# matriks pelayanan fasilitas j terhadap area i
a = [[1,1,0,0,0],
     [1,0,0,0,0],
     [0,1,1,0,0],
     [0,0,1,0,0],
     [0,1,0,1,0],
     [0,0,0,1,1],
     [0,0,1,1,0],
     [0,1,0,0,1],
     [1,0,0,0,1],
     [1,0,0,0,1]]

m = len(Dem) # jumlah area
n = len(Fas) # jumlah fasilitas

#========================== PROGRAM MULAI ==========================

# Inisiasi
F = range(n) # himpunan fasilitas yg belum dipilih
U = range(m) # himpunan area yg belum terlayani
S = [] # fasilitas yang sudah dipilih

print "Inisiasi"
print "Fasilitas yang belum dipilih", [Fas[j] for j in F]
print "Area yang belum terlayani", [Dem[i] for i in U]
print "Fasilitas terpilih", [Fas[j] for j in S]

k = 0 # jumlah iterasi
while U and F:
    
    k += 1
    R = dict() # data rasio
    for j in F:
        # hitung jumlah area pelayanan fasilitas j
        Uj = len([i for i in U if a[i][j] == 1])
    
        # hitung rasio
        if Uj != 0:
            ras = float(c[j])/Uj
            R[j] = round(ras,2)
            print "Rasio fasilitas {}: {}".format(Fas[j], R[j])
        else:
            print "Fasilits {} tidak memiliki area pelayanan".format(Fas[j])
        
    # Cari fasilitas dengan rasio terkecil
    j_min = min(R, key = R.get)
    S.append(j_min)
    F.remove(j_min)
    print "Fasilitas {} terpilih".format(Fas[j_min])
    
    # Update U
    temp = U[:]
    for i in temp:
        if a[i][j_min] == 1:
            U.remove(i)
            
    print "\nIterasi", k
    print "Fasilitas yang belum dipilih", [Fas[j] for j in F]
    print "Area yang belum terlayani", [Dem[i] for i in U]
    print "Fasilitas terpilih", [Fas[j] for j in S]
        
print "\nSeluruh area sudah terlayani"
Sname = [Fas[j] for j in S]
print "Fasilitas terpilih adalah", ", ".join(Sname)
TotBiaya = sum([c[j] for j in S])
print "Total biaya pendirian fasilitas adalah", TotBiaya
