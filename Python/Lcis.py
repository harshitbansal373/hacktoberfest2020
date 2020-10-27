def Lcis(seq1,seq2):
    n=len(seq1)
    m=len(seq2)
    dp=[[0 for i in range(m)] for j in range(n)]
    for i in range(n):
        theta=0
        for j in range(m):
            if(i==0 or j==0):
                dp[i][j]=0
            else:
                dp[i][j]=dp[i-1][j]
            if seq1[i]>seq2[j]:
                theta=max(theta,dp[i][j])
            elif seq1[i]==seq2[j]:
                dp[i][j]=theta+1
    maxlen=max(dp[n-1])
    j=m-1;
    LCIS=[]
    if dp[n-1][0]>0:
        LCIS.append(dp[n-1][0])
    for i in range(1,m):
        if dp[n-1][i]<dp[n-1][i-1]:
            dp[n-1][i]=dp[n-1][i-1]
    for i in range(1,m):
        if dp[n-1][i]>dp[n-1][i-1]:
            LCIS.append(seq2[i])
    print("LCIS is: ",LCIS)
    return max(dp[n-1])
seq1=[]
seq2=[]
n=int(input("Enter size of seq1"))
print("Enter sequence1")
for i in range(n):
    seq1.append(int(input()))
m=int(input("Enter size of seq2"))
for i in range(m):
    seq2.append(int(input()))
lenLcis=Lcis(seq1,seq2)
print("length of LCIS is: ",lenLcis)
