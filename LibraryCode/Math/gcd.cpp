int gcd(int p, int q){
    if(p==0) return q;
    if(q==0) return p;
    if(((p&1)==0) && ((q&1)==0)) return ((gcd(p >> 1, q >> 1)) << 1);
    if((p&1)==0) return gcd(p>>1, q);
    if((q&1)==0) return gcd(p, q>>1);
    if (p>q) return gcd((p-q)>>1, q);
    return gcd(p, (q-p)>>1);
}

