// Lucas Theorem based function that returns nCr % p 
// This function works like decimal to binary conversion 
// recursive function.  First we compute last digits of 
// n and r in base p, then recur for remaining digits 
int nCrModpLucas(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
   // Compute last digits of n and r in base p 
   int ni = n%p, ri = r%p; 
  
   // Compute result for last digits computed above, and 
   // for remaining digits.  Multiply the two results and 
   // compute the result of multiplication in modulo p. 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 
