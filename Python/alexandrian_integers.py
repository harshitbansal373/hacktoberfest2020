import itertools
import sys

#  The numbers are of the form p(p+d)(p+(p^2+1)/d), where d runs over divisors 
#  of p^2+1 and p runs over all positive integers.
class Problem():
    def __init__(self):
        self.bound = 100000
        self.primes = []
        self._sieve()
        
    def _sieve(self):
        visited = [False] * (self.bound + 1)
        visited[0] = visited[1] = True
        for i in range(2, self.bound + 1):
            if not visited[i]:
                self.primes.append(i)
            for j in range(i + i, self.bound + 1, i):
                visited[j] = True
        print('Prime count:', len(self.primes))
    
    def solve(self):
        alexandrian_integers = set()
        for p in range(1, self.bound + 1):
            if p % 100 == 0:
                print('Current', p)
            divisors = self._get_all_divisors(p**2 + 1)
            for d in divisors:
                if d > p:
                    break
                alexandrian_integers.add(p*(p+d)*(p+(p**2+1)//d))
        alexandrian_integers = list(alexandrian_integers)
        alexandrian_integers.sort()
        print(alexandrian_integers[150000-1])
    
    def _get_all_divisors(self, n):
        rv = []
        factors = self._factorize(n)
        for x in itertools.product(*map(lambda c: [c ** i for i in range(factors[c] + 1)], factors)):
            z = 1
            for y in x:
                z *= y
            rv.append(z)
        rv.sort()
        return rv
        
    def _factorize(self, n):
        d = n
        rv = {}
        for i in range(len(self.primes)):
            p = self.primes[i]
            if d == 1 or p > d:
                break
            count = 0
            while d % p == 0:
                d = d//p
                count += 1
            if count > 0:
                rv[p] = count
        if d > 1:
            rv[d] = 1
        return rv    
                    
def main():
    problem = Problem()
    problem.solve()
    
if __name__ == '__main__':
    sys.exit(main())
