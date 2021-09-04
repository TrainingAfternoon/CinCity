//#define MASK_SIZE uint64_t
//
//TODO: consider if first is implementing a painter's algorithm and how to fix that

namespace Bits {
    class Bitmask {
        public:
            Bitmask(uint64_t bitmask) {
                mask = bitmask;
            }

            //Get the ith bit of the mask
            int bit(int i) {
                return (mask >> i) & 1;
            }

            //Get the number of set bits in the mask
            int count() {
                int bits = 0;
                int ashl = 0;
                while(ashl < sizeof(uint64_t) * 8) bits += (mask >> ashl++)&1;
                return bits;
            }

            //Get the first nonzero bit in the mask
            int first() {
                int pos = 0;
                while(!((mask >> pos) & 1)) pos++;
                return pos;
            }
            
            //Set the ith bits
            void set(int i) {
                mask |= (1 << i);
            }

            //Check if the ith bit is set
            //Funnily enough due to how c works, this is the same as bit(i)
            bool check(int i) {
                return (mask >> i) & 1;
            }
        private:
            uint64_t mask;
    }
}
